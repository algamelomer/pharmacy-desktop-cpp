#pragma once

#include "product.h"
namespace test {
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
        Label^ titleLabel;
        Label^ lblSearch;
        Label^ separator;

    public:
        ProductSearchForm()
        {
            this->Text = "Product Manager";
            this->Width = 800;
            this->Height = 900;
            this->BackColor = Color::FromArgb(46, 46, 46);

            // Title Label
            titleLabel = gcnew Label();
            titleLabel->Text = "Product Manager";
            titleLabel->Font = gcnew System::Drawing::Font("Segoe UI", 16, FontStyle::Bold);
            titleLabel->ForeColor = Color::White;
            titleLabel->AutoSize = true;
            titleLabel->Location = Point(20, 10);
            this->Controls->Add(titleLabel);

            // Search Label
            lblSearch = gcnew Label();
            lblSearch->Text = "Search Products: ";
            lblSearch->Font = gcnew System::Drawing::Font("Segoe UI", 10);
            lblSearch->ForeColor = Color::White;
            lblSearch->Location = Point(20, 50);
            lblSearch->Width = 100;
            lblSearch->Height = 20;
            this->Controls->Add(lblSearch);

            // Search Box
            searchBox = gcnew TextBox();
            searchBox->Location = Point(20, 70);
            searchBox->Width = 300;
            searchBox->Font = gcnew System::Drawing::Font("Segoe UI", 10);
            searchBox->BackColor = Color::FromArgb(60, 60, 60);
            searchBox->ForeColor = Color::White;
            searchBox->TextChanged += gcnew EventHandler(this, &ProductSearchForm::OnSearchTextChanged);
            searchBox->GotFocus += gcnew EventHandler(this, &ProductSearchForm::OnSearchBoxFocus);
            searchBox->LostFocus += gcnew EventHandler(this, &ProductSearchForm::OnSearchBoxBlur);
            this->Controls->Add(searchBox);

            // Placeholder Label
            placeholderLabel = gcnew Label();
            placeholderLabel->Text = "Type product name...";
            placeholderLabel->Font = gcnew System::Drawing::Font("Segoe UI", 10);
            placeholderLabel->ForeColor = Color::Gray;
            placeholderLabel->Location = searchBox->Location;
            placeholderLabel->Width = searchBox->Width;
            placeholderLabel->Height = searchBox->Height;
            placeholderLabel->Click += gcnew EventHandler(this, &ProductSearchForm::OnPlaceholderClick);
            this->Controls->Add(placeholderLabel);

            // Separator
            separator = gcnew Label();
            separator->BackColor = Color::FromArgb(0, 120, 215);
            separator->Height = 2;
            separator->Width = this->ClientSize.Width - 40;
            separator->Location = Point(20, searchBox->Top + searchBox->Height + 10);
            this->Controls->Add(separator);

            // Grid
            productGrid = gcnew DataGridView();
            productGrid->Top = separator->Top + separator->Height + 10;
            productGrid->Left = 20;
            productGrid->Width = this->ClientSize.Width - 40;
            productGrid->Height = this->ClientSize.Height - productGrid->Top - 10;
            productGrid->BackgroundColor = Color::FromArgb(46, 46, 46);
            productGrid->DefaultCellStyle->BackColor = Color::FromArgb(60, 60, 60);
            productGrid->DefaultCellStyle->ForeColor = Color::White;
            productGrid->AlternatingRowsDefaultCellStyle->BackColor = Color::FromArgb(50, 50, 50);
            productGrid->ColumnHeadersDefaultCellStyle->BackColor = Color::FromArgb(0, 120, 215);
            productGrid->ColumnHeadersDefaultCellStyle->ForeColor = Color::White;
            productGrid->EnableHeadersVisualStyles = false;
            productGrid->DefaultCellStyle->SelectionBackColor = Color::FromArgb(0, 100, 180);
            productGrid->DefaultCellStyle->SelectionForeColor = Color::White;
            productGrid->RowHeadersVisible = false;
            productGrid->CellBorderStyle = DataGridViewCellBorderStyle::SingleHorizontal;
            productGrid->GridColor = Color::FromArgb(80, 80, 80);
            productGrid->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::EnableResizing;
            productGrid->ColumnHeadersHeight = 40;
            productGrid->ColumnHeadersDefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
            productGrid->RowTemplate->Height = 30;
            productGrid->Font = gcnew System::Drawing::Font("Segoe UI", 9);
            productGrid->ReadOnly = true;
            productGrid->AllowUserToAddRows = false;
            productGrid->AllowUserToDeleteRows = false;
            productGrid->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
            productGrid->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
            this->Controls->Add(productGrid);

            // Initial load
            RefreshProductList("");

            // Resize event
            this->Resize += gcnew EventHandler(this, &ProductSearchForm::OnResize);
        }

    private:
        void OnResize(Object^ sender, EventArgs^ e)
        {
            separator->Width = this->ClientSize.Width - 40;
            productGrid->Width = this->ClientSize.Width - 40;
            productGrid->Height = this->ClientSize.Height - productGrid->Top - 10;
        }

        void OnSearchTextChanged(Object^ sender, EventArgs^ e)
        {
            placeholderLabel->Visible = String::IsNullOrEmpty(searchBox->Text);
            String^ keyword = searchBox->Text->Trim();
            RefreshProductList(keyword);
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

            // Define columns
            productGrid->Columns->Add("Id", "ID");
            productGrid->Columns->Add("Name", "Name");
            productGrid->Columns->Add("Category", "Category ID");
            productGrid->Columns->Add("Inventory", "Inventory ID");
            productGrid->Columns->Add("Price", "Price");
            productGrid->Columns->Add("Count", "Count");
            productGrid->Columns->Add("Barcode", "Barcode");

            // Set column alignments
            productGrid->Columns["Id"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
            productGrid->Columns["Category"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
            productGrid->Columns["Inventory"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
            productGrid->Columns["Price"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleRight;
            productGrid->Columns["Count"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
            productGrid->Columns["Barcode"]->DefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleLeft;

            // Populate rows
            for each (Product ^ p in products)
            {
                productGrid->Rows->Add(p->Id, p->Name, p->CategoryId, p->InventoryId, p->Price, p->Count, p->Barcode);
            }
        }

    private:
        System::Void InitializeComponent()
        {
            this->SuspendLayout();
            this->ClientSize = System::Drawing::Size(800, 900);
            this->Name = L"ProductSearchForm";
            this->Load += gcnew System::EventHandler(this, &ProductSearchForm::ProductSearchForm_Load);
            this->ResumeLayout(false);
        }

    private:
        System::Void ProductSearchForm_Load(System::Object^ sender, System::EventArgs^ e)
        {
        }
    };
}