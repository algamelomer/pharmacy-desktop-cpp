#pragma once
#include "product.h"
#include "EditProductForm.h"

namespace ProductApp {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Collections::Generic;
    using namespace System::Drawing;
    using namespace System::Data::SQLite;

    public ref class ProductForm : public Form
    {
    private:
        Label^ lblSearch;
        TextBox^ searchBox;
        Label^ placeholderLabel;
        Button^ btnAdd;
        DataGridView^ dataGrid;
        Label^ titleLabel;
        Label^ separator;

        // Original color for hover effect
        Color originalBtnAddBackColor;

    public:
        ProductForm()
        {
            InitializeComponent();
        }

    private:
        void InitializeComponent()
        {
            this->Text = "Product Manager";
            this->Width = 800;
            this->Height = 900;
            this->BackColor = Color::FromArgb(46, 46, 46);

            // Title Label
            titleLabel = gcnew Label();
            titleLabel->Text = "Product Manager";
            titleLabel->Font = gcnew System::Drawing::Font("Segoe UI", 16, FontStyle::Bold);
            titleLabel->ForeColor = Color::White;
            titleLabel->AutoSize = true;
            titleLabel->Location = Point(20, 10);
            this->Controls->Add(titleLabel);

            // Search Label
            lblSearch = gcnew Label();
            lblSearch->Text = "Search Products: ";
            lblSearch->Font = gcnew System::Drawing::Font("Segoe UI", 10);
            lblSearch->ForeColor = Color::White;
            lblSearch->Location = Point(20, 50);
            lblSearch->Width = 100;
            lblSearch->Height = 20;
            this->Controls->Add(lblSearch);

            // Search Box
            searchBox = gcnew TextBox();
            searchBox->Location = Point(20, 70);
            searchBox->Width = 300;
            searchBox->Font = gcnew System::Drawing::Font("Segoe UI", 10);
            searchBox->BackColor = Color::FromArgb(60, 60, 60);
            searchBox->ForeColor = Color::White;
            searchBox->TextChanged += gcnew EventHandler(this, &ProductForm::OnSearchTextChanged);
            searchBox->GotFocus += gcnew EventHandler(this, &ProductForm::OnSearchBoxFocus);
            searchBox->LostFocus += gcnew EventHandler(this, &ProductForm::OnSearchBoxBlur);
            this->Controls->Add(searchBox);

            // Placeholder Label
            placeholderLabel = gcnew Label();
            placeholderLabel->Text = "Type product name...";
            placeholderLabel->Font = gcnew System::Drawing::Font("Segoe UI", 10);
            placeholderLabel->ForeColor = Color::Gray;
            placeholderLabel->Location = searchBox->Location;
            placeholderLabel->Width = searchBox->Width;
            placeholderLabel->Height = searchBox->Height;
            placeholderLabel->Click += gcnew EventHandler(this, &ProductForm::OnPlaceholderClick);
            this->Controls->Add(placeholderLabel);

            // Add Button
            btnAdd = gcnew Button();
            btnAdd->Text = "Add";
            btnAdd->Font = gcnew System::Drawing::Font("Segoe UI", 10, FontStyle::Bold);
            btnAdd->Top = 70;
            btnAdd->Left = searchBox->Width + 40;
            btnAdd->BackColor = Color::FromArgb(0, 120, 215);
            btnAdd->ForeColor = Color::White;
            btnAdd->FlatStyle = FlatStyle::Flat;
            btnAdd->FlatAppearance->BorderSize = 0;
            originalBtnAddBackColor = btnAdd->BackColor;
            btnAdd->Click += gcnew EventHandler(this, &ProductForm::BtnAdd_Click);
            btnAdd->MouseEnter += gcnew EventHandler(this, &ProductForm::BtnAdd_MouseEnter);
            btnAdd->MouseLeave += gcnew EventHandler(this, &ProductForm::BtnAdd_MouseLeave);
            this->Controls->Add(btnAdd);

            // Separator
            separator = gcnew Label();
            separator->BackColor = Color::FromArgb(0, 120, 215);
            separator->Height = 2;
            separator->Width = this->ClientSize.Width - 40;
            separator->Location = Point(20, btnAdd->Top + btnAdd->Height + 10);
            this->Controls->Add(separator);

            // DataGrid
            dataGrid = gcnew DataGridView();
            dataGrid->Top = separator->Top + separator->Height + 10;
            dataGrid->Left = 20;
            dataGrid->Width = this->ClientSize.Width - 40;
            dataGrid->Height = this->ClientSize.Height - dataGrid->Top - 10;
            dataGrid->BackgroundColor = Color::FromArgb(46, 46, 46);
            dataGrid->DefaultCellStyle->BackColor = Color::FromArgb(60, 60, 60);
            dataGrid->DefaultCellStyle->ForeColor = Color::White;
            dataGrid->AlternatingRowsDefaultCellStyle->BackColor = Color::FromArgb(50, 50, 50);
            dataGrid->ColumnHeadersDefaultCellStyle->BackColor = Color::FromArgb(0, 120, 215);
            dataGrid->ColumnHeadersDefaultCellStyle->ForeColor = Color::White;
            dataGrid->EnableHeadersVisualStyles = false;
            dataGrid->DefaultCellStyle->SelectionBackColor = Color::FromArgb(0, 100, 180);
            dataGrid->DefaultCellStyle->SelectionForeColor = Color::White;
            dataGrid->RowHeadersVisible = false;
            dataGrid->CellBorderStyle = DataGridViewCellBorderStyle::SingleHorizontal;
            dataGrid->GridColor = Color::FromArgb(80, 80, 80);
            dataGrid->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::EnableResizing;
            dataGrid->ColumnHeadersHeight = 40;
            dataGrid->ColumnHeadersDefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
            dataGrid->RowTemplate->Height = 30;
            dataGrid->Font = gcnew System::Drawing::Font("Segoe UI", 9);
            dataGrid->ReadOnly = true;
            dataGrid->AllowUserToAddRows = false;
            dataGrid->AllowUserToDeleteRows = false;
            dataGrid->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
            dataGrid->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
            dataGrid->CellClick += gcnew DataGridViewCellEventHandler(this, &ProductForm::DataGrid_CellClick);
            this->Controls->Add(dataGrid);

            // Tab indices
            searchBox->TabIndex = 0;
            btnAdd->TabIndex = 1;
            dataGrid->TabIndex = 2;

            // Resize event
            this->Resize += gcnew EventHandler(this, &ProductForm::OnResize);

            LoadProducts("");
        }

        void OnResize(Object^ sender, EventArgs^ e)
        {
            separator->Width = this->ClientSize.Width - 40;
            dataGrid->Width = this->ClientSize.Width - 40;
            dataGrid->Height = this->ClientSize.Height - dataGrid->Top - 10;
        }

        void LoadProducts(String^ keyword)
        {
            List<Product^>^ products = RetrySearchProductsByName(keyword);
            dataGrid->Rows->Clear();
            dataGrid->Columns->Clear();

            // Define columns
            dataGrid->Columns->Add("Id", "ID");
            dataGrid->Columns->Add("Name", "Name");
            dataGrid->Columns->Add("CategoryId", "Category ID");
            dataGrid->Columns->Add("InventoryId", "Inventory ID");
            dataGrid->Columns->Add("Price", "Price");
            dataGrid->Columns->Add("Count", "Count");
            dataGrid->Columns->Add("Barcode", "Barcode");
            dataGrid->Columns->Add("update", "Update");
            dataGrid->Columns->Add("delete", "Delete");

            // Set column alignments
            dataGrid->Columns["Id"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
            dataGrid->Columns["CategoryId"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
            dataGrid->Columns["InventoryId"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
            dataGrid->Columns["Price"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleRight;
            dataGrid->Columns["Count"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
            dataGrid->Columns["Barcode"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleLeft;

            // Set button column widths
            dataGrid->Columns["update"]->Width = 80;
            dataGrid->Columns["delete"]->Width = 80;

            // Populate rows
            for each (Product ^ p in products)
            {
                dataGrid->Rows->Add(p->Id, p->Name, p->CategoryId, p->InventoryId, p->Price, p->Count, p->Barcode);
                DataGridViewButtonCell^ BtnUpdate_Click = gcnew DataGridViewButtonCell();
                BtnUpdate_Click->Value = "Update";
                BtnUpdate_Click->Style->BackColor = Color::FromArgb(0, 120, 215);
                BtnUpdate_Click->Style->ForeColor = Color::White;
                dataGrid->Rows[dataGrid->Rows->Count - 1]->Cells["update"] = BtnUpdate_Click;

                DataGridViewButtonCell^ BtnDelete_Click = gcnew DataGridViewButtonCell();
                BtnDelete_Click->Value = "Delete";
                BtnDelete_Click->Style->BackColor = Color::FromArgb(255, 80, 80);
                BtnDelete_Click->Style->ForeColor = Color::White;
                dataGrid->Rows[dataGrid->Rows->Count - 1]->Cells["delete"] = BtnDelete_Click;
            }
        }

        void OnSearchTextChanged(Object^ sender, EventArgs^ e)
        {
            String^ keyword = searchBox->Text->Trim();
            LoadProducts(keyword);
            placeholderLabel->Visible = String::IsNullOrEmpty(searchBox->Text);
        }

        void OnSearchBoxFocus(Object^ sender, EventArgs^ e)
        {
            placeholderLabel->Visible = false;
        }

        void OnSearchBoxBlur(Object^ sender, EventArgs^ e)
        {
            placeholderLabel->Visible = String::IsNullOrEmpty(searchBox->Text);
        }

        void OnPlaceholderClick(Object^ sender, EventArgs^ e)
        {
            searchBox->Focus();
        }

        void BtnAdd_Click(Object^ sender, EventArgs^ e)
        {
            try
            {
                EditProductForm^ editForm = gcnew EditProductForm();
                if (editForm->ShowDialog(this) == System::Windows::Forms::DialogResult::OK)
                {
                    if (RetryAddProduct(editForm->UpdatedProduct))
                    {
                        MessageBox::Show("Product added");
                        LoadProducts("");
                    }
                    else
                    {
                        MessageBox::Show("Failed to add product.");
                    }
                }
            }
            catch (FormatException^)
            {
                MessageBox::Show("Please enter valid numeric values for Category ID, Inventory ID, Price, and Count.");
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error adding product: " + ex->Message);
            }
        }

        void BtnAdd_MouseEnter(Object^ sender, EventArgs^ e)
        {
            btnAdd->BackColor = Color::FromArgb(0, 100, 180);
        }

        void BtnAdd_MouseLeave(Object^ sender, EventArgs^ e)
        {
            btnAdd->BackColor = originalBtnAddBackColor;
        }

        void DataGrid_CellClick(Object^ sender, DataGridViewCellEventArgs^ e)
        {
            if (e->RowIndex >= 0)
            {
                try
                {
                    if (e->ColumnIndex == dataGrid->Columns["delete"]->Index)
                    {
                        int productId = Convert::ToInt32(dataGrid->Rows[e->RowIndex]->Cells[0]->Value);
                        System::Windows::Forms::DialogResult result = MessageBox::Show(
                            "Are you sure you want to delete product ID: " + productId.ToString() + "?",
                            "Confirm Delete",
                            MessageBoxButtons::YesNo,
                            MessageBoxIcon::Warning);
                        if (result == System::Windows::Forms::DialogResult::Yes)
                        {
                            if (RetryDeleteProduct(productId))
                            {
                                MessageBox::Show("Product deleted");
                                LoadProducts("");
                            }
                            else
                            {
                                MessageBox::Show("Failed to delete product.");
                            }
                        }
                    }
                    else if (e->ColumnIndex == dataGrid->Columns["update"]->Index)
                    {
                        int productId = Convert::ToInt32(dataGrid->Rows[e->RowIndex]->Cells[0]->Value);
                        Product^ selected = RetryGetProductById(productId);
                        if (selected != nullptr)
                        {
                            EditProductForm^ editForm = gcnew EditProductForm(selected);
                            if (editForm->ShowDialog(this) == System::Windows::Forms::DialogResult::OK)
                            {
                                if (RetryUpdateProduct(editForm->UpdatedProduct))
                                {
                                    MessageBox::Show("Product updated");
                                    LoadProducts("");
                                }
                                else
                                {
                                    MessageBox::Show("Failed to update product.");
                                }
                            }
                        }
                        else
                        {
                            MessageBox::Show("Failed to retrieve product for update.");
                        }
                    }
                }
                catch (FormatException^)
                {
                    MessageBox::Show("Please enter valid numeric values for Category ID, Inventory ID, Price, and Count.");
                }
                catch (Exception^ ex)
                {
                    MessageBox::Show("Error: " + ex->Message);
                }
            }
        }

        // Retry helper functions for database operations
        List<Product^>^ RetrySearchProductsByName(String^ name)
        {
            int maxRetries = 3;
            int retryDelayMs = 100;

            for (int attempt = 0; attempt < maxRetries; attempt++)
            {
                try
                {
                    return ProductDBHelper::SearchProductsByName(name);
                }
                catch (SQLiteException^ ex)
                {
                    if (ex->Message->Contains("database is locked") && attempt < maxRetries - 1)
                    {
                        System::Threading::Thread::Sleep(retryDelayMs);
                        continue;
                    }
                    MessageBox::Show("Search Error: " + ex->Message);
                    throw;
                }
            }
            return gcnew List<Product^>();
        }

        bool RetryAddProduct(Product^ product)
        {
            int maxRetries = 3;
            int retryDelayMs = 100;

            for (int attempt = 0; attempt < maxRetries; attempt++)
            {
                try
                {
                    return ProductDBHelper::AddProduct(product);
                }
                catch (SQLiteException^ ex)
                {
                    if (ex->Message->Contains("database is locked") && attempt < maxRetries - 1)
                    {
                        System::Threading::Thread::Sleep(retryDelayMs);
                        continue;
                    }
                    MessageBox::Show("Add Error: " + ex->Message);
                    throw;
                }
            }
            return false;
        }

        Product^ RetryGetProductById(int id)
        {
            int maxRetries = 3;
            int retryDelayMs = 100;

            for (int attempt = 0; attempt < maxRetries; attempt++)
            {
                try
                {
                    return ProductDBHelper::GetProductById(id);
                }
                catch (SQLiteException^ ex)
                {
                    if (ex->Message->Contains("database is locked") && attempt < maxRetries - 1)
                    {
                        System::Threading::Thread::Sleep(retryDelayMs);
                        continue;
                    }
                    MessageBox::Show("Get Product Error: " + ex->Message);
                    throw;
                }
            }
            return nullptr;
        }

        bool RetryUpdateProduct(Product^ product)
        {
            int maxRetries = 3;
            int retryDelayMs = 100;

            for (int attempt = 0; attempt < maxRetries; attempt++)
            {
                try
                {
                    return ProductDBHelper::UpdateProduct(product);
                }
                catch (SQLiteException^ ex)
                {
                    if (ex->Message->Contains("database is locked") && attempt < maxRetries - 1)
                    {
                        System::Threading::Thread::Sleep(retryDelayMs);
                        continue;
                    }
                    MessageBox::Show("Update Error: " + ex->Message);
                    throw;
                }
            }
            return false;
        }

        bool RetryDeleteProduct(int id)
        {
            int maxRetries = 3;
            int retryDelayMs = 100;

            for (int attempt = 0; attempt < maxRetries; attempt++)
            {
                try
                {
                    return ProductDBHelper::DeleteProduct(id);
                }
                catch (SQLiteException^ ex)
                {
                    if (ex->Message->Contains("database is locked") && attempt < maxRetries - 1)
                    {
                        System::Threading::Thread::Sleep(retryDelayMs);
                        continue;
                    }
                    MessageBox::Show("Delete Error: " + ex->Message);
                    throw;
                }
            }
            return false;
        }
    };
}