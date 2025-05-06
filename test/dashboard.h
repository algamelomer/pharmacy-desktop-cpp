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

        TextBox^ txtName;
        TextBox^ txtCategoryId;
        TextBox^ txtInventoryId;
        TextBox^ txtPrice;
        TextBox^ txtCount;
        TextBox^ txtBarcode;

        Button^ btnAdd;
        Button^ btnUpdate;
        Button^ btnDelete;

        DataGridView^ dataGrid;


        TextBox^ searchBox;
        Label^ placeholderLabel;

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

            int labelWidth = 100;
            int textBoxWidth = 200;
            int leftMargin = 20;
            int topMargin = 20;
            int verticalSpacing = 30;
          
            // Search Box
            searchBox = gcnew TextBox();
            searchBox->Location = Point(20, 40);
            searchBox->Width = 300;
            searchBox->TextChanged += gcnew EventHandler(this, &ProductForm::OnSearchTextChanged);
            searchBox->GotFocus += gcnew EventHandler(this, &ProductForm::OnSearchBoxFocus);
            searchBox->LostFocus += gcnew EventHandler(this, &ProductForm::OnSearchBoxBlur);
            this->Controls->Add(searchBox);

            // Placeholder Label
            placeholderLabel = gcnew Label();
            placeholderLabel->Text = "Type product name...";
            placeholderLabel->ForeColor = SystemColors::GrayText;
            placeholderLabel->Location = searchBox->Location;
            placeholderLabel->Width = searchBox->Width;
            placeholderLabel->Height = searchBox->Height;
            placeholderLabel->Click += gcnew EventHandler(this, &ProductForm::OnPlaceholderClick);
            this->Controls->Add(placeholderLabel);


            // Search Box label
            lblSearch = gcnew Label();
            lblSearch->Text = "Search Products: ";
            lblSearch->Location = Point(searchBox->Left, searchBox->Top - 20);
            lblSearch->Width = 100;
            lblSearch->Height = 20;
            this->Controls->Add(lblSearch);

            // add btn
            btnAdd = gcnew Button();
            btnAdd->Text = "Add";
            btnAdd->Top = 40;
            btnAdd->Left = searchBox->Width + (leftMargin*2);
            btnAdd->Click += gcnew EventHandler(this, &ProductForm::BtnAdd_Click);
            this->Controls->Add(btnAdd);

            // DataGrid
            dataGrid = gcnew DataGridView();
            dataGrid->Top = btnAdd->Top + 50;
            dataGrid->Left = leftMargin;
            dataGrid->Width = this->ClientSize.Width;
            dataGrid->Height = this->ClientSize.Height;

            dataGrid->ReadOnly = true;
            dataGrid->AllowUserToAddRows = false;
            dataGrid->AllowUserToDeleteRows = false;
            dataGrid->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
            dataGrid->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
            dataGrid->CellClick += gcnew DataGridViewCellEventHandler(this, &ProductForm::DataGrid_CellClick);
            dataGrid->Visible = true;
            dataGrid->Enabled = true;
            dataGrid->BackgroundColor = System::Drawing::Color::LightGray;
            this->Controls->Add(dataGrid);

            LoadProducts("");
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
            dataGrid->Columns->Add("update", "update");
            dataGrid->Columns->Add("delete", "delete");

            // Populate rows
            for each(Product ^ p in products)
            {
                dataGrid->Rows->Add(p->Id, p->Name, p->CategoryId, p->InventoryId, p->Price, p->Count, p->Barcode);
                DataGridViewButtonCell^ BtnUpdate_Click = gcnew DataGridViewButtonCell();
                BtnUpdate_Click->Value = "Update";
                dataGrid->Rows[dataGrid->Rows->Count - 1]->Cells["update"] = BtnUpdate_Click;

                DataGridViewButtonCell^ BtnDelete_Click = gcnew DataGridViewButtonCell();
                BtnDelete_Click->Value = "Delete";
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

        void BtnUpdate_Click(Object^ sender, EventArgs^ e)
        {
            if (dataGrid->SelectedRows->Count == 0)
            {
                MessageBox::Show("Please select a product to update.");
                return;
            }

            try
            {
                int selectedRowIndex = dataGrid->SelectedRows[0]->Index;
                int productId = Convert::ToInt32(dataGrid->Rows[selectedRowIndex]->Cells[0]->Value);

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
            catch (FormatException^)
            {
                MessageBox::Show("Please enter valid numeric values for Category ID, Inventory ID, Price, and Count.");
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error updating product: " + ex->Message);
            }
        }

        void BtnDelete_Click(Object^ sender, EventArgs^ e)
        {
            if (dataGrid->SelectedRows->Count == 0)
            {
                MessageBox::Show("Please select a product to delete.");
                return;
            }

            try
            {
                int selectedRowIndex = dataGrid->SelectedRows[0]->Index;
                int productId = Convert::ToInt32(dataGrid->Rows[selectedRowIndex]->Cells[0]->Value);
                MessageBox::Show("Product ID: " + productId.ToString());
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
            catch (Exception^ ex)
            {
                MessageBox::Show("Error deleting product: " + ex->Message);
            }
        }

        void DataGrid_CellClick(Object^ sender, DataGridViewCellEventArgs^ e)
        {
            if (e->RowIndex >= 0) // Ensure a valid row is clicked
            {
                try
                {
                    // Check if the clicked cell is in the "delete" column
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
                    // Check if the clicked cell is in the "update" column
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
            return gcnew List<Product^>(); // Return empty list if all retries fail
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
            return false; // Return false if all retries fail
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
            return nullptr; // Return nullptr if all retries fail
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
            return false; // Return false if all retries fail
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
            return false; // Return false if all retries fail
        }
    };
}