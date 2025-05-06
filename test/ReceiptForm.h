#pragma once

#include "Product.h"
//#include "ProductDBHelper.h"
#include "InputDialog.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
using namespace System::Drawing;

public ref class ReceiptForm : public Form
{
private:
    // UI Elements
    TextBox^ searchBox;
    Button^ searchBtn;
    Button^ addToReceiptBtn;
    Button^ removeFromReceiptBtn;
    Button^ purchaseBtn;
    DataGridView^ productsGrid;
    DataGridView^ receiptGrid;
    Label^ totalLabel;
    double totalPrice = 0.0;

public:
    ReceiptForm()
    {
        InitializeComponent();

    }

private:
    void InitializeComponent()
    {
        this->Text = "Receipt Management";
        this->Width = 800;
        this->Height = 600;

        // 🔎 Search Bar
        searchBox = gcnew TextBox();
        searchBox->Top = 10;
        searchBox->Left = 10;
        searchBox->Width = 200;
        this->Controls->Add(searchBox);

        searchBtn = gcnew Button();
        searchBtn->Text = "Search";
        searchBtn->Top = 10;
        searchBtn->Left = 220;
        searchBtn->Click += gcnew EventHandler(this, &ReceiptForm::SearchProducts);
        this->Controls->Add(searchBtn);

        // 📦 Products Grid
        productsGrid = gcnew DataGridView();
        productsGrid->Top = 50;
        productsGrid->Left = 10;
        productsGrid->Width = 360;
        productsGrid->Height = 200;
        productsGrid->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
        this->Controls->Add(productsGrid);

        // ➕ Add to Receipt

        addToReceiptBtn = gcnew Button();
        addToReceiptBtn->Text = "➕ Add to Receipt";
        addToReceiptBtn->Top = 260;
        addToReceiptBtn->Left = 10;
        addToReceiptBtn->Click += gcnew EventHandler(this, &ReceiptForm::AddToReceipt);
        this->Controls->Add(addToReceiptBtn);

        // 📝 Receipt Grid
        receiptGrid = gcnew DataGridView();
        receiptGrid->Top = 300;
        receiptGrid->Left = 10;
        receiptGrid->Width = 360;
        receiptGrid->Height = 200;
        receiptGrid->SelectionMode = DataGridViewSelectionMode::FullRowSelect;

        receiptGrid->Columns->Add("ID", "ID");
        receiptGrid->Columns->Add("Name", "Name");
        receiptGrid->Columns->Add("Price", "Price");

        this->Controls->Add(receiptGrid);

        // ➖ Remove from Receipt
        removeFromReceiptBtn = gcnew Button();
        removeFromReceiptBtn->Text = "➖ Remove";
        removeFromReceiptBtn->Top = 510;
        removeFromReceiptBtn->Left = 10;
        removeFromReceiptBtn->Click += gcnew EventHandler(this, &ReceiptForm::RemoveFromReceipt);
        this->Controls->Add(removeFromReceiptBtn);

        // 🛒 Purchase Button
        purchaseBtn = gcnew Button();
        purchaseBtn->Text = "🛒 Purchase";
        purchaseBtn->Top = 510;
        purchaseBtn->Left = 120;
        purchaseBtn->Click += gcnew EventHandler(this, &ReceiptForm::Purchase);
        this->Controls->Add(purchaseBtn);

        // 💲 Total Label
        totalLabel = gcnew Label();
        totalLabel->Text = "Total: $0.00";
        totalLabel->Top = 510;
        totalLabel->Left = 250;
        totalLabel->Width = 200;
        this->Controls->Add(totalLabel);

        // Load all products initially
        LoadProducts("");
    }

    // 🔎 Search Products
    void SearchProducts(Object^ sender, EventArgs^ e)
    {
        LoadProducts(searchBox->Text);
    }

    void LoadProducts(String^ search)
    {
        List<Product^>^ products = ProductDBHelper::SearchProductsByName(search);
        productsGrid->Rows->Clear();
        productsGrid->Columns->Clear();

        // Define Columns
        productsGrid->Columns->Add("ID", "ID");
        productsGrid->Columns->Add("Name", "Name");
        productsGrid->Columns->Add("Price", "Price");

        // Add Products to Table
        for each (Product ^ p in products)
        {
            productsGrid->Rows->Add(p->Id, p->Name, p->Price);
        }
    }

    // ➕ Add to Receipt
    void AddToReceipt(Object^ sender, EventArgs^ e)
    {
        if (productsGrid->SelectedRows->Count == 0) return;

        int productId = Convert::ToInt32(productsGrid->SelectedRows[0]->Cells[0]->Value);
        Product^ p = ProductDBHelper::GetProductById(productId);
        if (p == nullptr) return;

        // Add product to receipt grid
        receiptGrid->Rows->Add(p->Id, p->Name, p->Price);
        totalPrice += p->Price;
        totalLabel->Text = "Total: $" + totalPrice.ToString("F2");
    }

    // ➖ Remove from Receipt
    void RemoveFromReceipt(Object^ sender, EventArgs^ e)
    {
        if (receiptGrid->SelectedRows->Count == 0) return;

        double price = Convert::ToDouble(receiptGrid->SelectedRows[0]->Cells[2]->Value);
        receiptGrid->Rows->Remove(receiptGrid->SelectedRows[0]);

        totalPrice -= price;
        totalLabel->Text = "Total: $" + totalPrice.ToString("F2");
    }

    // 🛒 Purchase
    // 🛒 Purchase
    void Purchase(Object^ sender, EventArgs^ e)
    {
        if (receiptGrid->Rows->Count == 0)
        {
            MessageBox::Show("No items in the receipt!", "Error");
            return;
        }

        // Ask for user cash input using custom InputDialog
        String^ input = InputDialog::Show("Enter cash amount:", "Payment", "0");
        if (String::IsNullOrWhiteSpace(input))
        {
            MessageBox::Show("No input entered.", "Error");
            return;
        }

        double userCash;
        if (!Double::TryParse(input, userCash))
        {
            MessageBox::Show("Invalid cash input.", "Error");
            return;
        }

        if (userCash < totalPrice)
        {
            MessageBox::Show("Insufficient funds!", "Error");
            return;
        }

        // Generate receipt text
        String^ receiptText = "=========== RECEIPT ===========\r\n";
        for each (DataGridViewRow ^ row in receiptGrid->Rows)
        {
            if (row->IsNewRow || row->Cells[1]->Value == nullptr || row->Cells[2]->Value == nullptr)
                continue;

            receiptText += row->Cells[1]->Value->ToString() + " - $" +
                row->Cells[2]->Value->ToString() + "\r\n";
        }
        receiptText += "--------------------------------\r\n";
        receiptText += "Total: $" + totalPrice.ToString("F2") + "\r\n";
        receiptText += "Cash:  $" + userCash.ToString("F2") + "\r\n";
        receiptText += "Change: $" + (userCash - totalPrice).ToString("F2") + "\r\n";
        receiptText += "================================\r\n";

        // Show a message with the receipt
        MessageBox::Show(receiptText, "Receipt");

        // Clear receipt
        receiptGrid->Rows->Clear();
        totalPrice = 0.0;
        totalLabel->Text = "Total: $0.00";
    }

};
