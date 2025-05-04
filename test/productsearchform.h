#pragma once

#include "product.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
using namespace System::Drawing;

public ref class ProductSearchForm : public Form
{
private:
   TextBox^ searchBox;
   DataGridView^ productGrid;
   Label^ placeholderLabel;

public:
   ProductSearchForm()
   {
       this->Text = "Search Products";
       this->Width = 800;
       this->Height = 500;

       // Search box
       searchBox = gcnew TextBox();
       searchBox->Location = Point(20, 20);
       searchBox->Width = 300;
       searchBox->TextChanged += gcnew EventHandler(this, &ProductSearchForm::OnSearchTextChanged);
       searchBox->GotFocus += gcnew EventHandler(this, &ProductSearchForm::OnSearchBoxFocus);
       searchBox->LostFocus += gcnew EventHandler(this, &ProductSearchForm::OnSearchBoxBlur);
       this->Controls->Add(searchBox);

       // Placeholder label
       placeholderLabel = gcnew Label();
       placeholderLabel->Text = "Type product name...";
       placeholderLabel->ForeColor = SystemColors::GrayText;
       placeholderLabel->Location = searchBox->Location;
       placeholderLabel->Width = searchBox->Width;
       placeholderLabel->Height = searchBox->Height;
       placeholderLabel->Click += gcnew EventHandler(this, &ProductSearchForm::OnPlaceholderClick);
       this->Controls->Add(placeholderLabel);

       // Grid
       productGrid = gcnew DataGridView();
       productGrid->Location = Point(20, 60);
       productGrid->Width = 740;
       productGrid->Height = 380;
       productGrid->ReadOnly = true;
       productGrid->AllowUserToAddRows = false;
       productGrid->AllowUserToDeleteRows = false;
       productGrid->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
       this->Controls->Add(productGrid);

       // Initial load
       RefreshProductList("");
   }

private:
   void OnSearchTextChanged(Object^ sender, EventArgs^ e)
   {
       String^ keyword = searchBox->Text->Trim();
       RefreshProductList(keyword);

       // Hide placeholder if text is entered
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

   void RefreshProductList(String^ keyword)
   {
       productGrid->Rows->Clear();
       productGrid->Columns->Clear();

       List<Product^>^ products = ProductDBHelper::SearchProductsByName(keyword);

       // Setup columns
       productGrid->Columns->Add("ID", "ID");
       productGrid->Columns->Add("Name", "Name");
       productGrid->Columns->Add("Category", "Category ID");
       productGrid->Columns->Add("Inventory", "Inventory ID");
       productGrid->Columns->Add("Price", "Price");
       productGrid->Columns->Add("Count", "Count");
       productGrid->Columns->Add("Barcode", "Barcode");

       for each (Product ^ p in products)
       {
           productGrid->Rows->Add(p->Id, p->Name, p->CategoryId, p->InventoryId, p->Price, p->Count, p->Barcode);
       }
   }
};
