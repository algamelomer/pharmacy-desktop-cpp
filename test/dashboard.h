#pragma once

namespace test {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Drawing::Drawing2D;

    public ref class Dashboard : public System::Windows::Forms::Form
    {
    public:
        Dashboard(void)
        {
            InitializeComponent();
            SetupHoverEffects();
        }

    protected:
        ~Dashboard()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::Panel^ mainPanel;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::PictureBox^ pictureBox1;
    private: System::Windows::Forms::Panel^ panel1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::PictureBox^ pictureBox3;
    private: System::Windows::Forms::Panel^ panel4;
    private: System::Windows::Forms::PictureBox^ pictureBox2;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::Panel^ panel3;
    private: System::Windows::Forms::Panel^ panel5;
    private: System::Windows::Forms::PictureBox^ pictureBox4;
    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::Panel^ panel2;

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Dashboard::typeid));
            this->mainPanel = (gcnew System::Windows::Forms::Panel());
            this->panel2 = (gcnew System::Windows::Forms::Panel());
            this->panel5 = (gcnew System::Windows::Forms::Panel());
            this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->panel4 = (gcnew System::Windows::Forms::Panel());
            this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->panel3 = (gcnew System::Windows::Forms::Panel());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->panel3 = (gcnew System::Windows::Forms::Panel());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
            this->panel2->SuspendLayout();
            this->panel5->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
            this->panel4->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
            this->panel1->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->panel3->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
            this->SuspendLayout();
            // 
            // mainPanel
            // 
            this->mainPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(40)));
            this->mainPanel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->mainPanel->Location = System::Drawing::Point(0, 0);
            this->mainPanel->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->mainPanel->Name = L"mainPanel";
            this->mainPanel->Padding = System::Windows::Forms::Padding(0, 146, 0, 0);
            this->mainPanel->Size = System::Drawing::Size(826, 457);
            this->mainPanel->TabIndex = 0;
            this->mainPanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Dashboard::mainPanel_Paint);
            // 
            // panel2
            // 
            this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
                static_cast<System::Int32>(static_cast<System::Byte>(75)));
            this->panel2->Controls->Add(this->panel5);
            this->panel2->Controls->Add(this->panel4);
            this->panel2->Controls->Add(this->panel1);
            this->panel2->Controls->Add(this->panel3);
            this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
            this->panel2->Location = System::Drawing::Point(0, 0);
            this->panel2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->panel2->Name = L"panel2";
            this->panel2->Size = System::Drawing::Size(826, 146);
            this->panel2->TabIndex = 1;
            this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Dashboard::panel2_Paint);
            // 
            // panel5
            // 
            this->panel5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(75)),
                static_cast<System::Int32>(static_cast<System::Byte>(90)));
            this->panel5->Controls->Add(this->pictureBox4);
            this->panel5->Controls->Add(this->label4);
            this->panel5->Cursor = System::Windows::Forms::Cursors::Hand;
            this->panel5->Location = System::Drawing::Point(0, 0);
            this->panel5->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->panel5->Name = L"panel5";
            this->panel5->Padding = System::Windows::Forms::Padding(8, 8, 8, 8);
            this->panel5->Size = System::Drawing::Size(150, 130);
            this->panel5->TabIndex = 3;
            this->panel5->Click += gcnew System::EventHandler(this, &Dashboard::panel5_Click);
            this->panel5->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Dashboard::panel_Paint);
            this->panel5->MouseEnter += gcnew System::EventHandler(this, &Dashboard::panel_MouseEnter);
            this->panel5->MouseLeave += gcnew System::EventHandler(this, &Dashboard::panel_MouseLeave);
            // 
            // pictureBox4
            // 
            this->pictureBox4->Dock = System::Windows::Forms::DockStyle::Top;
            this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
            this->pictureBox4->Location = System::Drawing::Point(8, 8);
            this->pictureBox4->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->pictureBox4->Name = L"pictureBox4";
            this->pictureBox4->Size = System::Drawing::Size(134, 81);
            this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox4->TabIndex = 2;
            this->pictureBox4->TabStop = false;
            this->pictureBox4->Click += gcnew System::EventHandler(this, &Dashboard::panel5_Click);
            this->pictureBox4->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Dashboard::pictureBox_Paint);
            this->pictureBox4->MouseEnter += gcnew System::EventHandler(this, &Dashboard::panel_MouseEnter);
            this->pictureBox4->MouseLeave += gcnew System::EventHandler(this, &Dashboard::panel_MouseLeave);
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label4->ForeColor = System::Drawing::Color::White;
            this->label4->Location = System::Drawing::Point(33, 94); // Centered: (150 - 83) / 2 = 33
            this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(83, 26);
            this->label4->TabIndex = 1;
            this->label4->Text = L"Return";
            this->label4->Click += gcnew System::EventHandler(this, &Dashboard::panel5_Click);
            this->label4->MouseEnter += gcnew System::EventHandler(this, &Dashboard::panel_MouseEnter);
            this->label4->MouseLeave += gcnew System::EventHandler(this, &Dashboard::panel_MouseLeave);
            // 
            // panel4
            // 
            this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(75)),
                static_cast<System::Int32>(static_cast<System::Byte>(90)));
            this->panel4->Controls->Add(this->pictureBox3);
            this->panel4->Controls->Add(this->label2);
            this->panel4->Cursor = System::Windows::Forms::Cursors::Hand;
            this->panel4->Location = System::Drawing::Point(0, 0);
            this->panel4->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->panel4->Name = L"panel4";
            this->panel4->Padding = System::Windows::Forms::Padding(8, 8, 8, 8);
            this->panel4->Size = System::Drawing::Size(150, 130);
            this->panel4->TabIndex = 2;
            this->panel4->Click += gcnew System::EventHandler(this, &Dashboard::panel4_Click);
            this->panel4->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Dashboard::panel_Paint);
            this->panel4->MouseEnter += gcnew System::EventHandler(this, &Dashboard::panel_MouseEnter);
            this->panel4->MouseLeave += gcnew System::EventHandler(this, &Dashboard::panel_MouseLeave);
            // 
            // pictureBox3
            // 
            this->pictureBox3->Dock = System::Windows::Forms::DockStyle::Top;
            this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
            this->pictureBox3->Location = System::Drawing::Point(8, 8);
            this->pictureBox3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->pictureBox3->Name = L"pictureBox3";
            this->pictureBox3->Size = System::Drawing::Size(134, 81);
            this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox3->TabIndex = 2;
            this->pictureBox3->TabStop = false;
            this->pictureBox3->Click += gcnew System::EventHandler(this, &Dashboard::panel4_Click);
            this->pictureBox3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Dashboard::pictureBox_Paint);
            this->pictureBox3->MouseEnter += gcnew System::EventHandler(this, &Dashboard::panel_MouseEnter);
            this->pictureBox3->MouseLeave += gcnew System::EventHandler(this, &Dashboard::panel_MouseLeave);
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label2->ForeColor = System::Drawing::Color::White;
            this->label2->Location = System::Drawing::Point(20, 94); // Centered: (150 - 110) / 2 = 20
            this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(110, 26);
            this->label2->TabIndex = 1;
            this->label2->Text = L"Inventory";
            this->label2->Click += gcnew System::EventHandler(this, &Dashboard::panel4_Click);
            this->label2->MouseEnter += gcnew System::EventHandler(this, &Dashboard::panel_MouseEnter);
            this->label2->MouseLeave += gcnew System::EventHandler(this, &Dashboard::panel_MouseLeave);
            // 
            // panel1
            // 
            this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(75)),
                static_cast<System::Int32>(static_cast<System::Byte>(90)));
            this->panel1->Controls->Add(this->pictureBox1);
            this->panel1->Controls->Add(this->label1);
            this->panel1->Cursor = System::Windows::Forms::Cursors::Hand;
            this->panel1->Location = System::Drawing::Point(0, 0);
            this->panel1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->panel1->Name = L"panel1";
            this->panel1->Padding = System::Windows::Forms::Padding(8, 8, 8, 8);
            this->panel1->Size = System::Drawing::Size(150, 130);
            this->panel1->TabIndex = 1;
            this->panel1->Click += gcnew System::EventHandler(this, &Dashboard::panel1_Click);
            this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Dashboard::panel_Paint);
            this->panel1->MouseEnter += gcnew System::EventHandler(this, &Dashboard::panel_MouseEnter);
            this->panel1->MouseLeave += gcnew System::EventHandler(this, &Dashboard::panel_MouseLeave);
            // 
            // pictureBox1
            // 
            this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Top;
            this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
            this->pictureBox1->InitialImage = nullptr;
            this->pictureBox1->Location = System::Drawing::Point(8, 8);
            this->pictureBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(134, 81);
            this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox1->TabIndex = 1;
            this->pictureBox1->TabStop = false;
            this->pictureBox1->Click += gcnew System::EventHandler(this, &Dashboard::panel1_Click);
            this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Dashboard::pictureBox_Paint);
            this->pictureBox1->MouseEnter += gcnew System::EventHandler(this, &Dashboard::panel_MouseEnter);
            this->pictureBox1->MouseLeave += gcnew System::EventHandler(this, &Dashboard::panel_MouseLeave);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->ForeColor = System::Drawing::Color::White;
            this->label1->Location = System::Drawing::Point(21, 94); // Centered: (150 - 108) / 2 = 21
            this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(108, 26);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Category";
            this->label1->Click += gcnew System::EventHandler(this, &Dashboard::panel1_Click);
            this->label1->MouseEnter += gcnew System::EventHandler(this, &Dashboard::panel_MouseEnter);
            this->label1->MouseLeave += gcnew System::EventHandler(this, &Dashboard::panel_MouseLeave);
            // 
            // panel3
            // 
            this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(60)), static_cast<System::Int32>(static_cast<System::Byte>(75)),
                static_cast<System::Int32>(static_cast<System::Byte>(90)));
            this->panel3->Controls->Add(this->label3);
            this->panel3->Controls->Add(this->pictureBox2);
            this->panel3->Cursor = System::Windows::Forms::Cursors::Hand;
            this->panel3->Location = System::Drawing::Point(0, 0);
            this->panel3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->panel3->Name = L"panel3";
            this->panel3->Padding = System::Windows::Forms::Padding(8, 8, 8, 8);
            this->panel3->Size = System::Drawing::Size(150, 130);
            this->panel3->TabIndex = 2;
            this->panel3->Click += gcnew System::EventHandler(this, &Dashboard::panel3_Click);
            this->panel3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Dashboard::panel_Paint);
            this->panel3->MouseEnter += gcnew System::EventHandler(this, &Dashboard::panel_MouseEnter);
            this->panel3->MouseLeave += gcnew System::EventHandler(this, &Dashboard::panel_MouseLeave);
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label3->ForeColor = System::Drawing::Color::White;
            this->label3->Location = System::Drawing::Point(25, 94); // Centered: (150 - 100) / 2 = 25
            this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(100, 26);
            this->label3->TabIndex = 1;
            this->label3->Text = L"Supplier";
            this->label3->Click += gcnew System::EventHandler(this, &Dashboard::panel3_Click);
            this->label3->MouseEnter += gcnew System::EventHandler(this, &Dashboard::panel_MouseEnter);
            this->label3->MouseLeave += gcnew System::EventHandler(this, &Dashboard::panel_MouseLeave);
            // 
            // pictureBox2
            // 
            this->pictureBox2->Dock = System::Windows::Forms::DockStyle::Top;
            this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
            this->pictureBox2->Location = System::Drawing::Point(8, 8);
            this->pictureBox2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->pictureBox2->Name = L"pictureBox2";
            this->pictureBox2->Size = System::Drawing::Size(134, 81);
            this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pictureBox2->TabIndex = 2;
            this->pictureBox2->TabStop = false;
            this->pictureBox2->Click += gcnew System::EventHandler(this, &Dashboard::panel3_Click);
            this->pictureBox2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Dashboard::pictureBox_Paint);
            this->pictureBox2->MouseEnter += gcnew System::EventHandler(this, &Dashboard::panel_MouseEnter);
            this->pictureBox2->MouseLeave += gcnew System::EventHandler(this, &Dashboard::panel_MouseLeave);
            // 
            // Dashboard
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(40)));
            this->ClientSize = System::Drawing::Size(826, 457);
            this->Controls->Add(this->panel2);
            this->Controls->Add(this->mainPanel);
            this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->MinimumSize = System::Drawing::Size(679, 414);
            this->Name = L"Dashboard";
            this->Text = L"Dashboard";
            this->Load += gcnew System::EventHandler(this, &Dashboard::Dashboard_Load);
            this->panel2->ResumeLayout(false);
            this->panel5->ResumeLayout(false);
            this->panel5->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
            this->panel4->ResumeLayout(false);
            this->panel4->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
            this->panel1->ResumeLayout(false);
            this->panel1->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->panel3->ResumeLayout(false);
            this->panel3->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
            this->ResumeLayout(false);

        }
#pragma endregion

    private: System::Void Dashboard_Load(System::Object^ sender, System::EventArgs^ e) {
        this->panel2->Resize += gcnew System::EventHandler(this, &Dashboard::panel2_Resize);
        this->MinimumSize = System::Drawing::Size(900, 500);
        ArrangePanels();
    }

    private: void ArrangePanels() {
        int panel2Width = this->panel2->Width;
        int panel2Height = this->panel2->Height;
        int panelWidth = 150; // Updated to match panel size
        int panelHeight = 130;
        int spacing = 40;
        int totalWidth = 4 * panelWidth + 3 * spacing;
        int startX = (panel2Width - totalWidth) / 2;

        this->panel3->Location = System::Drawing::Point(startX, (panel2Height - panelHeight) / 2);
        this->panel4->Location = System::Drawing::Point(startX + panelWidth + spacing, (panel2Height - panelHeight) / 2);
        this->panel5->Location = System::Drawing::Point(startX + 2 * (panelWidth + spacing), (panel2Height - panelHeight) / 2);
        this->panel1->Location = System::Drawing::Point(startX + 3 * (panelWidth + spacing), (panel2Height - panelHeight) / 2);
    }

    private: System::Void panel2_Resize(System::Object^ sender, System::EventArgs^ e) {
        ArrangePanels();
    }

    private: void SetupHoverEffects() {
        this->panel1->Tag = gcnew array<Object^> { this->panel1->BackColor, this->panel1->Size };
        this->panel3->Tag = gcnew array<Object^> { this->panel3->BackColor, this->panel3->Size };
        this->panel4->Tag = gcnew array<Object^> { this->panel4->BackColor, this->panel4->Size };
        this->panel5->Tag = gcnew array<Object^> { this->panel5->BackColor, this->panel5->Size };

        System::Windows::Forms::ToolTip^ toolTip = gcnew System::Windows::Forms::ToolTip();
        toolTip->SetToolTip(this->panel1, L"Manage product categories");
        toolTip->SetToolTip(this->panel3, L"Manage suppliers");
        toolTip->SetToolTip(this->panel4, L"View and manage inventory");
        toolTip->SetToolTip(this->panel5, L"Handle product returns");
    }

    private: System::Void panel_MouseEnter(System::Object^ sender, System::EventArgs^ e) {
        Control^ control = dynamic_cast<Control^>(sender);
        Panel^ targetPanel = nullptr;
        if (control == this->panel1 || control == this->label1 || control == this->pictureBox1)
            targetPanel = this->panel1;
        else if (control == this->panel3 || control == this->label3 || control == this->pictureBox2)
            targetPanel = this->panel3;
        else if (control == this->panel4 || control == this->label2 || control == this->pictureBox3)
            targetPanel = this->panel4;
        else if (control == this->panel5 || control == this->label4 || control == this->pictureBox4)
            targetPanel = this->panel5;

        if (targetPanel != nullptr) {
            targetPanel->BackColor = System::Drawing::Color::FromArgb(90, 105, 120);
        }
    }

    private: System::Void panel_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
        Control^ control = dynamic_cast<Control^>(sender);
        Panel^ targetPanel = nullptr;
        if (control == this->panel1 || control == this->label1 || control == this->pictureBox1)
            targetPanel = this->panel1;
        else if (control == this->panel3 || control == this->label3 || control == this->pictureBox2)
            targetPanel = this->panel3;
        else if (control == this->panel4 || control == this->label2 || control == this->pictureBox3)
            targetPanel = this->panel4;
        else if (control == this->panel5 || control == this->label4 || control == this->pictureBox4)
            targetPanel = this->panel5;

        if (targetPanel != nullptr) {
            array<Object^>^ tag = dynamic_cast<array<Object^>^>(targetPanel->Tag);
            targetPanel->BackColor = *dynamic_cast<System::Drawing::Color^>(tag[0]);
        }
    }

    private: System::Void panel1_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void panel3_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void panel4_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void panel5_Click(System::Object^ sender, System::EventArgs^ e);

    private: System::Void mainPanel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
        System::Drawing::Rectangle rect = mainPanel->ClientRectangle;
        LinearGradientBrush^ brush = gcnew LinearGradientBrush(rect,
            System::Drawing::Color::FromArgb(20, 30, 40),
            System::Drawing::Color::FromArgb(50, 65, 80),
            LinearGradientMode::Vertical);
        e->Graphics->FillRectangle(brush, rect);
    }

    private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
        Control^ control = dynamic_cast<Control^>(sender);
        e->Graphics->DrawRectangle(gcnew System::Drawing::Pen(System::Drawing::Color::FromArgb(100, 115, 130), 2.0f), 0.0f, 0.0f, control->Width - 1.0f, control->Height - 1.0f);
    }

    private: System::Void panel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
        System::Windows::Forms::Panel^ panel = dynamic_cast<System::Windows::Forms::Panel^>(sender);
        e->Graphics->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;
        System::Drawing::Rectangle rect = System::Drawing::Rectangle(4, 4, panel->Width - 8, panel->Height - 8);
        float radius = 20.0f; // Increased from 15.0f for smoother corners
        System::Drawing::Drawing2D::GraphicsPath^ path = gcnew System::Drawing::Drawing2D::GraphicsPath();
        path->AddArc(static_cast<float>(rect.X), static_cast<float>(rect.Y), radius, radius, 180.0f, 90.0f);
        path->AddArc(static_cast<float>(rect.Width - radius), static_cast<float>(rect.Y), radius, radius, 270.0f, 90.0f);
        path->AddArc(static_cast<float>(rect.Width - radius), static_cast<float>(rect.Height - radius), radius, radius, 0.0f, 90.0f);
        path->AddArc(static_cast<float>(rect.X), static_cast<float>(rect.Height - radius), radius, radius, 90.0f, 90.0f);
        path->CloseAllFigures();
        panel->Region = gcnew System::Drawing::Region(path);

        System::Drawing::Drawing2D::GraphicsPath^ shadowPath = gcnew System::Drawing::Drawing2D::GraphicsPath();
        shadowPath->AddArc(static_cast<float>(rect.X + 2), static_cast<float>(rect.Y + 2), radius, radius, 180.0f, 90.0f);
        shadowPath->AddArc(static_cast<float>(rect.Width - radius + 2), static_cast<float>(rect.Y + 2), radius, radius, 270.0f, 90.0f);
        shadowPath->AddArc(static_cast<float>(rect.Width - radius + 2), static_cast<float>(rect.Height - radius + 2), radius, radius, 0.0f, 90.0f);
        shadowPath->AddArc(static_cast<float>(rect.X + 2), static_cast<float>(rect.Height - radius + 2), radius, radius, 90.0f, 90.0f);
        shadowPath->CloseAllFigures();
        e->Graphics->FillPath(gcnew System::Drawing::SolidBrush(System::Drawing::Color::FromArgb(50, 0, 0, 0)), shadowPath);

        e->Graphics->FillPath(gcnew System::Drawing::SolidBrush(panel->BackColor), path);
        e->Graphics->DrawPath(gcnew System::Drawing::Pen(System::Drawing::Color::FromArgb(20, 20, 20), 1.5f), path);
    }

    private: System::Void pictureBox_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
        System::Windows::Forms::PictureBox^ pb = dynamic_cast<System::Windows::Forms::PictureBox^>(sender);
        e->Graphics->DrawRectangle(gcnew System::Drawing::Pen(System::Drawing::Color::White, 2.0f), 2.0f, 2.0f, pb->Width - 5.0f, pb->Height - 5.0f);
    }

    private: void LoadUserControl(System::Windows::Forms::UserControl^ userControl);
    };
}