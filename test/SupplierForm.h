#pragma once
#include "SupplierDBManage.h"
#include "SupplierDialog.h"

namespace test {
    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;
    using namespace System::Collections::Generic;

    public ref class SupplierForm : public System::Windows::Forms::UserControl {
    private:
        TextBox^ searchBox;
        Label^ placeholderLabel;
        Label^ titleLabel;
        Label^ lblSearch;
        Label^ separator;
        DataGridView^ supplierGrid;

    public:
        SupplierForm() {
            InitializeComponent();
            RefreshSupplierList("");
        }

    private:
        void InitializeComponent() {
            // Form setup
            this->Text = "Supplier Manager";
            this->Width = 900;
            this->Height = 800;
            this->BackColor = Color::FromArgb(46, 46, 46);
            //this->StartPosition = FormStartPosition::CenterScreen;

            // Title Label
            titleLabel = gcnew Label();
            titleLabel->Text = "Supplier Manager";
            titleLabel->Font = gcnew Drawing::Font("Segoe UI", 16, FontStyle::Bold);
            titleLabel->ForeColor = Color::White;
            titleLabel->AutoSize = true;
            titleLabel->Location = Point(20, 10);
            this->Controls->Add(titleLabel);

            // Search Label
            lblSearch = gcnew Label();
            lblSearch->Text = "Search";
            lblSearch->Font = gcnew Drawing::Font("Segoe UI", 10);
            lblSearch->ForeColor = Color::White;
            lblSearch->Location = Point(20, 45);
            this->Controls->Add(lblSearch);

            // Search Box
            searchBox = gcnew TextBox();
            searchBox->Location = Point(20, 70);
            searchBox->Width = 300;
            searchBox->Font = gcnew Drawing::Font("Segoe UI", 10);
            searchBox->BackColor = Color::FromArgb(60, 60, 60);
            searchBox->ForeColor = Color::White;
            //searchBox->BorderStyle = BorderStyle::FixedSingle;
            searchBox->TextChanged += gcnew EventHandler(this, &SupplierForm::OnSearchTextChanged);
            searchBox->GotFocus += gcnew EventHandler(this, &SupplierForm::OnSearchBoxFocus);
            searchBox->LostFocus += gcnew EventHandler(this, &SupplierForm::OnSearchBoxBlur);
            this->Controls->Add(searchBox);

            // Placeholder Label
            placeholderLabel = gcnew Label();
            placeholderLabel->Text = "Type supplier name...";
            placeholderLabel->Font = gcnew Drawing::Font("Segoe UI", 10);
            placeholderLabel->ForeColor = Color::Gray;
            placeholderLabel->Location = searchBox->Location;
            placeholderLabel->Size = searchBox->Size;
            placeholderLabel->Click += gcnew EventHandler(this, &SupplierForm::OnPlaceholderClick);
            this->Controls->Add(placeholderLabel);

            // Separator
            separator = gcnew Label();
            separator->BackColor = Color::FromArgb(0, 120, 215);
            separator->Height = 2;
            separator->Width = this->ClientSize.Width - 40;
            separator->Location = Point(20, searchBox->Bottom + 10);
            this->Controls->Add(separator);

            // Supplier Grid
            supplierGrid = gcnew DataGridView();
            supplierGrid->Top = separator->Bottom + 10;
            supplierGrid->Left = 20;
            supplierGrid->Width = this->ClientSize.Width - 40;
            supplierGrid->Height = this->ClientSize.Height - supplierGrid->Top - 80;
            supplierGrid->BackgroundColor = Color::FromArgb(46, 46, 46);
            supplierGrid->DefaultCellStyle->BackColor = Color::FromArgb(60, 60, 60);
            supplierGrid->DefaultCellStyle->ForeColor = Color::White;
            supplierGrid->AlternatingRowsDefaultCellStyle->BackColor = Color::FromArgb(50, 50, 50);
            supplierGrid->ColumnHeadersDefaultCellStyle->BackColor = Color::FromArgb(0, 120, 215);
            supplierGrid->ColumnHeadersDefaultCellStyle->ForeColor = Color::White;
            supplierGrid->EnableHeadersVisualStyles = false;
            supplierGrid->DefaultCellStyle->SelectionBackColor = Color::FromArgb(0, 100, 180);
            supplierGrid->DefaultCellStyle->SelectionForeColor = Color::White;
            supplierGrid->RowHeadersVisible = false;
            supplierGrid->CellBorderStyle = DataGridViewCellBorderStyle::SingleHorizontal;
            supplierGrid->GridColor = Color::FromArgb(80, 80, 80);
            supplierGrid->ColumnHeadersHeight = 40;
            supplierGrid->ColumnHeadersDefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
            supplierGrid->RowTemplate->Height = 30;
            supplierGrid->Font = gcnew Drawing::Font("Segoe UI", 10);
            supplierGrid->AllowUserToAddRows = false;
            supplierGrid->ReadOnly = true;
            supplierGrid->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
            supplierGrid->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
            this->Controls->Add(supplierGrid);

            // Buttons
            FlowLayoutPanel^ buttonPanel = gcnew FlowLayoutPanel();
            buttonPanel->FlowDirection = FlowDirection::LeftToRight;
            buttonPanel->Dock = DockStyle::Bottom;
            buttonPanel->Height = 60;
            buttonPanel->Padding = System::Windows::Forms::Padding(10);
            buttonPanel->BackColor = Color::FromArgb(46, 46, 46);

            Button^ addButton = CreateButton("Add", Color::FromArgb(0, 120, 215));
            addButton->Click += gcnew EventHandler(this, &SupplierForm::OnAddClick);
            Button^ editButton = CreateButton("Edit", Color::FromArgb(0, 153, 51));
            editButton->Click += gcnew EventHandler(this, &SupplierForm::OnEditClick);
            Button^ deleteButton = CreateButton("Delete", Color::FromArgb(192, 57, 43));
            deleteButton->Click += gcnew EventHandler(this, &SupplierForm::OnDeleteClick);

            buttonPanel->Controls->Add(addButton);
            buttonPanel->Controls->Add(editButton);
            buttonPanel->Controls->Add(deleteButton);
            this->Controls->Add(buttonPanel);
            this->Resize += gcnew EventHandler(this, &SupplierForm::OnResize);
        }


        void OnResize(Object^ sender, EventArgs^ e)
        {
            separator->Width = this->ClientSize.Width - 40;
            supplierGrid->Width = this->ClientSize.Width - 40;
            supplierGrid->Height = this->ClientSize.Height - supplierGrid->Top - 80;
        }


        Button^ CreateButton(String^ text, Color backColor) {
            Button^ btn = gcnew Button();
            btn->Text = text;
            btn->BackColor = backColor;
            btn->ForeColor = Color::White;
            btn->Font = gcnew Drawing::Font("Segoe UI", 10, FontStyle::Bold);
            btn->Height = 40;
            btn->Width = 100;
            btn->FlatStyle = FlatStyle::Flat;
            btn->Margin = System::Windows::Forms::Padding(10);
            return btn;
        }

        void RefreshSupplierList(String^ keyword) {
            supplierGrid->Rows->Clear();
            supplierGrid->Columns->Clear();

            supplierGrid->Columns->Add("Id", "ID");
            supplierGrid->Columns->Add("Name", "Name");
            supplierGrid->Columns->Add("Company", "Company");
            supplierGrid->Columns->Add("Description", "Description");
            supplierGrid->Columns->Add("Phone", "Phone");

            List<Supplier^>^ suppliers = SupplierDBManage::SearchSuppliers(keyword);
            for each(Supplier ^ s in suppliers) {
                supplierGrid->Rows->Add(s->Id, s->Name, s->Company, s->Description, s->Phone);
            }
        }

        void OnSearchTextChanged(Object^, EventArgs^) {
            RefreshSupplierList(searchBox->Text);
            placeholderLabel->Visible = String::IsNullOrWhiteSpace(searchBox->Text);
        }

        void OnSearchBoxFocus(Object^, EventArgs^) {
            placeholderLabel->Visible = false;
        }

        void OnSearchBoxBlur(Object^, EventArgs^) {
            if (String::IsNullOrWhiteSpace(searchBox->Text)) {
                placeholderLabel->Visible = true;
            }
        }

        void OnPlaceholderClick(Object^ sender, EventArgs^ e) {
            searchBox->Focus();
        }

        void OnAddClick(Object^, EventArgs^) {
            SupplierDialog^ dlg = gcnew SupplierDialog();
            if (dlg->ShowDialog(this) == System::Windows::Forms::DialogResult::OK) {
                Supplier^ newSup = dlg->GetSupplier();
                SupplierDBManage::InsertSupplier(newSup);
                RefreshSupplierList(searchBox->Text);
            }
        }

        void OnEditClick(Object^, EventArgs^) {
            if (supplierGrid->SelectedRows->Count == 0) return;

            int id = Convert::ToInt32(supplierGrid->SelectedRows[0]->Cells["Id"]->Value);
            String^ name = supplierGrid->SelectedRows[0]->Cells["Name"]->Value->ToString();
            String^ company = supplierGrid->SelectedRows[0]->Cells["Company"]->Value->ToString();
            String^ desc = supplierGrid->SelectedRows[0]->Cells["Description"]->Value->ToString();
            String^ phone = supplierGrid->SelectedRows[0]->Cells["Phone"]->Value->ToString();

            Supplier^ current = gcnew Supplier(id, name, company, desc, phone);

            SupplierDialog^ dlg = gcnew SupplierDialog(current);
            if (dlg->ShowDialog(this) == System::Windows::Forms::DialogResult::OK) {
                Supplier^ updated = dlg->GetSupplier();
                SupplierDBManage::UpdateSupplier(updated);
                RefreshSupplierList(searchBox->Text);
            }
        }

        void OnDeleteClick(Object^, EventArgs^) {
            if (supplierGrid->SelectedRows->Count > 0) {
                int id = Convert::ToInt32(supplierGrid->SelectedRows[0]->Cells["Id"]->Value);
                SupplierDBManage::DeleteSupplier(id);
                RefreshSupplierList(searchBox->Text);
            }
        }
    };
}
