#pragma once
#include "Supplier.h"

namespace test {
    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;

    public ref class SupplierDialog : public Form {
    private:
        int editingId;

    public:
        TextBox^ txtName;
        TextBox^ txtCompany;
        TextBox^ txtDescription;
        TextBox^ txtPhone;
        Button^ btnOK;
        Button^ btnCancel;

        // Constructor for adding
        SupplierDialog()
            : editingId(0)
        {
            InitializeComponents();
            this->Text = "Add New Supplier";
        }

        // Constructor for edit
        SupplierDialog(Supplier^ s)
            : editingId(s->Id)
        {
            InitializeComponents();
            this->Text = "Edit Supplier";
            txtName->Text = s->Name;
            txtCompany->Text = s->Company;
            txtDescription->Text = s->Description;
            txtPhone->Text = s->Phone;
        }

    private:
        void InitializeComponents() {
            this->Size = Drawing::Size(400, 360);
            this->StartPosition = FormStartPosition::CenterParent;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->MaximizeBox = false;

            Label^ lbl;
            int y = 20;

            // Name
            lbl = gcnew Label();
            lbl->Text = "Name:";
            lbl->Location = Point(20, y);
            this->Controls->Add(lbl);

            txtName = gcnew TextBox();
            txtName->Location = Point(120, y);
            txtName->Width = 240;
            this->Controls->Add(txtName);
            y += 40;

            // Company
            lbl = gcnew Label();
            lbl->Text = "Company:";
            lbl->Location = Point(20, y);
            this->Controls->Add(lbl);

            txtCompany = gcnew TextBox();
            txtCompany->Location = Point(120, y);
            txtCompany->Width = 240;
            this->Controls->Add(txtCompany);
            y += 40;

            // Description (multiline)
            lbl = gcnew Label();
            lbl->Text = "Description:";
            lbl->Location = Point(20, y);
            this->Controls->Add(lbl);

            txtDescription = gcnew TextBox();
            txtDescription->Location = Point(120, y);
            txtDescription->Width = 240;
            txtDescription->Height = 80;
            txtDescription->Multiline = true;
            txtDescription->ScrollBars = ScrollBars::Vertical;
            this->Controls->Add(txtDescription);
            y += 100;

            // Phone
            lbl = gcnew Label();
            lbl->Text = "Phone:";
            lbl->Location = Point(20, y);
            this->Controls->Add(lbl);

            txtPhone = gcnew TextBox();
            txtPhone->Location = Point(120, y);
            txtPhone->Width = 240;
            this->Controls->Add(txtPhone);
            y += 50;

            // OK button
            btnOK = gcnew Button();
            btnOK->Text = "OK";
            btnOK->DialogResult = System::Windows::Forms::DialogResult::OK;
            btnOK->Location = Point(120, y);
            btnOK->Width = 100;
            this->Controls->Add(btnOK);

            // Cancel button
            btnCancel = gcnew Button();
            btnCancel->Text = "Cancel";
            btnCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
            btnCancel->Location = Point(260, y);
            btnCancel->Width = 100;
            this->Controls->Add(btnCancel);

            this->AcceptButton = btnOK;
            this->CancelButton = btnCancel;
        }

    public:
        // Return a Supplier object built from the dialog inputs
        Supplier^ GetSupplier() {
            return gcnew Supplier(
                editingId,
                txtName->Text,
                txtCompany->Text,
                txtDescription->Text,
                txtPhone->Text
            );
        }
    };
}
