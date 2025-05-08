#pragma once
#include "product.h"
#include "inventory.h"
#include "category.h"

namespace ProductApp {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;

    public ref class EditProductForm : public Form
    {
    private:
        bool _isNewProduct;
        Label^ lblName;
        Label^ lblCategory;
        Label^ lblInventory;
        Label^ lblPrice;
        Label^ lblCount;
        Label^ lblBarcode;

        TextBox^ txtName;
        ComboBox^ comboCategory;
        ComboBox^ comboInventory;
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

        property Product^ UpdatedProduct {
            Product^ get() { return product; }
        }

    private:
        void InitializeComponent()
        {
            this->Text = _isNewProduct ? "Add Product" : "Edit Product";
            this->Width = 400;
            this->Height = 450;  // Increased height to accommodate all controls
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
             // Add this include directive at the top of the file

            // Ensure the namespace is correctly referenced
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
            this->MaximizeBox = false;
            this->MinimizeBox = false;
            this->StartPosition = FormStartPosition::CenterParent;

            int textBoxWidth = 200;
            int leftMargin = 20;
            int topMargin = 20;
            int verticalSpacing = 30;

            // Name Section
            lblName = gcnew Label();
            lblName->Text = "Name:";
            lblName->Location = Point(leftMargin, topMargin);
            this->Controls->Add(lblName);

            txtName = gcnew TextBox();
            txtName->Location = Point(leftMargin, lblName->Bottom + 5);
            txtName->Width = textBoxWidth;
            txtName->Text = product->Name;
            this->Controls->Add(txtName);

            // Category Section
            lblCategory = gcnew Label();
            lblCategory->Text = "Category:";
            lblCategory->Location = Point(leftMargin, txtName->Bottom + verticalSpacing);
            this->Controls->Add(lblCategory);

            comboCategory = gcnew ComboBox();
            comboCategory->DropDownStyle = ComboBoxStyle::DropDownList;
            comboCategory->Location = Point(leftMargin, lblCategory->Bottom + 5);
            comboCategory->Width = textBoxWidth;
            LoadCategories();
            this->Controls->Add(comboCategory);

            // Inventory Section
            lblInventory = gcnew Label();
            lblInventory->Text = "Inventory:";
            lblInventory->Location = Point(leftMargin, comboCategory->Bottom + verticalSpacing);
            this->Controls->Add(lblInventory);

            comboInventory = gcnew ComboBox();
            comboInventory->DropDownStyle = ComboBoxStyle::DropDownList;
            comboInventory->Location = Point(leftMargin, lblInventory->Bottom + 5);
            comboInventory->Width = textBoxWidth;
            LoadInventories();
            this->Controls->Add(comboInventory);

            // Price Section
            lblPrice = gcnew Label();
            lblPrice->Text = "Price:";
            lblPrice->Location = Point(leftMargin, comboInventory->Bottom + verticalSpacing);
            this->Controls->Add(lblPrice);

            txtPrice = gcnew TextBox();
            txtPrice->Location = Point(leftMargin, lblPrice->Bottom + 5);
            txtPrice->Width = textBoxWidth;
            txtPrice->Text = product->Price.ToString();
            this->Controls->Add(txtPrice);

            // Count Section
            lblCount = gcnew Label();
            lblCount->Text = "Count:";
            lblCount->Location = Point(leftMargin, txtPrice->Bottom + verticalSpacing);
            this->Controls->Add(lblCount);

            txtCount = gcnew TextBox();
            txtCount->Location = Point(leftMargin, lblCount->Bottom + 5);
            txtCount->Width = textBoxWidth;
            txtCount->Text = product->Count.ToString();
            this->Controls->Add(txtCount);

            // Barcode Section
            lblBarcode = gcnew Label();
            lblBarcode->Text = "Barcode:";
            lblBarcode->Location = Point(leftMargin, txtCount->Bottom + verticalSpacing);
            this->Controls->Add(lblBarcode);

            txtBarcode = gcnew TextBox();
            txtBarcode->Location = Point(leftMargin, lblBarcode->Bottom + 5);
            txtBarcode->Width = textBoxWidth;
            txtBarcode->Text = product->Barcode;
            this->Controls->Add(txtBarcode);

            // Buttons
            btnSave = gcnew Button();
            btnSave->Text = _isNewProduct ? "Add" : "Save";
            btnSave->Location = Point(leftMargin, txtBarcode->Bottom + 30);
            btnSave->Click += gcnew EventHandler(this, &EditProductForm::BtnSave_Click);
            this->Controls->Add(btnSave);

            btnCancel = gcnew Button();
            btnCancel->Text = "Cancel";
            btnCancel->Location = Point(btnSave->Right + 10, btnSave->Top);
            btnCancel->Click += gcnew EventHandler(this, &EditProductForm::BtnCancel_Click);
            this->Controls->Add(btnCancel);
        }

        void LoadCategories()
        {
            try
            {
                comboCategory->DataSource = CategoryDBHelper::GetAllCategories();
                comboCategory->DisplayMember = "Name";
                comboCategory->ValueMember = "Id";
                comboCategory->SelectedValue = product->CategoryId;
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error loading categories: " + ex->Message);
            }
        }

        void LoadInventories()
        {
            try
            {
                comboInventory->DataSource = InventoryDBHelper::GetAllInventories();
                comboInventory->DisplayMember = "Location";
                comboInventory->ValueMember = "Id";
                comboInventory->SelectedValue = product->InventoryId;
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Error loading inventories: " + ex->Message);
            }
        }

        void BtnSave_Click(Object^ sender, EventArgs^ e)
        {
            try
            {
                // Validate selections
                if (comboCategory->SelectedValue == nullptr || comboInventory->SelectedValue == nullptr)
                {
                    MessageBox::Show("Please select both a category and an inventory location.");
                    return;
                }

                // Update product object
                product->Name = txtName->Text;
                product->CategoryId = safe_cast<int>(comboCategory->SelectedValue);
                product->InventoryId = safe_cast<int>(comboInventory->SelectedValue);
                product->Price = Convert::ToDouble(txtPrice->Text);
                product->Count = Convert::ToInt32(txtCount->Text);
                product->Barcode = txtBarcode->Text;

                this->DialogResult = System::Windows::Forms::DialogResult::OK;
                this->Close();
            }
            catch (FormatException^)
            {
                MessageBox::Show("Invalid numeric values! Please check:\n- Price must be a decimal number\n- Count must be a whole number");
            }
            catch (Exception^ ex)
            {
                MessageBox::Show("Saving failed: " + ex->Message);
            }
        }

        void BtnCancel_Click(Object^ sender, EventArgs^ e)
        {
         // Add this include directive at the top of the file if not already present
            this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
            this->Close();
        }
    };
}