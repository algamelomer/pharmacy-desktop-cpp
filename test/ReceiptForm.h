#pragma once

#include "Product.h"
#include "InputDialog.h"
using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
using namespace System::Drawing;

public ref class ReceiptForm : public Form
{
private:
    TextBox^ searchBox;
    DataGridView^ productsGrid;
    DataGridView^ receiptGrid;
    Button^ purchaseBtn;
    //Button^ printBtn;
    Label^ totalLabel;
    double totalPrice = 0.0;

public:
    ReceiptForm()
    {
        InitializeComponent();
    }

private:
    void OnCloseButtonClick(Object^ sender, EventArgs^ e)
    {
        // Close the receipt form
        Form^ receiptForm = safe_cast<Form^>(safe_cast<Control^>(sender)->Parent);
        if (receiptForm != nullptr)
        {
            receiptForm->Close();
        }
    }

    void InitializeComponent()
    {
        this->Text = "Receipt Management";
        this->Width = 800;
        this->Height = 600;

		int gridWidth = this->ClientSize.Width;
		int gridHeight = this->ClientSize.Height;

        searchBox = gcnew TextBox();
        searchBox->Top = 10;
        searchBox->Left = 10;
        searchBox->Width = 300;
        searchBox->TextChanged += gcnew EventHandler(this, &ReceiptForm::OnSearchTextChanged);
        this->Controls->Add(searchBox);

        productsGrid = gcnew DataGridView();
        productsGrid->Top = 40;
        productsGrid->Left = 10;
        productsGrid->Width = gridWidth;
        productsGrid->Height = 240;
        productsGrid->AllowUserToAddRows = false;
        productsGrid->ReadOnly = true;
        productsGrid->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
        productsGrid->CellContentClick += gcnew DataGridViewCellEventHandler(this, &ReceiptForm::OnProductGridCellClick);
        this->Controls->Add(productsGrid);

        receiptGrid = gcnew DataGridView();
        receiptGrid->Top = 300;
        receiptGrid->Left = 10;
        receiptGrid->Width = gridWidth;
        receiptGrid->Height = 200;
        receiptGrid->AllowUserToAddRows = false;
        receiptGrid->ReadOnly = true;
        receiptGrid->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
        receiptGrid->CellContentClick += gcnew DataGridViewCellEventHandler(this, &ReceiptForm::OnReceiptGridCellClick);
        receiptGrid->Columns->Add("ID", "ID");
        receiptGrid->Columns->Add("Name", "Name");
        receiptGrid->Columns->Add("Price", "Price");
        receiptGrid->Columns->Add("Remove", "Remove");
        this->Controls->Add(receiptGrid);

        purchaseBtn = gcnew Button();
        purchaseBtn->Text = "Purchase";
        purchaseBtn->Top = 510;
        purchaseBtn->Left = 10;
        purchaseBtn->Click += gcnew EventHandler(this, &ReceiptForm::Purchase);
        this->Controls->Add(purchaseBtn);

        totalLabel = gcnew Label();
        totalLabel->Text = "Total: $0.00";
        totalLabel->Top = 510;
        totalLabel->Left = 250;
        totalLabel->Width = 200;
        this->Controls->Add(totalLabel);

        LoadProducts("");
    }

    void OnSearchTextChanged(Object^ sender, EventArgs^ e)
    {
        LoadProducts(searchBox->Text);
    }

    void LoadProducts(String^ search)
    {
        List<Product^>^ products = ProductDBHelper::SearchProductsByName(search);
        productsGrid->Columns->Clear();
        productsGrid->Rows->Clear();

        productsGrid->Columns->Add("ID", "ID");
        productsGrid->Columns->Add("Name", "Name");
        productsGrid->Columns->Add("Price", "Price");

        DataGridViewButtonColumn^ addBtn = gcnew DataGridViewButtonColumn();
        addBtn->HeaderText = "Add";
        addBtn->Text = "add";
        addBtn->UseColumnTextForButtonValue = true;
        productsGrid->Columns->Add(addBtn);

        for each (Product ^ p in products)
        {
            productsGrid->Rows->Add(p->Id, p->Name, p->Price);
        }
    }

    void OnProductGridCellClick(Object^ sender, DataGridViewCellEventArgs^ e)
    {
        if (e->RowIndex >= 0 && e->ColumnIndex == 3) // Add button column
        {
            int productId = Convert::ToInt32(productsGrid->Rows[e->RowIndex]->Cells[0]->Value);
            Product^ p = ProductDBHelper::GetProductById(productId);
            if (p)
            {
                receiptGrid->Rows->Add(p->Id, p->Name, p->Price);
				DataGridViewButtonCell^ removeBtn = gcnew DataGridViewButtonCell();
				removeBtn->Value = "Remove";
				receiptGrid->Rows[receiptGrid->Rows->Count - 1]->Cells["Remove"] = removeBtn;


                totalPrice += p->Price;
                totalLabel->Text = "Total: $" + totalPrice.ToString("F2");
            }
        }
    }

    void OnReceiptGridCellClick(Object^ sender, DataGridViewCellEventArgs^ e)
    {
        if (e->RowIndex >= 0 && e->ColumnIndex == 3) // Remove button column
        {
            double price = Convert::ToDouble(receiptGrid->Rows[e->RowIndex]->Cells[2]->Value);
            receiptGrid->Rows->RemoveAt(e->RowIndex);
            totalPrice -= price;
            totalLabel->Text = "Total: $" + totalPrice.ToString("F2");
        }
    }

    void Purchase(Object^ sender, EventArgs^ e)  
       {  
           if (receiptGrid->Rows->Count == 0)  
           {  
               MessageBox::Show("No items in the receipt!", "Error");  
               return;  
           }  

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

           String^ receiptText = GenerateReceiptText(userCash);  

           // Create a custom form for the receipt message box with a Print button  
           Form^ receiptForm = gcnew Form();  
           receiptForm->Text = "Receipt";  
           receiptForm->Width = 400;  
           receiptForm->Height = 300;  

           TextBox^ receiptBox = gcnew TextBox();  
           receiptBox->Multiline = true;  
           receiptBox->ReadOnly = true;  
           receiptBox->Dock = DockStyle::Top;  
           receiptBox->Height = 200;  
           receiptBox->Text = receiptText;  
           receiptForm->Controls->Add(receiptBox);  

           Button^ printButton = gcnew Button();  
           printButton->Text = "Print";  
           printButton->Dock = DockStyle::Bottom;  
           printButton->Click += gcnew EventHandler(this, &ReceiptForm::PrintReceipt);  
           receiptForm->Controls->Add(printButton);  

           Button^ closeButton = gcnew Button();  
           closeButton->Text = "Close";  
           closeButton->Dock = DockStyle::Bottom;  
           //closeButton->Click += gcnew EventHandler(this, &ReceiptForm::Close);
        // Fix for the invalid delegate initializer and related errors

        // Update the Close button's event handler assignment
        closeButton->Click += gcnew EventHandler(this, &ReceiptForm::OnCloseButtonClick);

        // Add the OnCloseButtonClick method to handle the Close button click event

     
           receiptForm->Controls->Add(closeButton);

           // Store the receipt text for printing  
           this->storedReceiptText = receiptText;  

           receiptForm->ShowDialog();  

           receiptGrid->Rows->Clear();  
           totalPrice = 0.0;  
           totalLabel->Text = "Total: $0.00";  
       }

    void PrintReceipt(Object^ sender, EventArgs^ e)  
    {  
       if (receiptGrid->Rows->Count == 0)  
       {  
           MessageBox::Show("No items to print.", "Error");  
           return;  
       }  

       double fakeCash = totalPrice;  
       String^ receiptText = GenerateReceiptText(fakeCash);  

       System::Drawing::Printing::PrintDocument^ printDoc = gcnew System::Drawing::Printing::PrintDocument();  
       printDoc->PrintPage += gcnew System::Drawing::Printing::PrintPageEventHandler(this, &ReceiptForm::OnPrintPage);  

       // Store receiptText in a member variable to avoid lambda capture issues  
       this->storedReceiptText = receiptText;  

       PrintDialog^ printDialog = gcnew PrintDialog();  
       printDialog->Document = printDoc;  
       if (printDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)  
       {  
           printDoc->Print();  
       }  
    }  

    void OnPrintPage(Object^ sender, System::Drawing::Printing::PrintPageEventArgs^ e)  
    {  
       e->Graphics->DrawString(this->storedReceiptText, gcnew System::Drawing::Font("Consolas", 12),  
           Brushes::Black, PointF(100, 100));  
    }  

    // Add a private member variable to store the receipt text  
    private:  
       String^ storedReceiptText;

    String^ GenerateReceiptText(double userCash)
    {
        String^ receiptText = "=========== RECEIPT ===========\r\n";
        for each (DataGridViewRow ^ row in receiptGrid->Rows)
        {
            if (row->IsNewRow) continue;
            receiptText += row->Cells[1]->Value->ToString() + " - $" + row->Cells[2]->Value->ToString() + "\r\n";
        }
        receiptText += "--------------------------------\r\n";
        receiptText += "Total: $" + totalPrice.ToString("F2") + "\r\n";
        receiptText += "Cash:  $" + userCash.ToString("F2") + "\r\n";
        receiptText += "Change: $" + (userCash - totalPrice).ToString("F2") + "\r\n";
        receiptText += "================================\r\n";
		receiptText += "Thank you for your purchase!\r\n";
		receiptText += "================================\r\n";
		receiptText += "Please visit us again!\r\n";
        return receiptText;
    }
};
