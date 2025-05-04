#pragma once
#include "product.h"
//#include "ProductDBHelper.h"

namespace ProductApp {

    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Collections::Generic;

    public ref class ProductForm : public Form
    {
    private:
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
        BindingSource^ bindingSource;

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
            this->Height = 600;

            txtName = gcnew TextBox();
            txtName->Top = 20;
            txtName->Left = 20;
            txtName->Width = 200;

            txtCategoryId = gcnew TextBox();
            txtCategoryId->Top = 50;
            txtCategoryId->Left = 20;
            txtCategoryId->Width = 200;

            txtInventoryId = gcnew TextBox();
            txtInventoryId->Top = 80;
            txtInventoryId->Left = 20;
            txtInventoryId->Width = 200;

            txtPrice = gcnew TextBox();
            txtPrice->Top = 110;
            txtPrice->Left = 20;
            txtPrice->Width = 200;

            txtCount = gcnew TextBox();
            txtCount->Top = 140;
            txtCount->Left = 20;
            txtCount->Width = 200;

            txtBarcode = gcnew TextBox();
            txtBarcode->Top = 170;
            txtBarcode->Left = 20;
            txtBarcode->Width = 200;

            btnAdd = gcnew Button();
            btnAdd->Text = "Add";
            btnAdd->Top = 200;
            btnAdd->Left = 20;
            btnAdd->Click += gcnew EventHandler(this, &ProductForm::BtnAdd_Click);

            btnUpdate = gcnew Button();
            btnUpdate->Text = "Update";
            btnUpdate->Top = 200;
            btnUpdate->Left = 100;
            btnUpdate->Click += gcnew EventHandler(this, &ProductForm::BtnUpdate_Click);

            btnDelete = gcnew Button();
            btnDelete->Text = "Delete";
            btnDelete->Top = 200;
            btnDelete->Left = 180;
            btnDelete->Click += gcnew EventHandler(this, &ProductForm::BtnDelete_Click);

            dataGrid = gcnew DataGridView();
            dataGrid->Top = 250;
            dataGrid->Left = 20;
            dataGrid->Width = 740;
            dataGrid->Height = 300;
            dataGrid->ReadOnly = true;
            dataGrid->AutoGenerateColumns = true;
            dataGrid->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
            dataGrid->CellClick += gcnew DataGridViewCellEventHandler(this, &ProductForm::DataGrid_CellClick);

            this->Controls->Add(txtName);
            this->Controls->Add(txtCategoryId);
            this->Controls->Add(txtInventoryId);
            this->Controls->Add(txtPrice);
            this->Controls->Add(txtCount);
            this->Controls->Add(txtBarcode);
            this->Controls->Add(btnAdd);
            this->Controls->Add(btnUpdate);
            this->Controls->Add(btnDelete);
            this->Controls->Add(dataGrid);

            LoadProducts();
        }

        void LoadProducts()
        {
            List<Product^>^ products = ProductDBHelper::SearchProductsByName("");
            bindingSource = gcnew BindingSource();
            bindingSource->DataSource = products;
            dataGrid->DataSource = bindingSource;
        }

        void BtnAdd_Click(Object^ sender, EventArgs^ e)
        {
            Product^ p = gcnew Product();
            p->Name = txtName->Text;
            p->CategoryId = Convert::ToInt32(txtCategoryId->Text);
            p->InventoryId = Convert::ToInt32(txtInventoryId->Text);
            p->Price = Convert::ToDouble(txtPrice->Text);
            p->Count = Convert::ToInt32(txtCount->Text);
            p->Barcode = txtBarcode->Text;

            if (ProductDBHelper::AddProduct(p))
            {
                MessageBox::Show("Product added successfully");
                LoadProducts();
            }
        }

        void BtnUpdate_Click(Object^ sender, EventArgs^ e)
        {
            if (dataGrid->SelectedRows->Count == 0) return;

            Product^ selected = (Product^)bindingSource[dataGrid->SelectedRows[0]->Index];
            selected->Name = txtName->Text;
            selected->CategoryId = Convert::ToInt32(txtCategoryId->Text);
            selected->InventoryId = Convert::ToInt32(txtInventoryId->Text);
            selected->Price = Convert::ToDouble(txtPrice->Text);
            selected->Count = Convert::ToInt32(txtCount->Text);
            selected->Barcode = txtBarcode->Text;

            if (ProductDBHelper::UpdateProduct(selected))
            {
                MessageBox::Show("Product updated");
                LoadProducts();
            }
        }

        void BtnDelete_Click(Object^ sender, EventArgs^ e)
        {
            if (dataGrid->SelectedRows->Count == 0) return;

            Product^ selected = (Product^)bindingSource[dataGrid->SelectedRows[0]->Index];
            if (ProductDBHelper::DeleteProduct(selected->Id))
            {
                MessageBox::Show("Product deleted");
                LoadProducts();
            }
        }

        void DataGrid_CellClick(Object^ sender, DataGridViewCellEventArgs^ e)
        {
            if (e->RowIndex >= 0)
            {
                Product^ selected = (Product^)bindingSource[e->RowIndex];
                txtName->Text = selected->Name;
                txtCategoryId->Text = selected->CategoryId.ToString();
                txtInventoryId->Text = selected->InventoryId.ToString();
                txtPrice->Text = selected->Price.ToString();
                txtCount->Text = selected->Count.ToString();
                txtBarcode->Text = selected->Barcode;
            }
        }
    };
}
