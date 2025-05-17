
#pragma once

#include "product.h"       
#include <vector>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

public ref class ReturnForm : public Form {
private:
    ComboBox^ cmbProduct;
    NumericUpDown^ numQuantity;
    Button^ btnAdd;
    DataGridView^ dgvReturns;
    Label^ lblTotalLabel;
    Label^ lblTotalAmount;
    Button^ btnConfirm;

    ref struct ReturnItem { Product^ Prod; int Quantity; double LineTotal; };
    List<ReturnItem^>^ returnsList;

public:
    ReturnForm() {
        this->Text = "Returns Manager";
        this->Size = Drawing::Size(600, 600);
        this->StartPosition = FormStartPosition::CenterScreen;
        returnsList = gcnew List<ReturnItem^>();
        InitializeComponent();
        LoadProductNames();
        UpdateTotal();
    }

private:
    void InitializeComponent() {
        // Product selector
        Label^ lblProd = gcnew Label();
        lblProd->Text = "Product Name:";
        lblProd->Location = Point(20, 20);
        this->Controls->Add(lblProd);

        cmbProduct = gcnew ComboBox();
        cmbProduct->Location = Point(120, 16);
        cmbProduct->Width = 300;
        cmbProduct->AutoCompleteMode = AutoCompleteMode::SuggestAppend;
        cmbProduct->AutoCompleteSource = AutoCompleteSource::ListItems;
        this->Controls->Add(cmbProduct);

        // Quantity
        Label^ lblQty = gcnew Label();
        lblQty->Text = "Return Quantity:";
        lblQty->Location = Point(20, 60);
        this->Controls->Add(lblQty);

        numQuantity = gcnew NumericUpDown();
        numQuantity->Location = Point(120, 56);
        numQuantity->Minimum = 1;
        numQuantity->Maximum = 1000;
        this->Controls->Add(numQuantity);

        // Add button
        btnAdd = gcnew Button();
        btnAdd->Text = "Add to Returns";
        btnAdd->Location = Point(450, 36);
        btnAdd->Click += gcnew EventHandler(this, &ReturnForm::OnAddClick);
        this->Controls->Add(btnAdd);

        // DataGridView
        dgvReturns = gcnew DataGridView();
        dgvReturns->Location = Point(20, 100);
        dgvReturns->Size = Drawing::Size(540, 350);
        dgvReturns->AllowUserToAddRows = false;
        dgvReturns->ReadOnly = false;
        dgvReturns->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
        dgvReturns->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
        dgvReturns->Columns->Add("Name", "Name");
        dgvReturns->Columns->Add("Quantity", "Quantity");
        dgvReturns->Columns->Add("Price", "Price");
        dgvReturns->Columns->Add("Total", "Total");
        // delete button column
        DataGridViewButtonColumn^ colDel = gcnew DataGridViewButtonColumn();
        colDel->Name = "Delete";
        colDel->HeaderText = "Delete";
        colDel->Text = "❌";
        colDel->UseColumnTextForButtonValue = true;
        dgvReturns->Columns->Add(colDel);
        dgvReturns->CellClick += gcnew DataGridViewCellEventHandler(this, &ReturnForm::OnGridCellClick);
        this->Controls->Add(dgvReturns);

        // Total labels
        lblTotalLabel = gcnew Label();
        lblTotalLabel->Text = "Total Returns:";
        lblTotalLabel->Location = Point(20, 470);
        lblTotalLabel->Font = gcnew Drawing::Font("Segoe UI", 10, FontStyle::Bold);
        this->Controls->Add(lblTotalLabel);

        lblTotalAmount = gcnew Label();
        lblTotalAmount->Text = "0.00";
        lblTotalAmount->Location = Point(140, 470);
        lblTotalAmount->Font = gcnew Drawing::Font("Segoe UI", 10, FontStyle::Bold);
        this->Controls->Add(lblTotalAmount);

        // Confirm button
        btnConfirm = gcnew Button();
        btnConfirm->Text = "Confirm Returns";
        btnConfirm->Location = Point(420, 465);
        btnConfirm->Click += gcnew EventHandler(this, &ReturnForm::OnConfirmClick);
        this->Controls->Add(btnConfirm);
    }

    void LoadProductNames() {
        cmbProduct->Items->Clear();
        List<Product^>^ all = ProductDBHelper::SearchProductsByName("");
        for each(Product ^ p in all)
            cmbProduct->Items->Add(p->Name);
    }

    void OnAddClick(Object^ sender, EventArgs^ e) {
        if (String::IsNullOrEmpty((String^)cmbProduct->Text)) return;
        String^ name = cmbProduct->Text;
        int qty = (int)numQuantity->Value;
        // find product by name (assume unique names)
        List<Product^>^ list = ProductDBHelper::SearchProductsByName(name);
        if (list->Count == 0) return;
        Product^ prod = list[0];
        double lineTotal = prod->Price * qty;
        // add to memory list
        ReturnItem^ item = gcnew ReturnItem();
        item->Prod = prod;
        item->Quantity = qty;
        item->LineTotal = lineTotal;
        returnsList->Add(item);
        // update grid
        dgvReturns->Rows->Add(prod->Name, qty, prod->Price, lineTotal);
        UpdateTotal();
    }

    void OnGridCellClick(Object^ sender, DataGridViewCellEventArgs^ e) {
        if (e->RowIndex < 0 || e->ColumnIndex != dgvReturns->Columns["Delete"]->Index) return;
        // remove from our returnsList and grid
        returnsList->RemoveAt(e->RowIndex);
        dgvReturns->Rows->RemoveAt(e->RowIndex);
        UpdateTotal();
    }

    void UpdateTotal() {
        double sum = 0;
        for each(ReturnItem ^ it in returnsList)
            sum += it->LineTotal;
        lblTotalAmount->Text = sum.ToString("F2");
    }

    void OnConfirmClick(Object^ sender, EventArgs^ e) {
        // For each return: increase product.Count and UpdateProduct in DB
        for each(ReturnItem ^ it in returnsList) {
            it->Prod->Count += it->Quantity;
            ProductDBHelper::UpdateProduct(it->Prod);
        }
        MessageBox::Show("Returns processed successfully.", "Done", MessageBoxButtons::OK, MessageBoxIcon::Information);
        // clear form
        returnsList->Clear();
        dgvReturns->Rows->Clear();
        UpdateTotal();
        LoadProductNames();
    }
};
