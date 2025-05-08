#pragma once
#include "product.h"
#include "category.h"
#include "inventory.h"

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

            searchBox->TabIndex = 0;
            btnAdd->TabIndex = 1;
            dataGrid->TabIndex = 2;

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

            // Add columns to the data grid
            dataGrid->Columns->Add("Id", "ID");
            dataGrid->Columns->Add("Name", "Name");
            dataGrid->Columns->Add("CategoryName", "Category Name");
            dataGrid->Columns->Add("InventoryName", "Inventory Name");
            dataGrid->Columns->Add("Price", "Price");
            dataGrid->Columns->Add("Count", "Count");
            dataGrid->Columns->Add("Barcode", "Barcode");
            dataGrid->Columns->Add("update", "Update");
            dataGrid->Columns->Add("delete", "Delete");

            // Format the columns
            dataGrid->Columns["Id"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
            dataGrid->Columns["CategoryName"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
            dataGrid->Columns["InventoryName"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
            dataGrid->Columns["Price"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleRight;
            dataGrid->Columns["Count"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
            dataGrid->Columns["Barcode"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleLeft;

            dataGrid->Columns["update"]->Width = 80;
            dataGrid->Columns["delete"]->Width = 80;

            for each (Product ^ p in products)
            {
                // Fetch Category and Inventory names based on IDs
                String^ categoryName = GetCategoryNameById(p->CategoryId);
                String^ inventoryName = GetInventoryNameById(p->InventoryId);

                // Add the product data to the grid
                dataGrid->Rows->Add(p->Id, p->Name, categoryName, inventoryName, p->Price, p->Count, p->Barcode);

                // Add Update button
                DataGridViewButtonCell^ BtnUpdate_Click = gcnew DataGridViewButtonCell();
                BtnUpdate_Click->Value = "Update";
                BtnUpdate_Click->Style->BackColor = Color::FromArgb(0, 120, 215);
                BtnUpdate_Click->Style->ForeColor = Color::White;
                dataGrid->Rows[dataGrid->Rows->Count - 1]->Cells["update"] = BtnUpdate_Click;

                // Add Delete button
                DataGridViewButtonCell^ BtnDelete_Click = gcnew DataGridViewButtonCell();
                BtnDelete_Click->Value = "Delete";
                BtnDelete_Click->Style->BackColor = Color::FromArgb(255, 80, 80);
                BtnDelete_Click->Style->ForeColor = Color::White;
                dataGrid->Rows[dataGrid->Rows->Count - 1]->Cells["delete"] = BtnDelete_Click;
            }
        }

        String^ GetCategoryNameById(int categoryId)
        {

            Category^ category = CategoryDBHelper::GetCategoryById(categoryId);
            return category != nullptr ? category->Name : "Unknown";
        }

        String^ GetInventoryNameById(int inventoryId)
        {

            Inventory^ inventory = InventoryDBHelper::GetInventoryById(inventoryId);
            return inventory != nullptr ? inventory->Location : "Unknown";
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

    private:
        ref class EditProductForm : public Form
        {
        private:
            Label^ lblName;
            TextBox^ txtName;
            Label^ lblCategoryId;
            ComboBox^ cmbCategoryId; // class-level ComboBox
            Label^ lblInventoryId;
            ComboBox^ cmbInventoryId; // class-level ComboBox for Inventory
            Label^ lblPrice;
            Label^ lblBarcode;
            Label^ lblCount;
            TextBox^ txtPrice;
            TextBox^ txtCount;
            TextBox^ txtBarcode;
            Button^ btnSave;
            Button^ btnCancel;
            Product^ product;

            Color originalBtnSaveBackColor;
            Color originalBtnCancelBackColor;

        public:
            property Product^ UpdatedProduct {
                Product^ get() {
                    return product;
                }
            }

            EditProductForm()
            {
                InitializeComponent();
                product = gcnew Product();
            }

            EditProductForm(Product^ existingProduct)
            {
                InitializeComponent();
                product = existingProduct;
                LoadProductData();
            }

        private:
            void InitializeComponent()
            {
                this->Text = "Edit Product";
                this->Width = 400;
                this->Height = 500;
                this->BackColor = Color::FromArgb(46, 46, 46);
                this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
                this->MaximizeBox = false;
                this->StartPosition = FormStartPosition::CenterParent;
                this->Padding = Windows::Forms::Padding(20);
                this->Font = gcnew Drawing::Font("Segoe UI", 10);

                // Name
                lblName = gcnew Label();
                lblName->Text = "Name:";
                lblName->ForeColor = Color::White;
                lblName->Location = Point(20, 60);
                lblName->Width = 100;
                this->Controls->Add(lblName);

                txtName = gcnew TextBox();
                txtName->Location = Point(130, 60);
                txtName->Width = 200;
                txtName->BackColor = Color::FromArgb(60, 60, 60);
                txtName->ForeColor = Color::White;
                this->Controls->Add(txtName);

                // Category ID
                lblCategoryId = gcnew Label();
                lblCategoryId->Text = "Category:";
                lblCategoryId->ForeColor = Color::White;
                lblCategoryId->Location = Point(20, 100);
                lblCategoryId->Width = 100;
                this->Controls->Add(lblCategoryId);

                cmbCategoryId = gcnew ComboBox(); // Category ComboBox
                cmbCategoryId->Location = Point(130, 100);
                cmbCategoryId->Width = 200;
                cmbCategoryId->BackColor = Color::FromArgb(60, 60, 60);
                cmbCategoryId->ForeColor = Color::White;
                cmbCategoryId->DropDownStyle = ComboBoxStyle::DropDownList;

                // Load categories
                List<Category^>^ categories = CategoryDBHelper::GetAllCategories();
                for each (Category ^ cat in categories) {
                    cmbCategoryId->Items->Add(cat);
                }
                cmbCategoryId->DisplayMember = "Name";

                if (cmbCategoryId->Items->Count > 0) {
                    cmbCategoryId->SelectedIndex = 0;
                }

                this->Controls->Add(cmbCategoryId);

                // Inventory ID
                lblInventoryId = gcnew Label();
                lblInventoryId->Text = "Inventory:";
                lblInventoryId->ForeColor = Color::White;
                lblInventoryId->Location = Point(20, 140);
                lblInventoryId->Width = 100;
                this->Controls->Add(lblInventoryId);

                cmbInventoryId = gcnew ComboBox(); // Inventory ComboBox
                cmbInventoryId->Location = Point(130, 140);
                cmbInventoryId->Width = 200;
                cmbInventoryId->BackColor = Color::FromArgb(60, 60, 60);
                cmbInventoryId->ForeColor = Color::White;
                cmbInventoryId->DropDownStyle = ComboBoxStyle::DropDownList;

                // Load inventories
                List<Inventory^>^ inventories = InventoryDBHelper::GetAllInventories();
                for each (Inventory ^ inv in inventories) {
                    cmbInventoryId->Items->Add(inv);
                }
                cmbInventoryId->DisplayMember = "Location";

                if (cmbInventoryId->Items->Count > 0) {
                    cmbInventoryId->SelectedIndex = 0;
                }

                this->Controls->Add(cmbInventoryId);

                // Price
                lblPrice = gcnew Label();
                lblPrice->Text = "Price:";
                lblPrice->ForeColor = Color::White;
                lblPrice->Location = Point(20, 180);
                lblPrice->Width = 100;
                this->Controls->Add(lblPrice);

                txtPrice = gcnew TextBox();
                txtPrice->Location = Point(130, 180);
                txtPrice->Width = 200;
                txtPrice->BackColor = Color::FromArgb(60, 60, 60);
                txtPrice->ForeColor = Color::White;
                this->Controls->Add(txtPrice);

                // Count
                lblCount = gcnew Label();
                lblCount->Text = "Count:";
                lblCount->ForeColor = Color::White;
                lblCount->Location = Point(20, 220);
                lblCount->Width = 100;
                this->Controls->Add(lblCount);

                txtCount = gcnew TextBox();
                txtCount->Location = Point(130, 220);
                txtCount->Width = 200;
                txtCount->BackColor = Color::FromArgb(60, 60, 60);
                txtCount->ForeColor = Color::White;
                this->Controls->Add(txtCount);

                // Barcode
                lblBarcode = gcnew Label();
                lblBarcode->Text = "Barcode:";
                lblBarcode->ForeColor = Color::White;
                lblBarcode->Location = Point(20, 260);
                lblBarcode->Width = 100;
                this->Controls->Add(lblBarcode);

                txtBarcode = gcnew TextBox();
                txtBarcode->Location = Point(130, 260);
                txtBarcode->Width = 200;
                txtBarcode->BackColor = Color::FromArgb(60, 60, 60);
                txtBarcode->ForeColor = Color::White;
                this->Controls->Add(txtBarcode);

                // Save Button
                btnSave = gcnew Button();
                btnSave->Text = "Save";
                btnSave->Font = gcnew Drawing::Font("Segoe UI", 10, FontStyle::Bold);
                btnSave->Location = Point(130, 320);
                btnSave->Width = 100;
                btnSave->Height = 40;
                btnSave->BackColor = Color::FromArgb(0, 120, 215);
                btnSave->ForeColor = Color::White;
                btnSave->FlatStyle = FlatStyle::Flat;
                btnSave->FlatAppearance->BorderSize = 0;
                btnSave->FlatAppearance->MouseOverBackColor = Color::FromArgb(0, 100, 180);
                originalBtnSaveBackColor = btnSave->BackColor;
                btnSave->Click += gcnew EventHandler(this, &EditProductForm::BtnSave_Click);
                this->Controls->Add(btnSave);

                // Cancel Button
                btnCancel = gcnew Button();
                btnCancel->Text = "Cancel";
                btnCancel->Font = gcnew Drawing::Font("Segoe UI", 10, FontStyle::Bold);
                btnCancel->Location = Point(240, 320);
                btnCancel->Width = 100;
                btnCancel->Height = 40;
                btnCancel->BackColor = Color::FromArgb(255, 80, 80);
                btnCancel->ForeColor = Color::White;
                btnCancel->FlatStyle = FlatStyle::Flat;
                btnCancel->FlatAppearance->BorderSize = 0;
                btnCancel->FlatAppearance->MouseOverBackColor = Color::FromArgb(200, 60, 60);
                originalBtnCancelBackColor = btnCancel->BackColor;
                btnCancel->Click += gcnew EventHandler(this, &EditProductForm::BtnCancel_Click);
                this->Controls->Add(btnCancel);
            }

            void LoadProductData()
            {
                if (product != nullptr)
                {
                    txtName->Text = product->Name;

                    // Load Category
                    for (int i = 0; i < cmbCategoryId->Items->Count; i++)
                    {
                        Category^ cat = dynamic_cast<Category^>(cmbCategoryId->Items[i]);
                        if (cat != nullptr && cat->Id == product->CategoryId)
                        {
                            cmbCategoryId->SelectedIndex = i;
                            break;
                        }
                    }

                    // Load Inventory
                    for (int i = 0; i < cmbInventoryId->Items->Count; i++)
                    {
                        Inventory^ inv = dynamic_cast<Inventory^>(cmbInventoryId->Items[i]);
                        if (inv != nullptr && inv->Id == product->InventoryId)
                        {
                            cmbInventoryId->SelectedIndex = i;
                            break;
                        }
                    }

                    txtPrice->Text = Convert::ToString(product->Price);
                    txtCount->Text = product->Count.ToString();
                    txtBarcode->Text = product->Barcode;
                }
            }

            void BtnSave_Click(Object^ sender, EventArgs^ e)
            {
                try
                {
                    product->Name = txtName->Text;

                    // Get selected category and inventory
                    Category^ selectedCategory = dynamic_cast<Category^>(cmbCategoryId->SelectedItem);
                    if (selectedCategory == nullptr)
                        throw gcnew Exception("Please select a category.");
                    product->CategoryId = selectedCategory->Id;

                    Inventory^ selectedInventory = dynamic_cast<Inventory^>(cmbInventoryId->SelectedItem);
                    if (selectedInventory == nullptr)
                        throw gcnew Exception("Please select an inventory.");
                    product->InventoryId = selectedInventory->Id;

                    product->Price = Convert::ToDouble(txtPrice->Text);
                    product->Count = Convert::ToInt32(txtCount->Text);
                    product->Barcode = txtBarcode->Text;

                    this->DialogResult = System::Windows::Forms::DialogResult::OK;
                    this->Close();
                }
                catch (Exception^ ex)
                {
                    MessageBox::Show("Invalid input: " + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
                }
            }

            void BtnCancel_Click(Object^ sender, EventArgs^ e)
            {
                this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
                this->Close();
            }
        };
    };
}