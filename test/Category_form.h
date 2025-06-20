﻿#pragma once
#include "category.h"

//#include "dbhelper.h"

    namespace ProductApp {
        using namespace System;
        using namespace System::Windows::Forms;
        using namespace System::Collections::Generic;
        using namespace System::Drawing;
        using namespace System::Data::SQLite;

    public ref class CategoryForm : public System::Windows::Forms::UserControl
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
        CategoryForm()
        {
            InitializeComponent();
        }

    private:
        void InitializeComponent()
        {
            this->Text = "Category Manager";
            this->Width = 800;
            this->Height = 900;
            this->BackColor = Color::FromArgb(46, 46, 46);

            // Title Label
            titleLabel = gcnew Label();
            titleLabel->Text = "Category Manager";
            titleLabel->Font = gcnew System::Drawing::Font("Segoe UI", 16, System::Drawing::FontStyle::Bold);
            titleLabel->ForeColor = Color::White;
            titleLabel->AutoSize = true;
            titleLabel->Location = Point(20, 10);
            this->Controls->Add(titleLabel);

            // Search Label
            lblSearch = gcnew Label();
            lblSearch->Text = "Search Categories: ";
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
            searchBox->TextChanged += gcnew EventHandler(this, &CategoryForm::OnSearchTextChanged);
            searchBox->GotFocus += gcnew EventHandler(this, &CategoryForm::OnSearchBoxFocus);
            searchBox->LostFocus += gcnew EventHandler(this, &CategoryForm::OnSearchBoxBlur);
            this->Controls->Add(searchBox);

            // Placeholder Label
            placeholderLabel = gcnew Label();
            placeholderLabel->Text = "Type category name...";
            placeholderLabel->Font = gcnew System::Drawing::Font("Segoe UI", 10);
            placeholderLabel->ForeColor = Color::Gray;
            placeholderLabel->Location = searchBox->Location;
            placeholderLabel->Width = searchBox->Width;
            placeholderLabel->Height = searchBox->Height;
            placeholderLabel->Click += gcnew EventHandler(this, &CategoryForm::OnPlaceholderClick);
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
            btnAdd->Click += gcnew EventHandler(this, &CategoryForm::BtnAdd_Click);
            btnAdd->MouseEnter += gcnew EventHandler(this, &CategoryForm::BtnAdd_MouseEnter);
            btnAdd->MouseLeave += gcnew EventHandler(this, &CategoryForm::BtnAdd_MouseLeave);
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
            dataGrid->CellClick += gcnew DataGridViewCellEventHandler(this, &CategoryForm::DataGrid_CellClick);
            this->Controls->Add(dataGrid);

            searchBox->TabIndex = 0;
            btnAdd->TabIndex = 1;
            dataGrid->TabIndex = 2;

            this->Resize += gcnew EventHandler(this, &CategoryForm::OnResize);
            LoadCategories("");
        }

        void OnResize(Object^ sender, EventArgs^ e)
        {
            separator->Width = this->ClientSize.Width - 40;
            dataGrid->Width = this->ClientSize.Width - 40;
            dataGrid->Height = this->ClientSize.Height - dataGrid->Top - 10;
        }

        void LoadCategories(String^ keyword)
        {
            List<Category^>^ categories = RetrySearchCategoriesByName(keyword);
            dataGrid->Rows->Clear();
            dataGrid->Columns->Clear();

            // Add columns
            dataGrid->Columns->Add("Id", "ID");
            dataGrid->Columns->Add("Name", "Name");
            dataGrid->Columns->Add("update", "Update");
            dataGrid->Columns->Add("delete", "Delete");

            // Format columns
            dataGrid->Columns["Id"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
            dataGrid->Columns["update"]->Width = 80;
            dataGrid->Columns["delete"]->Width = 80;

            for each (Category ^ c in categories)
            {
                dataGrid->Rows->Add(c->Id, c->Name);
                // Update Button
                DataGridViewButtonCell^ BtnUpdate = gcnew DataGridViewButtonCell();
                BtnUpdate->Value = "Update";
                BtnUpdate->Style->BackColor = Color::FromArgb(0, 120, 215);
                BtnUpdate->Style->ForeColor = Color::White;
                dataGrid->Rows[dataGrid->Rows->Count - 1]->Cells["update"] = BtnUpdate;

                // Delete Button
                DataGridViewButtonCell^ BtnDelete = gcnew DataGridViewButtonCell();
                BtnDelete->Value = "Delete";
                BtnDelete->Style->BackColor = Color::FromArgb(255, 80, 80);
                BtnDelete->Style->ForeColor = Color::White;
                dataGrid->Rows[dataGrid->Rows->Count - 1]->Cells["delete"] = BtnDelete;
            }
        }

        void OnSearchTextChanged(Object^ sender, EventArgs^ e)
        {
            String^ keyword = searchBox->Text->Trim();
            LoadCategories(keyword);
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
                EditCategoryForm^ editForm = gcnew EditCategoryForm();
                if (editForm->ShowDialog(this) == System::Windows::Forms::DialogResult::OK)
                {
                    if (RetryAddCategory(editForm->UpdatedCategory))
                    {
                        MessageBox::Show("Category added");
                        LoadCategories("");
                    }
                    else
                    {
                        MessageBox::Show("Failed to add category.");
                    }
                }
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error adding category: " + ex->Message);
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
                int categoryId = Convert::ToInt32(dataGrid->Rows[e->RowIndex]->Cells[0]->Value);

                if (e->ColumnIndex == dataGrid->Columns["delete"]->Index)
                {
                    System::Windows::Forms::DialogResult result = MessageBox::Show(
                        "Are you sure you want to delete category ID: " + categoryId.ToString() + "?",
                        "Confirm Delete",
                        MessageBoxButtons::YesNo,
                        MessageBoxIcon::Warning);

                    if (result == System::Windows::Forms::DialogResult::Yes && RetryDeleteCategory(categoryId))
                    {
                        MessageBox::Show("Category deleted");
                        LoadCategories("");
                    }
                }
                else if (e->ColumnIndex == dataGrid->Columns["update"]->Index)
                {
                    Category^ selected = RetryGetCategoryById(categoryId);
                    if (selected != nullptr)
                    {
                        EditCategoryForm^ editForm = gcnew EditCategoryForm(selected);
                        if (editForm->ShowDialog(this) == System::Windows::Forms::DialogResult::OK)
                        {
                            if (RetryUpdateCategory(editForm->UpdatedCategory))
                            {
                                MessageBox::Show("Category updated");
                                LoadCategories("");
                            }
                            else
                            {
                                MessageBox::Show("Failed to update category.");
                            }
                        }
                    }
                    else
                    {
                        MessageBox::Show("Failed to retrieve category for update.");
                    }
                }
            }
        }

        List<Category^>^ RetrySearchCategoriesByName(String^ name)
        {
            int maxRetries = 3;
            int retryDelayMs = 100;
            for (int attempt = 0; attempt < maxRetries; attempt++)
            {
                try
                {
                    return CategoryDBHelper::SearchCategoriesByName(name);
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
            return gcnew List<Category^>();
        }

        bool RetryAddCategory(Category^ category)
        {
            int maxRetries = 3;
            int retryDelayMs = 100;
            for (int attempt = 0; attempt < maxRetries; attempt++)
            {
                try
                {
                    return CategoryDBHelper::AddCategory(category);
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

        Category^ RetryGetCategoryById(int id)
        {
            int maxRetries = 3;
            int retryDelayMs = 100;
            for (int attempt = 0; attempt < maxRetries; attempt++)
            {
                try
                {
                    return CategoryDBHelper::GetCategoryById(id);
                }
                catch (SQLiteException^ ex)
                {
                    if (ex->Message->Contains("database is locked") && attempt < maxRetries - 1)
                    {
                        System::Threading::Thread::Sleep(retryDelayMs);
                        continue;
                    }
                    MessageBox::Show("Get Category Error: " + ex->Message);
                    throw;
                }
            }
            return nullptr;
        }

        bool RetryUpdateCategory(Category^ category)
        {
            int maxRetries = 3;
            int retryDelayMs = 100;
            for (int attempt = 0; attempt < maxRetries; attempt++)
            {
                try
                {
                    return CategoryDBHelper::UpdateCategory(category);
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

        bool RetryDeleteCategory(int id)
        {
            int maxRetries = 3;
            int retryDelayMs = 100;
            for (int attempt = 0; attempt < maxRetries; attempt++)
            {
                try
                {
                    return CategoryDBHelper::DeleteCategory(id);
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
        ref class EditCategoryForm : public Form
        {
        private:
            Label^ lblName;
            TextBox^ txtName;
            Button^ btnSave;
            Button^ btnCancel;
            Category^ category;
            Color originalBtnSaveBackColor;
            Color originalBtnCancelBackColor;

        public:
            property Category^ UpdatedCategory {
                Category^ get() { return category; }
            }

            EditCategoryForm()
            {
                InitializeComponent();
                category = gcnew Category();
            }

            EditCategoryForm(Category^ existingCategory)
            {
                InitializeComponent();
                category = existingCategory;
                LoadCategoryData();
            }

        private:
            void InitializeComponent()
            {
                this->Text = "Edit Category";
                this->Width = 400;
                this->Height = 200;
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
                lblName->Location = Point(20, 40);
                lblName->Width = 100;
                this->Controls->Add(lblName);

                txtName = gcnew TextBox();
                txtName->Location = Point(130, 40);
                txtName->Width = 200;
                txtName->BackColor = Color::FromArgb(60, 60, 60);
                txtName->ForeColor = Color::White;
                this->Controls->Add(txtName);

                // Save Button
                btnSave = gcnew Button();
                btnSave->Text = "Save";
                btnSave->Font = gcnew Drawing::Font("Segoe UI", 10, FontStyle::Bold);
                btnSave->Location = Point(130, 90);
                btnSave->Width = 100;
                btnSave->Height = 40;
                btnSave->BackColor = Color::FromArgb(0, 120, 215);
                btnSave->ForeColor = Color::White;
                btnSave->FlatStyle = FlatStyle::Flat;
                btnSave->FlatAppearance->BorderSize = 0;
                btnSave->FlatAppearance->MouseOverBackColor = Color::FromArgb(0, 100, 180);
                originalBtnSaveBackColor = btnSave->BackColor;
                btnSave->Click += gcnew EventHandler(this, &EditCategoryForm::BtnSave_Click);
                this->Controls->Add(btnSave);

                // Cancel Button
                btnCancel = gcnew Button();
                btnCancel->Text = "Cancel";
                btnCancel->Font = gcnew Drawing::Font("Segoe UI", 10, FontStyle::Bold);
                btnCancel->Location = Point(240, 90);
                btnCancel->Width = 100;
                btnCancel->Height = 40;
                btnCancel->BackColor = Color::FromArgb(255, 80, 80);
                btnCancel->ForeColor = Color::White;
                btnCancel->FlatStyle = FlatStyle::Flat;
                btnCancel->FlatAppearance->BorderSize = 0;
                btnCancel->FlatAppearance->MouseOverBackColor = Color::FromArgb(200, 60, 60);
                originalBtnCancelBackColor = btnCancel->BackColor;
                btnCancel->Click += gcnew EventHandler(this, &EditCategoryForm::BtnCancel_Click);
                this->Controls->Add(btnCancel);
            }

            void LoadCategoryData()
            {
                if (category != nullptr)
                {
                    txtName->Text = category->Name;
                }
            }

            void BtnSave_Click(Object^ sender, EventArgs^ e)
            {
                try
                {
                    category->Name = txtName->Text;
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
