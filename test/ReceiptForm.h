#pragma

#include "Product.h"
#include "sale.h"
#include "sale_item.h"
#include "CustomerTypeDialog.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;

public ref class CustomInputDialog : public Form
{
private:
    TextBox^ inputTextBox;
    Button^ okButton;
    Button^ cancelButton;
    Label^ promptLabel;

public:
    static String^ Show(String^ prompt, String^ title, String^ defaultValue)
    {
        CustomInputDialog^ dialog = gcnew CustomInputDialog(prompt, title, defaultValue);
        if (dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
        {
            return dialog->inputTextBox->Text;
        }
        return nullptr;
    }

private:
    CustomInputDialog(String^ prompt, String^ title, String^ defaultValue)
    {
        this->Text = title;
        this->Width = 400;
        this->Height = 200;
        this->BackColor = Color::FromArgb(40, 40, 40);
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
        this->MaximizeBox = false;
        this->StartPosition = FormStartPosition::CenterParent;
        this->Padding = Windows::Forms::Padding(20);
        this->Font = gcnew Drawing::Font("Segoe UI", 11);

        promptLabel = gcnew Label();
        promptLabel->Text = prompt;
        promptLabel->ForeColor = Color::FromArgb(245, 245, 245);
        promptLabel->Location = Point(20, 20);
        promptLabel->Width = 340;
        this->Controls->Add(promptLabel);

        inputTextBox = gcnew TextBox();
        inputTextBox->Location = Point(20, 60);
        inputTextBox->Width = 340;
        inputTextBox->BackColor = Color::FromArgb(60, 60, 60);
        inputTextBox->ForeColor = Color::FromArgb(245, 245, 245);
        inputTextBox->BorderStyle = BorderStyle::FixedSingle;
        inputTextBox->Text = defaultValue;
        this->Controls->Add(inputTextBox);

        okButton = gcnew Button();
        okButton->Text = "OK";
        okButton->Font = gcnew Drawing::Font("Segoe UI", 11, FontStyle::Bold);
        okButton->Location = Point(150, 120);
        okButton->Width = 100;
        okButton->Height = 40;
        okButton->BackColor = Color::FromArgb(0, 120, 215);
        okButton->ForeColor = Color::White;
        okButton->FlatStyle = FlatStyle::Flat;
        okButton->FlatAppearance->BorderSize = 1;
        okButton->FlatAppearance->BorderColor = Color::FromArgb(0, 80, 150);
        okButton->FlatAppearance->MouseOverBackColor = Color::FromArgb(0, 140, 255);
        okButton->Click += gcnew EventHandler(this, &CustomInputDialog::OkButton_Click);
        this->Controls->Add(okButton);

        cancelButton = gcnew Button();
        cancelButton->Text = "Cancel";
        cancelButton->Font = gcnew Drawing::Font("Segoe UI", 11, FontStyle::Bold);
        cancelButton->Location = Point(260, 120);
        cancelButton->Width = 100;
        cancelButton->Height = 40;
        cancelButton->BackColor = Color::FromArgb(255, 80, 80);
        cancelButton->ForeColor = Color::White;
        cancelButton->FlatStyle = FlatStyle::Flat;
        cancelButton->FlatAppearance->BorderSize = 1;
        cancelButton->FlatAppearance->BorderColor = Color::FromArgb(200, 50, 50);
        cancelButton->FlatAppearance->MouseOverBackColor = Color::FromArgb(255, 100, 100);
        cancelButton->Click += gcnew EventHandler(this, &CustomInputDialog::CancelButton_Click);
        this->Controls->Add(cancelButton);

        this->AcceptButton = okButton;
        this->CancelButton = cancelButton;
    }

    void OkButton_Click(Object^ sender, EventArgs^ e)
    {
        this->DialogResult = System::Windows::Forms::DialogResult::OK;
        this->Close();
    }

    void CancelButton_Click(Object^ sender, EventArgs^ e)
    {
        this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
        this->Close();
    }
};

public ref class ReceiptPreviewDialog : public Form
{
private:
    TextBox^ previewTextBox;
    Button^ closeButton;

public:
    ReceiptPreviewDialog(String^ receiptText)
    {
        this->Text = "Receipt Preview";
        this->Width = 500;
        this->Height = 600;
        this->BackColor = Color::FromArgb(40, 40, 40);
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
        this->MaximizeBox = false;
        this->StartPosition = FormStartPosition::CenterParent;
        this->Padding = Windows::Forms::Padding(20);

        previewTextBox = gcnew TextBox();
        previewTextBox->Multiline = true;
        previewTextBox->ReadOnly = true;
        previewTextBox->ScrollBars = ScrollBars::Vertical;
        previewTextBox->Location = Point(20, 20);
        previewTextBox->Width = 440;
        previewTextBox->Height = 450;
        previewTextBox->BackColor = Color::FromArgb(60, 60, 60);
        previewTextBox->ForeColor = Color::FromArgb(245, 245, 245);
        previewTextBox->Font = gcnew Drawing::Font("Consolas", 12);
        previewTextBox->Text = receiptText;
        previewTextBox->Paint += gcnew PaintEventHandler(this, &ReceiptPreviewDialog::OnTextBoxPaint);
        this->Controls->Add(previewTextBox);

        closeButton = gcnew Button();
        closeButton->Text = "Close";
        closeButton->Font = gcnew Drawing::Font("Segoe UI", 11, FontStyle::Bold);
        closeButton->Location = Point(340, 500);
        closeButton->Width = 120;
        closeButton->Height = 40;
        closeButton->BackColor = Color::FromArgb(255, 80, 80);
        closeButton->ForeColor = Color::White;
        closeButton->FlatStyle = FlatStyle::Flat;
        closeButton->FlatAppearance->BorderSize = 1;
        closeButton->FlatAppearance->BorderColor = Color::FromArgb(200, 50, 50);
        closeButton->FlatAppearance->MouseOverBackColor = Color::FromArgb(255, 100, 100);
        closeButton->Click += gcnew EventHandler(this, &ReceiptPreviewDialog::CloseButton_Click);
        this->Controls->Add(closeButton);

        this->CancelButton = closeButton;
    }

private:
    void OnTextBoxPaint(Object^ sender, PaintEventArgs^ e)
    {
        TextBox^ tb = safe_cast<TextBox^>(sender);
        Graphics^ g = e->Graphics;
        Rectangle rect = Rectangle(tb->Location.X - 2, tb->Location.Y - 2, tb->Width + 4, tb->Height + 4);
        Pen^ borderPen = gcnew Pen(Color::FromArgb(0, 120, 215), 2);
        g->SmoothingMode = SmoothingMode::AntiAlias;

        GraphicsPath^ path = gcnew GraphicsPath();
        int radius = 10;
        path->AddArc(rect.X, rect.Y, radius, radius, 180, 90);
        path->AddArc(rect.Width - radius, rect.Y, radius, radius, 270, 90);
        path->AddArc(rect.Width - radius, rect.Height - radius, radius, radius, 0, 90);
        path->AddArc(rect.X, rect.Height - radius, radius, radius, 90, 90);
        path->CloseFigure();

        g->DrawPath(borderPen, path);
    }

    void CloseButton_Click(Object^ sender, EventArgs^ e)
    {
        this->Close();
    }
};

public ref class ReceiptForm : public Form
{
private:
    Button^ newCustomerBtn;
    Button^ oldCustomerBtn;
    Button^ previewReceiptBtn;
    TextBox^ customerNameTextBox;
    TextBox^ customerPhoneTextBox;
    Label^ customerNameLabel;
    Label^ customerPhoneLabel;
    TextBox^ searchBox;
    DataGridView^ productsGrid;
    DataGridView^ receiptGrid;
    Button^ purchaseBtn;
    Button^ clearReceiptBtn;
    TextBox^ receiptTextBox;
    Button^ printBtn;
    Label^ totalLabel;
    Label^ separator;
    Panel^ mainPanel;
    TextBox^ notesTextBox;
    Button^ addNoteBtn;
    ProgressBar^ loadingBar;
    CheckBox^ repeatCustomerCheckBox;
    Timer^ loadingTimer;
    int loadingProgress;
    double totalPrice = 0.0;

    Color originalNewCustomerBtnBackColor;
    Color originalOldCustomerBtnBackColor;
    Color originalPurchaseBtnBackColor;
    Color originalClearReceiptBtnBackColor;
    Color originalPrintBtnBackColor;
    Color originalPreviewReceiptBtnBackColor;

public:
    ReceiptForm()
    {
        InitializeComponent();
    }

private:
    void InitializeComponent()
    {
        this->Text = "Receipt Management";
        this->Width = 1200;
        this->Height = 900;
        this->BackColor = Color::FromArgb(40, 40, 40);
        this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Sizable;
        this->MaximizeBox = true;
        this->StartPosition = FormStartPosition::CenterScreen;
        this->Padding = Windows::Forms::Padding(10);
        this->Font = gcnew Drawing::Font("Segoe UI", 11);

        // Main Panel
        mainPanel = gcnew Panel();
        mainPanel->AutoScroll = true;
        mainPanel->Dock = DockStyle::Fill;
        mainPanel->BackColor = Color::FromArgb(40, 40, 40);
        mainPanel->Padding = Windows::Forms::Padding(20);
        this->Controls->Add(mainPanel);

        // Title Label
        Label^ titleLabel = gcnew Label();
        titleLabel->Text = "Receipt Management";
        titleLabel->Font = gcnew System::Drawing::Font("Segoe UI", 14, FontStyle::Bold);
        titleLabel->ForeColor = Color::FromArgb(245, 245, 245);
        titleLabel->AutoSize = true;
        titleLabel->Location = Point(20, 20);
        titleLabel->Paint += gcnew PaintEventHandler(this, &ReceiptForm::TitleLabel_Paint);
        mainPanel->Controls->Add(titleLabel);

        // Search Box
        searchBox = gcnew TextBox();
        searchBox->Top = 60;
        searchBox->Left = 20;
        searchBox->Width = 400;
        searchBox->BackColor = Color::FromArgb(60, 60, 60);
        searchBox->ForeColor = Color::FromArgb(245, 245, 245);
        searchBox->BorderStyle = BorderStyle::FixedSingle;
        searchBox->Font = gcnew Drawing::Font("Segoe UI", 11);
        searchBox->TextChanged += gcnew EventHandler(this, &ReceiptForm::OnSearchTextChanged);
        mainPanel->Controls->Add(searchBox);

        // Products Grid
        productsGrid = gcnew DataGridView();
        productsGrid->Top = 100;
        productsGrid->Left = 20;
        productsGrid->Width = 1080;
        productsGrid->Height = 350;
        productsGrid->BackgroundColor = Color::FromArgb(40, 40, 40);
        productsGrid->DefaultCellStyle->BackColor = Color::FromArgb(60, 60, 60);
        productsGrid->DefaultCellStyle->ForeColor = Color::FromArgb(245, 245, 245);
        productsGrid->AlternatingRowsDefaultCellStyle->BackColor = Color::FromArgb(50, 50, 50);
        productsGrid->ColumnHeadersDefaultCellStyle->BackColor = Color::FromArgb(0, 120, 215);
        productsGrid->ColumnHeadersDefaultCellStyle->ForeColor = Color::White;
        productsGrid->EnableHeadersVisualStyles = false;
        productsGrid->DefaultCellStyle->SelectionBackColor = Color::FromArgb(0, 140, 255);
        productsGrid->DefaultCellStyle->SelectionForeColor = Color::White;
        productsGrid->RowHeadersVisible = false;
        productsGrid->CellBorderStyle = DataGridViewCellBorderStyle::Single;
        productsGrid->GridColor = Color::FromArgb(80, 80, 80);
        productsGrid->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::EnableResizing;
        productsGrid->ColumnHeadersHeight = 45;
        productsGrid->ColumnHeadersDefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
        productsGrid->RowTemplate->Height = 35;
        productsGrid->Font = gcnew System::Drawing::Font("Segoe UI", 10);
        productsGrid->AllowUserToAddRows = false;
        productsGrid->ReadOnly = true;
        productsGrid->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
        productsGrid->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
        productsGrid->AllowUserToResizeColumns = true;
        productsGrid->ScrollBars = ScrollBars::Both;
        productsGrid->CellContentClick += gcnew DataGridViewCellEventHandler(this, &ReceiptForm::OnProductGridCellClick);
        productsGrid->MouseMove += gcnew MouseEventHandler(this, &ReceiptForm::Grid_MouseMove);
        mainPanel->Controls->Add(productsGrid);

        // Receipt Grid
        receiptGrid = gcnew DataGridView();
        receiptGrid->Top = 460;
        receiptGrid->Left = 20;
        receiptGrid->Width = 1080;
        receiptGrid->Height = 300;
        receiptGrid->BackgroundColor = Color::FromArgb(40, 40, 40);
        receiptGrid->DefaultCellStyle->BackColor = Color::FromArgb(60, 60, 60);
        receiptGrid->DefaultCellStyle->ForeColor = Color::FromArgb(245, 245, 245);
        receiptGrid->AlternatingRowsDefaultCellStyle->BackColor = Color::FromArgb(50, 50, 50);
        receiptGrid->ColumnHeadersDefaultCellStyle->BackColor = Color::FromArgb(0, 120, 215);
        receiptGrid->ColumnHeadersDefaultCellStyle->ForeColor = Color::White;
        receiptGrid->EnableHeadersVisualStyles = false;
        receiptGrid->DefaultCellStyle->SelectionBackColor = Color::FromArgb(0, 140, 255);
        receiptGrid->DefaultCellStyle->SelectionForeColor = Color::White;
        receiptGrid->RowHeadersVisible = false;
        receiptGrid->CellBorderStyle = DataGridViewCellBorderStyle::Single;
        receiptGrid->GridColor = Color::FromArgb(80, 80, 80);
        receiptGrid->ColumnHeadersHeightSizeMode = DataGridViewColumnHeadersHeightSizeMode::EnableResizing;
        receiptGrid->ColumnHeadersHeight = 45;
        receiptGrid->ColumnHeadersDefaultCellStyle->Alignment = DataGridViewContentAlignment::MiddleCenter;
        receiptGrid->RowTemplate->Height = 35;
        receiptGrid->Font = gcnew System::Drawing::Font("Segoe UI", 10);
        receiptGrid->AllowUserToAddRows = false;
        receiptGrid->ReadOnly = true;
        receiptGrid->SelectionMode = DataGridViewSelectionMode::FullRowSelect;
        receiptGrid->AutoSizeColumnsMode = DataGridViewAutoSizeColumnsMode::Fill;
        receiptGrid->AllowUserToResizeColumns = true;
        receiptGrid->ScrollBars = ScrollBars::Both;
        receiptGrid->CellContentClick += gcnew DataGridViewCellEventHandler(this, &ReceiptForm::OnReceiptGridCellClick);
        receiptGrid->MouseMove += gcnew MouseEventHandler(this, &ReceiptForm::Grid_MouseMove);
        receiptGrid->Columns->Add("ID", "ID");
        receiptGrid->Columns->Add("Name", "Name");
        receiptGrid->Columns->Add("Price", "Price");
        receiptGrid->Columns->Add("Remove", "Remove");
        mainPanel->Controls->Add(receiptGrid);

        // Loading Bar
        loadingBar = gcnew ProgressBar();
        loadingBar->Location = Point(20, 770);
        loadingBar->Width = 200;
        loadingBar->Height = 20;
        loadingBar->Visible = false;
        mainPanel->Controls->Add(loadingBar);

        // Separator
        separator = gcnew Label();
        separator->BackColor = Color::FromArgb(0, 120, 215);
        separator->Height = 2;
        separator->Width = 1080;
        separator->Location = Point(20, 800);
        mainPanel->Controls->Add(separator);

        // Customer Section
        customerNameLabel = gcnew Label();
        customerNameLabel->Text = "Customer Name:";
        customerNameLabel->ForeColor = Color::FromArgb(245, 245, 245);
        customerNameLabel->Location = Point(20, 820);
        customerNameLabel->Width = 120;
        mainPanel->Controls->Add(customerNameLabel);

        customerNameTextBox = gcnew TextBox();
        customerNameTextBox->Location = Point(150, 820);
        customerNameTextBox->Width = 250;
        customerNameTextBox->BackColor = Color::FromArgb(60, 60, 60);
        customerNameTextBox->ForeColor = Color::FromArgb(245, 245, 245);
        customerNameTextBox->BorderStyle = BorderStyle::FixedSingle;
        customerNameTextBox->Font = gcnew Drawing::Font("Segoe UI", 11);
        customerNameTextBox->ReadOnly = true;
        mainPanel->Controls->Add(customerNameTextBox);

        customerPhoneLabel = gcnew Label();
        customerPhoneLabel->Text = "Customer Phone:";
        customerPhoneLabel->ForeColor = Color::FromArgb(245, 245, 245);
        customerPhoneLabel->Location = Point(20, 850);
        customerPhoneLabel->Width = 120;
        mainPanel->Controls->Add(customerPhoneLabel);

        customerPhoneTextBox = gcnew TextBox();
        customerPhoneTextBox->Location = Point(150, 850);
        customerPhoneTextBox->Width = 250;
        customerPhoneTextBox->BackColor = Color::FromArgb(60, 60, 60);
        customerPhoneTextBox->ForeColor = Color::FromArgb(245, 245, 245);
        customerPhoneTextBox->BorderStyle = BorderStyle::FixedSingle;
        customerPhoneTextBox->Font = gcnew Drawing::Font("Segoe UI", 11);
        customerPhoneTextBox->ReadOnly = true;
        customerPhoneTextBox->KeyPress += gcnew KeyPressEventHandler(this, &ReceiptForm::CustomerPhoneTextBox_KeyPress);
        mainPanel->Controls->Add(customerPhoneTextBox);

        // Repeat Customer CheckBox
        repeatCustomerCheckBox = gcnew CheckBox();
        repeatCustomerCheckBox->Text = "Repeat Customer (5% Discount)";
        repeatCustomerCheckBox->ForeColor = Color::FromArgb(245, 245, 245);
        repeatCustomerCheckBox->Location = Point(150, 880);
        repeatCustomerCheckBox->Width = 250;
        repeatCustomerCheckBox->CheckedChanged += gcnew EventHandler(this, &ReceiptForm::RepeatCustomerCheckBox_CheckedChanged);
        mainPanel->Controls->Add(repeatCustomerCheckBox);

        // Total Label
        totalLabel = gcnew Label();
        totalLabel->Text = "Total: 0.00 L.E";
        totalLabel->ForeColor = Color::FromArgb(245, 245, 245);
        totalLabel->Font = gcnew Drawing::Font("Segoe UI", 12, FontStyle::Bold);
        totalLabel->Location = Point(20, 910);
        totalLabel->Width = 250;
        mainPanel->Controls->Add(totalLabel);

        // Customer Buttons (Top Row)
        newCustomerBtn = gcnew Button();
        newCustomerBtn->Text = "New Customer";
        newCustomerBtn->Font = gcnew Drawing::Font("Segoe UI", 12, FontStyle::Bold);
        newCustomerBtn->Location = Point(420, 820);
        newCustomerBtn->Width = 150;
        newCustomerBtn->Height = 40;
        SetupButtonGradient(newCustomerBtn);
        originalNewCustomerBtnBackColor = newCustomerBtn->BackColor;
        newCustomerBtn->Click += gcnew EventHandler(this, &ReceiptForm::NewCustomerBtn_Click);
        ToolTip^ newCustomerToolTip = gcnew ToolTip();
        newCustomerToolTip->SetToolTip(newCustomerBtn, "Add a new customer");
        mainPanel->Controls->Add(newCustomerBtn);

        oldCustomerBtn = gcnew Button();
        oldCustomerBtn->Text = "Old Customer";
        oldCustomerBtn->Font = gcnew Drawing::Font("Segoe UI", 12, FontStyle::Bold);
        oldCustomerBtn->Location = Point(580, 820);
        oldCustomerBtn->Width = 150;
        oldCustomerBtn->Height = 40;
        SetupButtonGradient(oldCustomerBtn);
        originalOldCustomerBtnBackColor = oldCustomerBtn->BackColor;
        oldCustomerBtn->Click += gcnew EventHandler(this, &ReceiptForm::OldCustomerBtn_Click);
        ToolTip^ oldCustomerToolTip = gcnew ToolTip();
        oldCustomerToolTip->SetToolTip(oldCustomerBtn, "Select an existing customer");
        mainPanel->Controls->Add(oldCustomerBtn);

        previewReceiptBtn = gcnew Button();
        previewReceiptBtn->Text = "Preview Receipt";
        previewReceiptBtn->Font = gcnew Drawing::Font("Segoe UI", 12, FontStyle::Bold);
        previewReceiptBtn->Location = Point(740, 820);
        previewReceiptBtn->Width = 150;
        previewReceiptBtn->Height = 40;
        SetupButtonGradient(previewReceiptBtn);
        originalPreviewReceiptBtnBackColor = previewReceiptBtn->BackColor;
        previewReceiptBtn->Click += gcnew EventHandler(this, &ReceiptForm::PreviewReceiptBtn_Click);
        ToolTip^ previewToolTip = gcnew ToolTip();
        previewToolTip->SetToolTip(previewReceiptBtn, "Preview the receipt");
        mainPanel->Controls->Add(previewReceiptBtn);

        purchaseBtn = gcnew Button();
        purchaseBtn->Text = "Purchase";
        purchaseBtn->Font = gcnew Drawing::Font("Segoe UI", 12, FontStyle::Bold);
        purchaseBtn->Location = Point(420, 870);
        purchaseBtn->Width = 150;
        purchaseBtn->Height = 40;
        SetupButtonGradient(purchaseBtn);
        originalPurchaseBtnBackColor = purchaseBtn->BackColor;
        purchaseBtn->Click += gcnew EventHandler(this, &ReceiptForm::Purchase);
        ToolTip^ purchaseToolTip = gcnew ToolTip();
        purchaseToolTip->SetToolTip(purchaseBtn, "Complete the purchase");
        mainPanel->Controls->Add(purchaseBtn);

        clearReceiptBtn = gcnew Button();
        clearReceiptBtn->Text = "Clear Receipt";
        clearReceiptBtn->Font = gcnew Drawing::Font("Segoe UI", 12, FontStyle::Bold);
        clearReceiptBtn->Location = Point(580, 870);
        clearReceiptBtn->Width = 150;
        clearReceiptBtn->Height = 40;
        clearReceiptBtn->BackColor = Color::FromArgb(255, 80, 80);
        clearReceiptBtn->ForeColor = Color::White;
        clearReceiptBtn->FlatStyle = FlatStyle::Flat;
        clearReceiptBtn->FlatAppearance->BorderSize = 1;
        clearReceiptBtn->FlatAppearance->BorderColor = Color::FromArgb(200, 50, 50);
        clearReceiptBtn->FlatAppearance->MouseOverBackColor = Color::FromArgb(255, 100, 100);
        originalClearReceiptBtnBackColor = clearReceiptBtn->BackColor;
        clearReceiptBtn->Click += gcnew EventHandler(this, &ReceiptForm::ClearReceipt);
        ToolTip^ clearToolTip = gcnew ToolTip();
        clearToolTip->SetToolTip(clearReceiptBtn, "Clear the current receipt");
        mainPanel->Controls->Add(clearReceiptBtn);

        printBtn = gcnew Button();
        printBtn->Text = "Print";
        printBtn->Font = gcnew Drawing::Font("Segoe UI", 12, FontStyle::Bold);
        printBtn->Location = Point(740, 870);
        printBtn->Width = 150;
        printBtn->Height = 40;
        SetupButtonGradient(printBtn);
        originalPrintBtnBackColor = printBtn->BackColor;
        printBtn->Click += gcnew EventHandler(this, &ReceiptForm::PrintReceipt);
        ToolTip^ printToolTip = gcnew ToolTip();
        printToolTip->SetToolTip(printBtn, "Print the receipt");
        mainPanel->Controls->Add(printBtn);

        // Notes TextBox
        notesTextBox = gcnew TextBox();
        notesTextBox->Location = Point(20, 940);
        notesTextBox->Width = 250;
        notesTextBox->BackColor = Color::FromArgb(60, 60, 60);
        notesTextBox->ForeColor = Color::FromArgb(245, 245, 245);
        notesTextBox->BorderStyle = BorderStyle::FixedSingle;
        notesTextBox->Font = gcnew Drawing::Font("Segoe UI", 11);
        mainPanel->Controls->Add(notesTextBox);

        // Add Note Button
        addNoteBtn = gcnew Button();
        addNoteBtn->Text = "Add Note";
        addNoteBtn->Font = gcnew Drawing::Font("Segoe UI", 12, FontStyle::Bold);
        addNoteBtn->Location = Point(280, 940);
        addNoteBtn->Width = 120;
        addNoteBtn->Height = 30;
        SetupButtonGradient(addNoteBtn);
        addNoteBtn->Click += gcnew EventHandler(this, &ReceiptForm::AddNoteBtn_Click);
        mainPanel->Controls->Add(addNoteBtn);

        // Receipt TextBox
        receiptTextBox = gcnew TextBox();
        receiptTextBox->Multiline = true;
        receiptTextBox->ReadOnly = true;
        receiptTextBox->ScrollBars = ScrollBars::Vertical;
        receiptTextBox->Top = 980;
        receiptTextBox->Left = 20;
        receiptTextBox->Width = 1080;
        receiptTextBox->Height = 120;
        receiptTextBox->BackColor = Color::FromArgb(60, 60, 60);
        receiptTextBox->ForeColor = Color::FromArgb(245, 245, 245);
        receiptTextBox->Font = gcnew Drawing::Font("Consolas", 12);
        receiptTextBox->Paint += gcnew PaintEventHandler(this, &ReceiptForm::ReceiptTextBox_Paint);
        mainPanel->Controls->Add(receiptTextBox);

        // Initialize loading timer
        loadingTimer = gcnew Timer();
        loadingTimer->Interval = 100;
        loadingTimer->Tick += gcnew EventHandler(this, &ReceiptForm::LoadingBarTimer_Tick);

        // Resize event
        this->Resize += gcnew EventHandler(this, &ReceiptForm::OnResize);

        LoadProducts("");
    }

    void SetupButtonGradient(Button^ btn)
    {
        btn->BackColor = Color::FromArgb(0, 120, 215);
        btn->ForeColor = Color::White;
        btn->FlatStyle = FlatStyle::Flat;
        btn->FlatAppearance->BorderSize = 1;
        btn->FlatAppearance->BorderColor = Color::FromArgb(0, 80, 150);
        btn->FlatAppearance->MouseOverBackColor = Color::FromArgb(0, 140, 255);
        btn->Paint += gcnew PaintEventHandler(this, &ReceiptForm::Button_Paint);
    }

    void Button_Paint(Object^ sender, PaintEventArgs^ e)
    {
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

    void TitleLabel_Paint(Object^ sender, PaintEventArgs^ e)
    {
        Label^ label = safe_cast<Label^>(sender);
        e->Graphics->TextRenderingHint = System::Drawing::Text::TextRenderingHint::AntiAlias;
        PointF textPos = PointF(label->Location.X, label->Location.Y);
        e->Graphics->DrawString(label->Text, label->Font, gcnew SolidBrush(Color::FromArgb(100, 0, 0, 0)), PointF(textPos.X + 2, textPos.Y + 2));
        e->Graphics->DrawString(label->Text, label->Font, gcnew SolidBrush(label->ForeColor), textPos);
    }

    void ReceiptTextBox_Paint(Object^ sender, PaintEventArgs^ e)
    {
        TextBox^ tb = safe_cast<TextBox^>(sender);
        Graphics^ g = e->Graphics;
        Rectangle rect = Rectangle(tb->Location.X - 2, tb->Location.Y - 2, tb->Width + 4, tb->Height + 4);
        Pen^ borderPen = gcnew Pen(Color::FromArgb(0, 120, 215), 2);
        g->SmoothingMode = SmoothingMode::AntiAlias;

        GraphicsPath^ path = gcnew GraphicsPath();
        int radius = 10;
        path->AddArc(rect.X, rect.Y, radius, radius, 180, 90);
        path->AddArc(rect.Width - radius, rect.Y, radius, radius, 270, 90);
        path->AddArc(rect.Width - radius, rect.Height - radius, radius, radius, 0, 90);
        path->AddArc(rect.X, rect.Height - radius, radius, radius, 90, 90);
        path->CloseFigure();

        g->DrawPath(borderPen, path);
    }

    void OnResize(Object^ sender, EventArgs^ e)
    {
        int newWidth = mainPanel->ClientSize.Width - 40;
        productsGrid->Width = newWidth;
        receiptGrid->Width = newWidth;
        receiptTextBox->Width = newWidth;
        separator->Width = newWidth;
    }

    void OnSearchTextChanged(Object^ sender, EventArgs^ e)
    {
        ShowLoadingBar();
        LoadProducts(searchBox->Text);
    }

    void ShowLoadingBar()
    {
        loadingBar->Visible = true;
        loadingBar->Value = 0;
        loadingProgress = 0;
        loadingTimer->Start();
    }

    void LoadingBarTimer_Tick(Object^ sender, EventArgs^ e)
    {
        loadingProgress += 10;
        loadingBar->Value = loadingProgress;
        if (loadingProgress >= 100)
        {
            loadingBar->Visible = false;
            loadingTimer->Stop();
        }
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
        addBtn->Text = "Add";
        addBtn->UseColumnTextForButtonValue = true;
        addBtn->DefaultCellStyle->BackColor = Color::FromArgb(0, 120, 215);
        addBtn->DefaultCellStyle->ForeColor = Color::White;
        productsGrid->Columns->Add(addBtn);

        for each (Product ^ p in products)
        {
            productsGrid->Rows->Add(p->Id, p->Name, p->Price);
        }
    }

    void OnProductGridCellClick(Object^ sender, DataGridViewCellEventArgs^ e)
    {
        if (e->RowIndex >= 0 && e->ColumnIndex == 3)
        {
            int productId = Convert::ToInt32(productsGrid->Rows[e->RowIndex]->Cells[0]->Value);
            Product^ p = ProductDBHelper::GetProductById(productId);
            if (p)
            {
                double price = p->Price;
                if (repeatCustomerCheckBox->Checked)
                    price *= 0.95;

                receiptGrid->Rows->Add(p->Id, p->Name, price);
                DataGridViewButtonCell^ removeBtn = gcnew DataGridViewButtonCell();
                removeBtn->Value = "Remove";
                removeBtn->Style->BackColor = Color::FromArgb(255, 80, 80);
                removeBtn->Style->ForeColor = Color::White;
                receiptGrid->Rows[receiptGrid->Rows->Count - 1]->Cells["Remove"] = removeBtn;

                totalPrice += price;
                totalLabel->Text = "Total: " + totalPrice.ToString("F2") + " L.E";
            }
        }
    }

    void OnReceiptGridCellClick(Object^ sender, DataGridViewCellEventArgs^ e)
    {
        if (e->RowIndex >= 0 && e->ColumnIndex == 3)
        {
            double price = Convert::ToDouble(receiptGrid->Rows[e->RowIndex]->Cells[2]->Value);
            receiptGrid->Rows->RemoveAt(e->RowIndex);
            totalPrice -= price;
            totalLabel->Text = "Total: " + totalPrice.ToString("F2") + " L.E";
            receiptTextBox->Text = "";
        }
    }

    void Grid_MouseMove(Object^ sender, MouseEventArgs^ e)
    {
        DataGridView^ grid = safe_cast<DataGridView^>(sender);
        DataGridView::HitTestInfo^ hit = grid->HitTest(e->X, e->Y);
        if (hit->RowIndex >= 0)
        {
            grid->Rows[hit->RowIndex]->DefaultCellStyle->BackColor = Color::FromArgb(0, 140, 255);
        }
        for each (DataGridViewRow ^ row in grid->Rows)
        {
            if (row->Index != hit->RowIndex)
            {
                row->DefaultCellStyle->BackColor = row->Index % 2 == 0 ? Color::FromArgb(60, 60, 60) : Color::FromArgb(50, 50, 50);
            }
        }
    }

    void CustomerPhoneTextBox_KeyPress(Object^ sender, KeyPressEventArgs^ e)
    {
        if (!Char::IsDigit(e->KeyChar) && e->KeyChar != '\b')
        {
            e->Handled = true;
        }
    }

    void RepeatCustomerCheckBox_CheckedChanged(Object^ sender, EventArgs^ e)
    {
        if (receiptGrid->Rows->Count > 0)
        {
            MessageBox::Show("Discount can only be applied before adding items.", "Warning");
            repeatCustomerCheckBox->Checked = false;
        }
    }

    void NewCustomerBtn_Click(Object^ sender, EventArgs^ e)
    {
        String^ name = CustomInputDialog::Show("Enter customer's name:", "New Customer", "");
        String^ phone = CustomInputDialog::Show("Enter customer's phone number:", "New Customer", "");
        if (!String::IsNullOrWhiteSpace(name) && !String::IsNullOrWhiteSpace(phone))
        {
            customerNameTextBox->Text = name;
            customerPhoneTextBox->Text = phone;
        }
        else
        {
            MessageBox::Show("Name or Phone cannot be empty.", "Error");
        }
    }

    void OldCustomerBtn_Click(Object^ sender, EventArgs^ e)
    {
        String^ phone = CustomInputDialog::Show("Enter customer's phone number:", "Old Customer", "");
        if (!String::IsNullOrWhiteSpace(phone))
        {
            Sale^ existingCustomer = Sale::GetByCustomerPhone(phone);
            if (existingCustomer != nullptr)
            {
                customerNameTextBox->Text = existingCustomer->CustomerName;
                customerPhoneTextBox->Text = phone;
                repeatCustomerCheckBox->Checked = true;
            }
            else
            {
                MessageBox::Show("Customer not found.", "Error");
            }
        }
        else
        {
            MessageBox::Show("Phone number cannot be empty.", "Error");
        }
    }

    void PreviewReceiptBtn_Click(Object^ sender, EventArgs^ e)
    {
        if (receiptGrid->Rows->Count == 0)
        {
            MessageBox::Show("No items in the receipt to preview!", "Error");
            return;
        }

        String^ customerName = customerNameTextBox->Text;
        String^ customerPhone = customerPhoneTextBox->Text;

        if (String::IsNullOrWhiteSpace(customerName) || String::IsNullOrWhiteSpace(customerPhone))
        {
            MessageBox::Show("Please select a customer (New or Old).", "Error");
            return;
        }

        String^ receiptText = GenerateReceiptText(0, customerName, customerPhone);
        ReceiptPreviewDialog^ previewDialog = gcnew ReceiptPreviewDialog(receiptText);
        previewDialog->ShowDialog();
    }

    void Purchase(Object^ sender, EventArgs^ e)
    {
        if (receiptGrid->Rows->Count == 0)
        {
            MessageBox::Show("No items in the receipt!", "Error");
            return;
        }

        String^ customerName = customerNameTextBox->Text;
        String^ customerPhone = customerPhoneTextBox->Text;

        if (String::IsNullOrWhiteSpace(customerName) || String::IsNullOrWhiteSpace(customerPhone))
        {
            MessageBox::Show("Please select a customer (New or Old).", "Error");
            return;
        }

        String^ input = CustomInputDialog::Show("Enter cash amount (L.E): ", "Payment", "0");
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

        String^ receiptText = GenerateReceiptText(userCash, customerName, customerPhone);
        receiptTextBox->Text = receiptText;

        Sale^ newSale = gcnew Sale();
        newSale->Total = totalPrice;
        newSale->Date = DateTime::Now.ToString();
        newSale->CustomerPhone = customerPhone;
        newSale->CustomerName = customerName;
        int saleId = Sale::Add(newSale);

        for each (DataGridViewRow ^ row in receiptGrid->Rows)
        {
            if (row->IsNewRow) continue;

            SaleItem^ item = gcnew SaleItem();
            item->SaleId = saleId;
            item->ProductId = Convert::ToInt32(row->Cells[0]->Value);
            item->Quantity = 1;
            item->total_price = Convert::ToDouble(row->Cells[2]->Value);

            SaleItem::Add(item);
        }

        receiptGrid->Rows->Clear();
        totalPrice = 0.0;
        totalLabel->Text = "Total: " + totalPrice.ToString("F2") + " L.E";
        notesTextBox->Text = "";
    }

    void ClearReceipt(Object^ sender, EventArgs^ e)
    {
        receiptGrid->Rows->Clear();
        totalPrice = 0.0;
        totalLabel->Text = "Total: " + totalPrice.ToString("F2") + " L.E";
        receiptTextBox->Text = "";
        customerNameTextBox->Text = "";
        customerPhoneTextBox->Text = "";
        notesTextBox->Text = "";
        repeatCustomerCheckBox->Checked = false;
    }

    void AddNoteBtn_Click(Object^ sender, EventArgs^ e)
    {
        if (!String::IsNullOrWhiteSpace(notesTextBox->Text))
        {
            MessageBox::Show("Note added: " + notesTextBox->Text, "Success");
        }
        else
        {
            MessageBox::Show("Please enter a note.", "Error");
        }
    }

    void PrintReceipt(Object^ sender, EventArgs^ e)
    {
        if (String::IsNullOrEmpty(receiptTextBox->Text))
        {
            MessageBox::Show("No receipt to print.", "Error");
            return;
        }

        ShowLoadingBar();
        System::Drawing::Printing::PrintDocument^ printDoc = gcnew System::Drawing::Printing::PrintDocument();
        printDoc->PrintPage += gcnew System::Drawing::Printing::PrintPageEventHandler(this, &ReceiptForm::OnPrintPage);

        PrintDialog^ printDialog = gcnew PrintDialog();
        printDialog->Document = printDoc;
        if (printDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
        {
            printDoc->Print();
        }
    }

    void OnPrintPage(Object^ sender, System::Drawing::Printing::PrintPageEventArgs^ e)
    {
        e->Graphics->DrawString(receiptTextBox->Text, gcnew System::Drawing::Font("Consolas", 12),
            Brushes::Black, PointF(100, 100));
    }

    String^ GenerateReceiptText(double userCash, String^ customerName, String^ customerPhone)
    {
        String^ receiptText = "";
        receiptText += "========================================\r\n";
        receiptText += "|         PHARMACY RECEIPT             |\r\n";
        receiptText += "========================================\r\n";
        receiptText += "Date     : " + DateTime::Now.ToString("yyyy-MM-dd HH:mm:ss") + "\r\n";
        receiptText += "Customer : " + customerName + "\r\n";
        receiptText += "Phone    : " + customerPhone + "\r\n";
        if (!String::IsNullOrWhiteSpace(notesTextBox->Text))
            receiptText += "Note     : " + notesTextBox->Text + "\r\n";
        receiptText += "----------------------------------------\r\n";
        receiptText += String::Format("{0,-20}{1,15}\r\n", "Item", "Price (L.E)");
        receiptText += "----------------------------------------\r\n";

        for each (DataGridViewRow ^ row in receiptGrid->Rows)
        {
            if (row->IsNewRow) continue;

            String^ item = row->Cells[1]->Value->ToString();
            String^ price = row->Cells[2]->Value->ToString();
            receiptText += String::Format("{0,-20}{1,15}\r\n", item, price);
        }

        receiptText += "----------------------------------------\r\n";
        receiptText += String::Format("{0,-20}{1,15:F2} L.E\r\n", "Total:", totalPrice);
        if (userCash > 0)
        {
            receiptText += String::Format("{0,-20}{1,15:F2} L.E\r\n", "Paid:", userCash);
            receiptText += String::Format("{0,-20}{1,15:F2} L.E\r\n", "Change:", (userCash - totalPrice));
        }
        if (repeatCustomerCheckBox->Checked)
            receiptText += "Discount : 5% applied for repeat customer\r\n";
        receiptText += "========================================\r\n";
        receiptText += "        Thank you for your visit!       \r\n";
        receiptText += "========================================\r\n";

        return receiptText;
    }
};