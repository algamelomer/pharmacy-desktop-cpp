#pragma once

#include "product.h"       
#include <vector>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;

public ref class ReturnForm : public System::Windows::Forms::UserControl {
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
        //this->StartPosition = FormStartPosition::CenterScreen;
        this->BackColor = Color::FromArgb(40, 40, 40);
        this->MinimumSize = Drawing::Size(400, 400);
        this->Size = Drawing::Size(800, 600);
        returnsList = gcnew List<ReturnItem^>();
        InitializeComponent();
        LoadProductNames();
        UpdateTotal();
    }

private:
    void InitializeComponent() {
        // form properties
        this->Resize += gcnew EventHandler(this, &ReturnForm::OnFormResize);

        // Title Label
        Label^ titleLabel = gcnew Label();
        titleLabel->Text = "Returns Manager";
        titleLabel->Font = gcnew Drawing::Font("Segoe UI", 14, FontStyle::Bold);
        titleLabel->ForeColor = Color::FromArgb(245, 245, 245);
        titleLabel->AutoSize = true;
        titleLabel->Location = Point(20, 20);
        titleLabel->Anchor = AnchorStyles::Top | AnchorStyles::Left;
        this->Controls->Add(titleLabel);

        // Separator
        Label^ separator = gcnew Label();
        separator->Name = "separator";
        separator->BackColor = Color::FromArgb(0, 120, 215);
        separator->Height = 2;
        separator->Anchor = AnchorStyles::Top | AnchorStyles::Left | AnchorStyles::Right;
        separator->Location = Point(20, 60);
        separator->Width = this->ClientSize.Width - 40;
        this->Controls->Add(separator);

        // Product selector
        Label^ lblProd = gcnew Label();
        lblProd->Text = "Product Name:";
        lblProd->Location = Point(20, 80);
        lblProd->ForeColor = Color::FromArgb(245, 245, 245);
        lblProd->Font = gcnew Drawing::Font("Segoe UI", 10);
        lblProd->Anchor = AnchorStyles::Top | AnchorStyles::Left;
        this->Controls->Add(lblProd);

        cmbProduct = gcnew ComboBox();
        cmbProduct->Name = "cmbProduct";
        cmbProduct->Location = Point(120, 76);
        cmbProduct->Anchor = AnchorStyles::Top | AnchorStyles::Left | AnchorStyles::Right;
        cmbProduct->Width = this->ClientSize.Width - 160;
        cmbProduct->AutoCompleteMode = AutoCompleteMode::SuggestAppend;
        cmbProduct->AutoCompleteSource = AutoCompleteSource::ListItems;
        cmbProduct->BackColor = Color::FromArgb(60, 60, 60);
        cmbProduct->ForeColor = Color::FromArgb(245, 245, 245);
        cmbProduct->Font = gcnew Drawing::Font("Segoe UI", 10);
        this->Controls->Add(cmbProduct);

        // Quantity
        Label^ lblQty = gcnew Label();
        lblQty->Text = "Return Quantity:";
        lblQty->Location = Point(20, 120);
        lblQty->ForeColor = Color::FromArgb(245, 245, 245);
        lblQty->Font = gcnew Drawing::Font("Segoe UI", 10);
        lblQty->Anchor = AnchorStyles::Top | AnchorStyles::Left;
        this->Controls->Add(lblQty);

        numQuantity = gcnew NumericUpDown();
        numQuantity->Location = Point(120, 116);
        numQuantity->Width = 100;
        numQuantity->Minimum = 1;
        numQuantity->Maximum = 1000;
        numQuantity->BackColor = Color::FromArgb(60, 60, 60);
        numQuantity->ForeColor = Color::FromArgb(245, 245, 245);
        numQuantity->Font = gcnew Drawing::Font("Segoe UI", 10);
        numQuantity->Anchor = AnchorStyles::Top | AnchorStyles::Left;
        this->Controls->Add(numQuantity);

        btnAdd = gcnew Button();
        btnAdd->Text = "Add to Returns";
        btnAdd->Size = Drawing::Size(120, 40);
        btnAdd->Location = Point(this->ClientSize.Width - 140, 110);
        btnAdd->Anchor = AnchorStyles::Top | AnchorStyles::Right;
        btnAdd->Click += gcnew EventHandler(this, &ReturnForm::OnAddClick);
        this->Controls->Add(btnAdd);
        SetupButtonGradient(btnAdd);

        // DataGridView
        dgvReturns = gcnew DataGridView();
        dgvReturns->Name = "dgvReturns";
        dgvReturns->Location = Point(20, 160);
        dgvReturns->Anchor = AnchorStyles::Top | AnchorStyles::Bottom | AnchorStyles::Left | AnchorStyles::Right;
        dgvReturns->Size = Drawing::Size(this->ClientSize.Width - 40, this->ClientSize.Height - 240);
        dgvReturns->AllowUserToAddRows = false;
        dgvReturns->ReadOnly = false;
        dgvReturns->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
        dgvReturns->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
        dgvReturns->BackgroundColor = Color::FromArgb(40, 40, 40);
        dgvReturns->DefaultCellStyle->BackColor = Color::FromArgb(60, 60, 60);
        dgvReturns->DefaultCellStyle->ForeColor = Color::FromArgb(245, 245, 245);
        dgvReturns->AlternatingRowsDefaultCellStyle->BackColor = Color::FromArgb(50, 50, 50);
        dgvReturns->ColumnHeadersDefaultCellStyle->BackColor = Color::FromArgb(0, 120, 215);
        dgvReturns->ColumnHeadersDefaultCellStyle->ForeColor = Color::White;
        dgvReturns->EnableHeadersVisualStyles = false;
        dgvReturns->DefaultCellStyle->SelectionBackColor = Color::FromArgb(0, 140, 255);
        dgvReturns->DefaultCellStyle->SelectionForeColor = Color::White;
        dgvReturns->RowHeadersVisible = false;
        dgvReturns->CellBorderStyle = DataGridViewCellBorderStyle::Single;
        dgvReturns->GridColor = Color::FromArgb(80, 80, 80);
        dgvReturns->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::EnableResizing;
        dgvReturns->ColumnHeadersHeight = 40;
        dgvReturns->ColumnHeadersDefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
        dgvReturns->RowTemplate->Height = 30;
        dgvReturns->Columns->Add("Name", "Name");
        dgvReturns->Columns->Add("Quantity", "Quantity");
        dgvReturns->Columns->Add("Price", "Price");
        dgvReturns->Columns->Add("Total", "Total");
        DataGridViewButtonColumn^ colDel = gcnew DataGridViewButtonColumn();
        colDel->Name = "Delete";
        colDel->HeaderText = "Delete";
        colDel->Text = "Remove";
        colDel->UseColumnTextForButtonValue = true;
        colDel->FlatStyle = FlatStyle::Flat;
        colDel->DefaultCellStyle->BackColor = Color::FromArgb(255, 80, 80);
        colDel->DefaultCellStyle->ForeColor = Color::White;
        dgvReturns->Columns->Add(colDel);
        dgvReturns->CellClick += gcnew DataGridViewCellEventHandler(this, &ReturnForm::OnGridCellClick);
        this->Controls->Add(dgvReturns);

        // Total labels
        lblTotalLabel = gcnew Label();
        lblTotalLabel->Text = "Total Returns:";
        lblTotalLabel->Location = Point(20, this->ClientSize.Height - 80);
        lblTotalLabel->ForeColor = Color::FromArgb(245, 245, 245);
        lblTotalLabel->Font = gcnew Drawing::Font("Segoe UI", 10, FontStyle::Bold);
        lblTotalLabel->Anchor = AnchorStyles::Bottom | AnchorStyles::Left;
        this->Controls->Add(lblTotalLabel);

        lblTotalAmount = gcnew Label();
        lblTotalAmount->Text = "0.00";
        lblTotalAmount->Location = Point(140, this->ClientSize.Height - 80);
        lblTotalAmount->ForeColor = Color::FromArgb(245, 245, 245);
        lblTotalAmount->Font = gcnew Drawing::Font("Segoe UI", 10, FontStyle::Bold);
        lblTotalAmount->Anchor = AnchorStyles::Bottom | AnchorStyles::Left;
        this->Controls->Add(lblTotalAmount);

        // Confirm button
        btnConfirm = gcnew Button();
        btnConfirm->Text = "Confirm Returns";
        btnConfirm->Size = Drawing::Size(140, 40);
        btnConfirm->Location = Point(this->ClientSize.Width - 160, this->ClientSize.Height - 85);
        btnConfirm->Anchor = AnchorStyles::Bottom | AnchorStyles::Right;
        btnConfirm->Click += gcnew EventHandler(this, &ReturnForm::OnConfirmClick);
        this->Controls->Add(btnConfirm);
        SetupButtonGradient(btnConfirm);

        // Tooltips
        ToolTip^ toolTip = gcnew ToolTip();
        toolTip->SetToolTip(btnAdd, "Add product to returns");
        toolTip->SetToolTip(btnConfirm, "Confirm returns");
    }

    void SetupButtonGradient(Button^ btn) {
        btn->BackColor = Color::FromArgb(0, 120, 215);
        btn->ForeColor = Color::White;
        btn->FlatStyle = FlatStyle::Flat;
        btn->FlatAppearance->BorderSize = 1;
        btn->FlatAppearance->BorderColor = Color::FromArgb(0, 80, 150);
        btn->FlatAppearance->MouseOverBackColor = Color::FromArgb(0, 140, 255);
        btn->Paint += gcnew PaintEventHandler(this, &ReturnForm::Button_Paint);
    }

    void Button_Paint(Object^ sender, PaintEventArgs^ e) {
        Button^ btn = safe_cast<Button^>(sender);
        Rectangle rect = btn->ClientRectangle;
        rect.Width -= 1;
        rect.Height -= 1;
        LinearGradientBrush^ brush = gcnew LinearGradientBrush(rect, Color::FromArgb(0, 120, 215), Color::FromArgb(0, 140, 255), 45.0f);
        e->Graphics->FillRectangle(brush, rect);
        Pen^ pen = gcnew Pen(Color::FromArgb(0, 80, 150));
        e->Graphics->DrawRectangle(pen, rect);
        TextRenderer::DrawText(e->Graphics, btn->Text, btn->Font, rect, btn->ForeColor, TextFormatFlags::HorizontalCenter | TextFormatFlags::VerticalCenter);
    }

    void LoadProductNames() {
        cmbProduct->Items->Clear();
        List<Product^>^ all = ProductDBHelper::SearchProductsByName("");
        for each (Product ^ p in all)
            cmbProduct->Items->Add(p->Name);
    }

    void OnAddClick(Object^ sender, EventArgs^ e) {
        if (String::IsNullOrEmpty((String^)cmbProduct->Text)) return;
        String^ name = cmbProduct->Text;
        int qty = (int)numQuantity->Value;
        List<Product^>^ list = ProductDBHelper::SearchProductsByName(name);
        if (list->Count == 0) return;
        Product^ prod = list[0];
        double lineTotal = prod->Price * qty;
        ReturnItem^ item = gcnew ReturnItem();
        item->Prod = prod;
        item->Quantity = qty;
        item->LineTotal = lineTotal;
        returnsList->Add(item);
        dgvReturns->Rows->Add(prod->Name, qty, prod->Price, lineTotal);
        UpdateTotal();
    }

    void OnGridCellClick(Object^ sender, DataGridViewCellEventArgs^ e) {
        if (e->RowIndex < 0 || e->ColumnIndex != dgvReturns->Columns["Delete"]->Index) return;
        returnsList->RemoveAt(e->RowIndex);
        dgvReturns->Rows->RemoveAt(e->RowIndex);
        UpdateTotal();
    }

    void UpdateTotal() {
        double sum = 0;
        for each (ReturnItem ^ it in returnsList)
            sum += it->LineTotal;
        lblTotalAmount->Text = sum.ToString("F2");
    }

    void OnConfirmClick(Object^ sender, EventArgs^ e) {
        for each (ReturnItem ^ it in returnsList) {
            it->Prod->Count += it->Quantity;
            ProductDBHelper::UpdateProduct(it->Prod);
        }
        MessageBox::Show("Returns processed successfully.", "Done", MessageBoxButtons::OK, MessageBoxIcon::Information);
        returnsList->Clear();
        dgvReturns->Rows->Clear();
        UpdateTotal();
        LoadProductNames();
    }

    void OnFormResize(Object^ sender, EventArgs^ e) {
        for each (Control ^ ctrl in this->Controls) {
            if (ctrl->Name == "separator") {
                ctrl->Width = this->ClientSize.Width - 40;
            }
            if (ctrl->Name == "cmbProduct") {
                ctrl->Width = this->ClientSize.Width - 160;
            }
            if (ctrl->Name == "dgvReturns") {
                ctrl->Size = Drawing::Size(this->ClientSize.Width - 40, this->ClientSize.Height - 240);
            }
        }
    }
};