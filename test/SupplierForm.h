#pragma once
#include "SupplierDBManage.h"
#include "SupplierDialog.h"

namespace test {
    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;

    public ref class SupplierForm : public Form {
    private:
        TextBox^ searchBox;
        DataGridView^ supplierGrid;
        FlowLayoutPanel^ buttonPanel;
        Button^ addButton;
        Button^ editButton;
        Button^ deleteButton;

    public:
        SupplierForm() {
            InitializeComponent();
            RefreshSupplierList("");
        }

    private:
        void InitializeComponent() {
            // sitting up the form
            this->Text = "Supplier Management";
            this->BackColor = Color::FromArgb(250, 250, 250);
            this->Size = Drawing::Size(900, 700);
            this->StartPosition = FormStartPosition::CenterScreen;

            // title label
            searchBox = gcnew TextBox();
            //searchBox->PlaceholderText = "Search by name, company, or phone...";
            searchBox->Dock = DockStyle::Top;
            searchBox->Margin = System::Windows::Forms::Padding(10);
            searchBox->Font = gcnew Drawing::Font("Segoe UI", 12);
            searchBox->TextChanged += gcnew EventHandler(this, &SupplierForm::OnSearchTextChanged);
            this->Controls->Add(searchBox);

            // GridView
            supplierGrid = gcnew DataGridView();
            supplierGrid->Dock = DockStyle::Fill;
            supplierGrid->BackgroundColor = Color::White;
            supplierGrid->AllowUserToAddRows = false;
            supplierGrid->ReadOnly = true;
            supplierGrid->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
            supplierGrid->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
            this->Controls->Add(supplierGrid);

            // Button Panel
            buttonPanel = gcnew FlowLayoutPanel();
            buttonPanel->FlowDirection = FlowDirection::LeftToRight;
            buttonPanel->Dock = DockStyle::Bottom;
            buttonPanel->Height = 60;
            buttonPanel->Padding = System::Windows::Forms::Padding(10);
            buttonPanel->BackColor = Color::FromArgb(240, 240, 240);

            addButton = CreateButton("Add", Color::FromArgb(0, 120, 215));
            addButton->Click += gcnew EventHandler(this, &SupplierForm::OnAddClick);
            editButton = CreateButton("Edit", Color::FromArgb(0, 153, 51));
            editButton->Click += gcnew EventHandler(this, &SupplierForm::OnEditClick);
            deleteButton = CreateButton("Delete", Color::FromArgb(192, 57, 43));
            deleteButton->Click += gcnew EventHandler(this, &SupplierForm::OnDeleteClick);

            buttonPanel->Controls->Add(addButton);
            buttonPanel->Controls->Add(editButton);
            buttonPanel->Controls->Add(deleteButton);
            this->Controls->Add(buttonPanel);
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
            btn->Margin = System::Windows::Forms::Padding(10, 10, 10, 10);
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

            supplierGrid->ColumnHeadersDefaultCellStyle->Font = gcnew Drawing::Font("Segoe UI", 11, FontStyle::Bold);
            supplierGrid->ColumnHeadersDefaultCellStyle->BackColor = Color::FromArgb(230, 230, 230);
            supplierGrid->EnableHeadersVisualStyles = false;

            List<Supplier^>^ suppliers = SupplierDBManage::SearchSuppliers(keyword);
            for each (Supplier ^ s in suppliers) {
                supplierGrid->Rows->Add(s->Id, s->Name, s->Company, s->Description, s->Phone);
            }
        }

        void OnSearchTextChanged(Object^, EventArgs^) {
            RefreshSupplierList(searchBox->Text);
        }

        void SupplierForm::OnAddClick(Object^, EventArgs^) {
            SupplierDialog^ dlg = gcnew SupplierDialog();
            if (dlg->ShowDialog(this) == System::Windows::Forms::DialogResult::OK) {
                Supplier^ newSup = dlg->GetSupplier();
                SupplierDBManage::InsertSupplier(newSup);
                RefreshSupplierList(searchBox->Text);
            }
        }

        void SupplierForm::OnEditClick(Object^, EventArgs^) {
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
