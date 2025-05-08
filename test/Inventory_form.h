#pragma once
#include "inventory.h"

namespace ProductApp {
    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Collections::Generic;
    using namespace System::Drawing;
    using namespace System::Data::SQLite;

    public ref class InventoryForm : public Form
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
        InventoryForm()
        {
            InitializeComponent();
        }

    private:
        void InitializeComponent()
        {
            this->Text = "Inventory Manager";
            this->Width = 800;
            this->Height = 900;
            this->BackColor = Color::FromArgb(46, 46, 46);

            // Title Label
            titleLabel = gcnew Label();
            titleLabel->Text = "Inventory Manager";
            titleLabel->Font = gcnew System::Drawing::Font("Segoe UI", 16, FontStyle::Bold);
            titleLabel->ForeColor = Color::White;
            titleLabel->AutoSize = true;
            titleLabel->Location = Point(20, 10);
            this->Controls->Add(titleLabel);

            // Search Label
            lblSearch = gcnew Label();
            lblSearch->Text = "Search Inventories: ";
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
            searchBox->TextChanged += gcnew EventHandler(this, &InventoryForm::OnSearchTextChanged);
            searchBox->GotFocus += gcnew EventHandler(this, &InventoryForm::OnSearchBoxFocus);
            searchBox->LostFocus += gcnew EventHandler(this, &InventoryForm::OnSearchBoxBlur);
            this->Controls->Add(searchBox);

            // Placeholder Label
            placeholderLabel = gcnew Label();
            placeholderLabel->Text = "Type inventory name...";
            placeholderLabel->Font = gcnew System::Drawing::Font("Segoe UI", 10);
            placeholderLabel->ForeColor = Color::Gray;
            placeholderLabel->Location = searchBox->Location;
            placeholderLabel->Width = searchBox->Width;
            placeholderLabel->Height = searchBox->Height;
            placeholderLabel->Click += gcnew EventHandler(this, &InventoryForm::OnPlaceholderClick);
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
            btnAdd->Click += gcnew EventHandler(this, &InventoryForm::BtnAdd_Click);
            btnAdd->MouseEnter += gcnew EventHandler(this, &InventoryForm::BtnAdd_MouseEnter);
            btnAdd->MouseLeave += gcnew EventHandler(this, &InventoryForm::BtnAdd_MouseLeave);
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
            dataGrid->CellClick += gcnew DataGridViewCellEventHandler(this, &InventoryForm::DataGrid_CellClick);
            this->Controls->Add(dataGrid);

            searchBox->TabIndex = 0;
            btnAdd->TabIndex = 1;
            dataGrid->TabIndex = 2;

            this->Resize += gcnew EventHandler(this, &InventoryForm::OnResize);
            LoadInventories("");
        }

        void OnResize(Object^ sender, EventArgs^ e)
        {
            separator->Width = this->ClientSize.Width - 40;
            dataGrid->Width = this->ClientSize.Width - 40;
            dataGrid->Height = this->ClientSize.Height - dataGrid->Top - 10;
        }

        void LoadInventories(String^ keyword)
        {
            List<Inventory^>^ inventories = RetrySearchInventoriesByLocation(keyword);
            dataGrid->Rows->Clear();
            dataGrid->Columns->Clear();

            // Add columns
            dataGrid->Columns->Add("Id", "ID");
            dataGrid->Columns->Add("Location", "Location");
            dataGrid->Columns->Add("update", "Update");
            dataGrid->Columns->Add("delete", "Delete");

            // Format columns
            dataGrid->Columns["Id"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
            dataGrid->Columns["update"]->Width = 80;
            dataGrid->Columns["delete"]->Width = 80;

            for each (Inventory ^ inv in inventories)
            {
                dataGrid->Rows->Add(inv->Id, inv->Location);

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
            LoadInventories(keyword);
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
                EditInventoryForm^ editForm = gcnew EditInventoryForm();
                if (editForm->ShowDialog(this) == System::Windows::Forms::DialogResult::OK)
                {
                    if (RetryAddInventory(editForm->UpdatedInventory))
                    {
                        MessageBox::Show("Inventory added");
                        LoadInventories("");
                    }
                    else
                    {
                        MessageBox::Show("Failed to add inventory.");
                    }
                }
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error adding inventory: " + ex->Message);
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
                int inventoryId = Convert::ToInt32(dataGrid->Rows[e->RowIndex]->Cells[0]->Value);

                if (e->ColumnIndex == dataGrid->Columns["delete"]->Index)
                {
                    System::Windows::Forms::DialogResult result = MessageBox::Show(
                        "Are you sure you want to delete inventory ID: " + inventoryId.ToString() + "?",
                        "Confirm Delete",
                        MessageBoxButtons::YesNo,
                        MessageBoxIcon::Warning);

                    if (result == System::Windows::Forms::DialogResult::Yes && RetryDeleteInventory(inventoryId))
                    {
                        MessageBox::Show("Inventory deleted");
                        LoadInventories("");
                    }
                }
                else if (e->ColumnIndex == dataGrid->Columns["update"]->Index)
                {
                    Inventory^ selected = RetryGetInventoryById(inventoryId);
                    if (selected != nullptr)
                    {
                        EditInventoryForm^ editForm = gcnew EditInventoryForm(selected);
                        if (editForm->ShowDialog(this) == System::Windows::Forms::DialogResult::OK)
                        {
                            if (RetryUpdateInventory(editForm->UpdatedInventory))
                            {
                                MessageBox::Show("Inventory updated");
                                LoadInventories("");
                            }
                            else
                            {
                                MessageBox::Show("Failed to update inventory.");
                            }
                        }
                    }
                    else
                    {
                        MessageBox::Show("Failed to retrieve inventory for update.");
                    }
                }
            }
        }

        List<Inventory^>^ RetrySearchInventoriesByLocation(String^ location)
        {
            int maxRetries = 3;
            int retryDelayMs = 100;
            for (int attempt = 0; attempt < maxRetries; attempt++)
            {
                try
                {
                    return InventoryDBHelper::SearchInventoriesByLocation(location);
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
            return gcnew List<Inventory^>();
        }

        bool RetryAddInventory(Inventory^ inventory)
        {
            int maxRetries = 3;
            int retryDelayMs = 100;
            for (int attempt = 0; attempt < maxRetries; attempt++)
            {
                try
                {
                    return InventoryDBHelper::AddInventory(inventory);
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

        Inventory^ RetryGetInventoryById(int id)
        {
            int maxRetries = 3;
            int retryDelayMs = 100;
            for (int attempt = 0; attempt < maxRetries; attempt++)
            {
                try
                {
                    return InventoryDBHelper::GetInventoryById(id);
                }
                catch (SQLiteException^ ex)
                {
                    if (ex->Message->Contains("database is locked") && attempt < maxRetries - 1)
                    {
                        System::Threading::Thread::Sleep(retryDelayMs);
                        continue;
                    }
                    MessageBox::Show("Get Inventory Error: " + ex->Message);
                    throw;
                }
            }
            return nullptr;
        }

        bool RetryUpdateInventory(Inventory^ inventory)
        {
            int maxRetries = 3;
            int retryDelayMs = 100;
            for (int attempt = 0; attempt < maxRetries; attempt++)
            {
                try
                {
                    return InventoryDBHelper::UpdateInventory(inventory);
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

        bool RetryDeleteInventory(int id)
        {
            int maxRetries = 3;
            int retryDelayMs = 100;
            for (int attempt = 0; attempt < maxRetries; attempt++)
            {
                try
                {
                    return InventoryDBHelper::DeleteInventory(id);
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
        ref class EditInventoryForm : public Form
        {
        private:
            Label^ lblLocation;
            TextBox^ txtLocation;
            Button^ btnSave;
            Button^ btnCancel;
            Inventory^ inventory;
            Color originalBtnSaveBackColor;
            Color originalBtnCancelBackColor;

        public:
            property Inventory^ UpdatedInventory {
                Inventory^ get() { return inventory; }
            }

            EditInventoryForm()
            {
                InitializeComponent();
                inventory = gcnew Inventory();
            }

            EditInventoryForm(Inventory^ existingInventory)
            {
                InitializeComponent();
                inventory = existingInventory;
                LoadInventoryData();
            }

        private:
            void InitializeComponent()
            {
                this->Text = "Edit Inventory";
                this->Width = 400;
                this->Height = 200;
                this->BackColor = Color::FromArgb(46, 46, 46);
                this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
                this->MaximizeBox = false;
                this->StartPosition = FormStartPosition::CenterParent;
                this->Padding = Windows::Forms::Padding(20);
                this->Font = gcnew Drawing::Font("Segoe UI", 10);

                // Location
                lblLocation = gcnew Label();
                lblLocation->Text = "Location:";
                lblLocation->ForeColor = Color::White;
                lblLocation->Location = Point(20, 40);
                lblLocation->Width = 100;
                this->Controls->Add(lblLocation);

                txtLocation = gcnew TextBox();
                txtLocation->Location = Point(130, 40);
                txtLocation->Width = 200;
                txtLocation->BackColor = Color::FromArgb(60, 60, 60);
                txtLocation->ForeColor = Color::White;
                this->Controls->Add(txtLocation);

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
                btnSave->Click += gcnew EventHandler(this, &EditInventoryForm::BtnSave_Click);
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
                btnCancel->Click += gcnew EventHandler(this, &EditInventoryForm::BtnCancel_Click);
                this->Controls->Add(btnCancel);
            }

            void LoadInventoryData()
            {
                if (inventory != nullptr)
                {
                    txtLocation->Text = inventory->Location;
                }
            }

            void BtnSave_Click(Object^ sender, EventArgs^ e)
            {
                try
                {
                    inventory->Location = txtLocation->Text;
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