#pragma once
#include "product.h"

namespace ProductApp {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;

    public ref class EditProductForm : public Form
    {
    private:
        bool _isNewProduct;
        Label^ lblName;
        Label^ lblCategoryId;
        Label^ lblInventoryId;
        Label^ lblPrice;
        Label^ lblCount;
        Label^ lblBarcode;

        TextBox^ txtName;
        TextBox^ txtCategoryId;
        TextBox^ txtInventoryId;
        TextBox^ txtPrice;
        TextBox^ txtCount;
        TextBox^ txtBarcode;

        Button^ btnSave;
        Button^ btnCancel;

        Product^ product;

    public:
        EditProductForm(Product^ prod)
        {
            product = prod;
            _isNewProduct = false;
            InitializeComponent();
        }
        EditProductForm()
        {
            product = gcnew Product();
            _isNewProduct = true;
            InitializeComponent();
        }
        // Property to get the updated product
        property Product^ UpdatedProduct {
            Product^ get() { return product; }
        }

    private:
        void InitializeComponent()
        {
            this->Text = _isNewProduct ? "Add Product" : "Edit Product";
            this->Width = 400;
            this->Height = 400;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->StartPosition = FormStartPosition::CenterParent;

            int labelWidth = 100;
            int textBoxWidth = 200;
            int leftMargin = 20;
            int topMargin = 20;
            int verticalSpacing = 30;

            // Labels and TextBoxes
            lblName = gcnew Label();
            lblName->Text = "Name";
            lblName->Top = topMargin;
            lblName->Left = leftMargin;
            this->Controls->Add(lblName);

            txtName = gcnew TextBox();
            txtName->Top = lblName->Top + 20;
            txtName->Left = leftMargin;
            txtName->Width = textBoxWidth;
            txtName->Text = product->Name;
            this->Controls->Add(txtName);

            lblCategoryId = gcnew Label();
            lblCategoryId->Text = "Category ID";
            lblCategoryId->Top = txtName->Top + verticalSpacing;
            lblCategoryId->Left = leftMargin;
            this->Controls->Add(lblCategoryId);

            txtCategoryId = gcnew TextBox();
            txtCategoryId->Top = lblCategoryId->Top + 20;
            txtCategoryId->Left = leftMargin;
            txtCategoryId->Width = textBoxWidth;
            txtCategoryId->Text = product->CategoryId.ToString();
            this->Controls->Add(txtCategoryId);

            lblInventoryId = gcnew Label();
            lblInventoryId->Text = "Inventory ID";
            lblInventoryId->Top = txtCategoryId->Top + verticalSpacing;
            lblInventoryId->Left = leftMargin;
            this->Controls->Add(lblInventoryId);

            txtInventoryId = gcnew TextBox();
            txtInventoryId->Top = lblInventoryId->Top + 20;
            txtInventoryId->Left = leftMargin;
            txtInventoryId->Width = textBoxWidth;
            txtInventoryId->Text = product->InventoryId.ToString();
            this->Controls->Add(txtInventoryId);

            lblPrice = gcnew Label();
            lblPrice->Text = "Price";
            lblPrice->Top = txtInventoryId->Top + verticalSpacing;
            lblPrice->Left = leftMargin;
            this->Controls->Add(lblPrice);

            txtPrice = gcnew TextBox();
            txtPrice->Top = lblPrice->Top + 20;
            txtPrice->Left = leftMargin;
            txtPrice->Width = textBoxWidth;
            txtPrice->Text = product->Price.ToString();
            this->Controls->Add(txtPrice);

            lblCount = gcnew Label();
            lblCount->Text = "Count";
            lblCount->Top = txtPrice->Top + verticalSpacing;
            lblCount->Left = leftMargin;
            this->Controls->Add(lblCount);

            txtCount = gcnew TextBox();
            txtCount->Top = lblCount->Top + 20;
            txtCount->Left = leftMargin;
            txtCount->Width = textBoxWidth;
            txtCount->Text = product->Count.ToString();
            this->Controls->Add(txtCount);

            lblBarcode = gcnew Label();
            lblBarcode->Text = "Barcode";
            lblBarcode->Top = txtCount->Top + verticalSpacing;
            lblBarcode->Left = leftMargin;
            this->Controls->Add(lblBarcode);

            txtBarcode = gcnew TextBox();
            txtBarcode->Top = lblBarcode->Top + 20;
            txtBarcode->Left = leftMargin;
            txtBarcode->Width = textBoxWidth;
            txtBarcode->Text = product->Barcode;
            this->Controls->Add(txtBarcode);

            // Buttons
            btnSave = gcnew Button();
            btnSave->Text = _isNewProduct ? "Add" : "Save";
            btnSave->Top = txtBarcode->Top + 40;
            btnSave->Left = leftMargin;
            btnSave->Click += gcnew EventHandler(this, &EditProductForm::BtnSave_Click);
            this->Controls->Add(btnSave);

            btnCancel = gcnew Button();
            btnCancel->Text = "Cancel";
            btnCancel->Top = btnSave->Top;
            btnCancel->Left = leftMargin + 90;
            btnCancel->Click += gcnew EventHandler(this, &EditProductForm::BtnCancel_Click);
            this->Controls->Add(btnCancel);
        }

        void BtnSave_Click(Object^ sender, EventArgs^ e)
        {
            try
            {
                product->Name = txtName->Text;
                product->CategoryId = Convert::ToInt32(txtCategoryId->Text);
                product->InventoryId = Convert::ToInt32(txtInventoryId->Text);
                product->Price = Convert::ToDouble(txtPrice->Text);
                product->Count = Convert::ToInt32(txtCount->Text);
                product->Barcode = txtBarcode->Text;
                this->DialogResult = System::Windows::Forms::DialogResult::OK;
                this->Close();
            }
            catch (FormatException^)
            {
                MessageBox::Show("Please enter valid numeric values for Category ID, Inventory ID, Price, and Count.");
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error saving product: " + ex->Message);
            }
        }

        void BtnCancel_Click(Object^ sender, EventArgs^ e)
        {
            this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
            this->Close();
        }
    };
}