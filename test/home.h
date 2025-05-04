#pragma once
#include "productsearchform.h"
#include "dashboard.h"

namespace test {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Drawing::Drawing2D;

    /// <summary>
    /// نموذج رئيسي بتصميم عصري باستخدام اللون #2E2E2E مع لوجو صيدلية
    /// </summary>
    public ref class home : public System::Windows::Forms::Form
    {
    private:
        System::Windows::Forms::Timer^ sidebarTimer;
        // إضافة لوجو الصيدلية
        int sidebarTargetWidth;
        bool sidebarExpanded;
        Color darkColor = Color::FromArgb(46, 46, 46); // #2E2E2E
        Color lightDarkColor = Color::FromArgb(70, 70, 70);
        Color accentColor = Color::FromArgb(70, 130, 180);

    public:
        home(void)
        {
            InitializeComponent();
            InitializeAnimations();
            ApplyModernStyling();
        }

    protected:
        ~home()
        {
            if (components)
            {
                delete components;
            }
            if (sidebarTimer) delete sidebarTimer;
        }

    private:
        System::Windows::Forms::Panel^ add_item_panel;
        System::Windows::Forms::Label^ label3;
        System::Windows::Forms::PictureBox^ pictureBox3;
        System::Windows::Forms::Panel^ Home_panel;
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::PictureBox^ pictureBox1;
        System::Windows::Forms::Panel^ Remove_item_panel;
        System::Windows::Forms::Label^ label2;
        System::Windows::Forms::PictureBox^ pictureBox2;
        System::Windows::Forms::Panel^ dashboard_panel;
        System::Windows::Forms::Label^ label6;
        System::Windows::Forms::PictureBox^ pictureBox6;
        System::Windows::Forms::Panel^ Menu_panel;
        System::Windows::Forms::Label^ label5;
        System::Windows::Forms::PictureBox^ pictureBox5;
        System::Windows::Forms::Panel^ search_item_panel;
        System::Windows::Forms::Label^ label4;
        System::Windows::Forms::PictureBox^ pictureBox4;
        System::Windows::Forms::Panel^ logout_panel;
        System::Windows::Forms::Label^ label7;
        System::Windows::Forms::PictureBox^ pictureBox7;
        System::Windows::Forms::Panel^ sidebar_panel_container;
        System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
        System::Windows::Forms::Panel^ content_panel;
        System::ComponentModel::Container^ components;

        void InitializeAnimations()
        {
            sidebarTimer = gcnew System::Windows::Forms::Timer();
            sidebarTimer->Interval = 10;
            sidebarTimer->Tick += gcnew EventHandler(this, &home::sidebarTimer_Tick);
            sidebarExpanded = true;
            sidebarTargetWidth = 250;
        }

        void ApplyModernStyling()
        {
            this->BackColor = darkColor;
            this->ForeColor = Color::White;
            this->Font = gcnew System::Drawing::Font("Segoe UI", 12.0F, FontStyle::Regular, GraphicsUnit::Point, static_cast<Byte>(0));
            this->Text = "Pharmacy Management System";
            this->FormBorderStyle = FormBorderStyle::FixedSingle;
            this->MaximizeBox = false;
            this->StartPosition = FormStartPosition::CenterScreen;

            sidebar_panel_container->BackColor = Color::FromArgb(30, 30, 30);
            flowLayoutPanel1->BackColor = Color::FromArgb(30, 30, 30);

            logoPictureBox->BackColor = Color::FromArgb(30, 30, 30);
            logoPictureBox->SizeMode = PictureBoxSizeMode::StretchImage;
            logoPictureBox->BorderStyle = BorderStyle::None;

            content_panel->BackColor = darkColor;
            content_panel->Paint += gcnew PaintEventHandler(this, &home::ContentPanel_Paint);

            for each(Control ^ control in flowLayoutPanel1->Controls)
            {
                if (control->GetType() == Panel::typeid)
                {
                    Panel^ panel = safe_cast<Panel^>(control);
                    panel->BackColor = Color::Transparent;
                    panel->ForeColor = Color::White;
                    panel->Padding = System::Windows::Forms::Padding(15, 15, 15, 15);
                    panel->Margin = System::Windows::Forms::Padding(5);
                    panel->MouseEnter += gcnew EventHandler(this, &home::Panel_MouseEnter);
                    panel->MouseLeave += gcnew EventHandler(this, &home::Panel_MouseLeave);

                    for each(Control ^ subControl in panel->Controls)
                    {
                        if (subControl->GetType() == Label::typeid)
                        {
                            Label^ label = safe_cast<Label^>(subControl);
                            label->ForeColor = Color::WhiteSmoke;
                            label->Font = gcnew System::Drawing::Font("Segoe UI Semibold", 12.5F, FontStyle::Bold);
                            label->TextAlign = ContentAlignment::MiddleLeft;
                        }
                        else if (subControl->GetType() == PictureBox::typeid)
                        {
                            PictureBox^ picBox = safe_cast<PictureBox^>(subControl);
                            picBox->SizeMode = PictureBoxSizeMode::StretchImage;
                            picBox->BackColor = Color::Transparent;
                        }
                    }
                }
            }

            logout_panel->BackColor = Color::FromArgb(40, 40, 40);
            logout_panel->ForeColor = Color::LightCoral;
        }

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(home::typeid));
            this->add_item_panel = (gcnew System::Windows::Forms::Panel());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
            this->Home_panel = (gcnew System::Windows::Forms::Panel());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->Remove_item_panel = (gcnew System::Windows::Forms::Panel());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
            this->search_item_panel = (gcnew System::Windows::Forms::Panel());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
            this->Menu_panel = (gcnew System::Windows::Forms::Panel());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
            this->dashboard_panel = (gcnew System::Windows::Forms::Panel());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
            this->logout_panel = (gcnew System::Windows::Forms::Panel());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
            this->sidebar_panel_container = (gcnew System::Windows::Forms::Panel());
            this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
            this->content_panel = (gcnew System::Windows::Forms::Panel());
            this->add_item_panel->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
            this->Home_panel->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->Remove_item_panel->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
            this->search_item_panel->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
            this->Menu_panel->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
            this->dashboard_panel->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
            this->logout_panel->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
            this->sidebar_panel_container->SuspendLayout();
            this->flowLayoutPanel1->SuspendLayout();
            this->SuspendLayout();
            // 
            // add_item_panel
            // 
            this->add_item_panel->Controls->Add(this->label3);
            this->add_item_panel->Controls->Add(this->pictureBox3);
            this->add_item_panel->Cursor = System::Windows::Forms::Cursors::Hand;
            this->add_item_panel->Location = System::Drawing::Point(2, 112);
            this->add_item_panel->Margin = System::Windows::Forms::Padding(2, 2, 2, 4);
            this->add_item_panel->Name = L"add_item_panel";
            this->add_item_panel->Size = System::Drawing::Size(205, 49);
            this->add_item_panel->TabIndex = 2;
            this->add_item_panel->Click += gcnew System::EventHandler(this, &home::add_item_panel_Click);
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->BackColor = System::Drawing::Color::Transparent;
            this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(40, 15);
            this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(80, 23);
            this->label3->TabIndex = 1;
            this->label3->Text = L"Add item";
            this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->label3->Click += gcnew System::EventHandler(this, &home::add_item_panel_Click);
            // 
            // pictureBox3
            // 
            this->pictureBox3->BackColor = System::Drawing::Color::Transparent;
            this->pictureBox3->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
            this->pictureBox3->Location = System::Drawing::Point(8, 8);
            this->pictureBox3->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->pictureBox3->Name = L"pictureBox3";
            this->pictureBox3->Size = System::Drawing::Size(28, 30);
            this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox3->TabIndex = 0;
            this->pictureBox3->TabStop = false;
            this->pictureBox3->Click += gcnew System::EventHandler(this, &home::add_item_panel_Click);
            // 
            // Home_panel
            // 
            this->Home_panel->Controls->Add(this->label1);
            this->Home_panel->Controls->Add(this->pictureBox1);
            this->Home_panel->Cursor = System::Windows::Forms::Cursors::Hand;
            this->Home_panel->Location = System::Drawing::Point(2, 2);
            this->Home_panel->Margin = System::Windows::Forms::Padding(2, 2, 2, 4);
            this->Home_panel->Name = L"Home_panel";
            this->Home_panel->Size = System::Drawing::Size(205, 49);
            this->Home_panel->TabIndex = 3;
            this->Home_panel->Click += gcnew System::EventHandler(this, &home::Home_panel_Click);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->BackColor = System::Drawing::Color::Transparent;
            this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(40, 15);
            this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(57, 23);
            this->label1->TabIndex = 1;
            this->label1->Text = L"Home";
            this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->label1->Click += gcnew System::EventHandler(this, &home::Home_panel_Click);
            // 
            // pictureBox1
            // 
            this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
            this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
            this->pictureBox1->Location = System::Drawing::Point(8, 8);
            this->pictureBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(28, 30);
            this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox1->TabIndex = 0;
            this->pictureBox1->TabStop = false;
            this->pictureBox1->Click += gcnew System::EventHandler(this, &home::Home_panel_Click);
            // 
            // Remove_item_panel
            // 
            this->Remove_item_panel->Controls->Add(this->label2);
            this->Remove_item_panel->Controls->Add(this->pictureBox2);
            this->Remove_item_panel->Cursor = System::Windows::Forms::Cursors::Hand;
            this->Remove_item_panel->Location = System::Drawing::Point(2, 167);
            this->Remove_item_panel->Margin = System::Windows::Forms::Padding(2, 2, 2, 4);
            this->Remove_item_panel->Name = L"Remove_item_panel";
            this->Remove_item_panel->Size = System::Drawing::Size(205, 49);
            this->Remove_item_panel->TabIndex = 4;
            this->Remove_item_panel->Click += gcnew System::EventHandler(this, &home::Remove_item_panel_Click);
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->BackColor = System::Drawing::Color::Transparent;
            this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(40, 15);
            this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(112, 23);
            this->label2->TabIndex = 1;
            this->label2->Text = L"Remove item";
            this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->label2->Click += gcnew System::EventHandler(this, &home::Remove_item_panel_Click);
            // 
            // pictureBox2
            // 
            this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
            this->pictureBox2->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
            this->pictureBox2->Location = System::Drawing::Point(8, 8);
            this->pictureBox2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->pictureBox2->Name = L"pictureBox2";
            this->pictureBox2->Size = System::Drawing::Size(28, 30);
            this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox2->TabIndex = 0;
            this->pictureBox2->TabStop = false;
            this->pictureBox2->Click += gcnew System::EventHandler(this, &home::Remove_item_panel_Click);
            // 
            // search_item_panel
            // 
            this->search_item_panel->Controls->Add(this->label4);
            this->search_item_panel->Controls->Add(this->pictureBox4);
            this->search_item_panel->Cursor = System::Windows::Forms::Cursors::Hand;
            this->search_item_panel->Location = System::Drawing::Point(2, 222);
            this->search_item_panel->Margin = System::Windows::Forms::Padding(2, 2, 2, 4);
            this->search_item_panel->Name = L"search_item_panel";
            this->search_item_panel->Size = System::Drawing::Size(205, 53);
            this->search_item_panel->TabIndex = 5;
            this->search_item_panel->Click += gcnew System::EventHandler(this, &home::search_item_panel_Click);
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->BackColor = System::Drawing::Color::Transparent;
            this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label4->Location = System::Drawing::Point(41, 15);
            this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(100, 23);
            this->label4->TabIndex = 1;
            this->label4->Text = L"Search item";
            this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->label4->Click += gcnew System::EventHandler(this, &home::search_item_panel_Click);
            // 
            // pictureBox4
            // 
            this->pictureBox4->BackColor = System::Drawing::Color::Transparent;
            this->pictureBox4->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
            this->pictureBox4->Location = System::Drawing::Point(8, 8);
            this->pictureBox4->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->pictureBox4->Name = L"pictureBox4";
            this->pictureBox4->Size = System::Drawing::Size(28, 30);
            this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox4->TabIndex = 0;
            this->pictureBox4->TabStop = false;
            this->pictureBox4->Click += gcnew System::EventHandler(this, &home::search_item_panel_Click);
            // 
            // Menu_panel
            // 
            this->Menu_panel->BackColor = System::Drawing::Color::Transparent;
            this->Menu_panel->Controls->Add(this->label5);
            this->Menu_panel->Controls->Add(this->pictureBox5);
            this->Menu_panel->Cursor = System::Windows::Forms::Cursors::Hand;
            this->Menu_panel->Location = System::Drawing::Point(2, 57);
            this->Menu_panel->Margin = System::Windows::Forms::Padding(2, 2, 2, 4);
            this->Menu_panel->Name = L"Menu_panel";
            this->Menu_panel->Size = System::Drawing::Size(205, 49);
            this->Menu_panel->TabIndex = 5;
            this->Menu_panel->Click += gcnew System::EventHandler(this, &home::Menu_panel_Click);
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->BackColor = System::Drawing::Color::Transparent;
            this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label5->Location = System::Drawing::Point(40, 13);
            this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(62, 25);
            this->label5->TabIndex = 1;
            this->label5->Text = L"Menu";
            this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->label5->Click += gcnew System::EventHandler(this, &home::Menu_panel_Click);
            // 
            // pictureBox5
            // 
            this->pictureBox5->BackColor = System::Drawing::Color::Transparent;
            this->pictureBox5->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
            this->pictureBox5->Location = System::Drawing::Point(8, 8);
            this->pictureBox5->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->pictureBox5->Name = L"pictureBox5";
            this->pictureBox5->Size = System::Drawing::Size(28, 30);
            this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox5->TabIndex = 0;
            this->pictureBox5->TabStop = false;
            this->pictureBox5->Click += gcnew System::EventHandler(this, &home::Menu_panel_Click);
            // 
            // dashboard_panel
            // 
            this->dashboard_panel->Controls->Add(this->label6);
            this->dashboard_panel->Controls->Add(this->pictureBox6);
            this->dashboard_panel->Cursor = System::Windows::Forms::Cursors::Hand;
            this->dashboard_panel->Location = System::Drawing::Point(2, 281);
            this->dashboard_panel->Margin = System::Windows::Forms::Padding(2, 2, 2, 4);
            this->dashboard_panel->Name = L"dashboard_panel";
            this->dashboard_panel->Size = System::Drawing::Size(205, 59);
            this->dashboard_panel->TabIndex = 5;
            this->dashboard_panel->Click += gcnew System::EventHandler(this, &home::dashboard_panel_Click);
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->BackColor = System::Drawing::Color::Transparent;
            this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label6->Location = System::Drawing::Point(41, 19);
            this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(93, 23);
            this->label6->TabIndex = 1;
            this->label6->Text = L"Dashboard";
            this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->label6->Click += gcnew System::EventHandler(this, &home::dashboard_panel_Click);
            // 
            // pictureBox6
            // 
            this->pictureBox6->BackColor = System::Drawing::Color::Transparent;
            this->pictureBox6->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
            this->pictureBox6->Location = System::Drawing::Point(6, 12);
            this->pictureBox6->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->pictureBox6->Name = L"pictureBox6";
            this->pictureBox6->Size = System::Drawing::Size(28, 30);
            this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox6->TabIndex = 0;
            this->pictureBox6->TabStop = false;
            this->pictureBox6->Click += gcnew System::EventHandler(this, &home::dashboard_panel_Click);
            // 
            // logout_panel
            // 
            this->logout_panel->Controls->Add(this->label7);
            this->logout_panel->Controls->Add(this->pictureBox7);
            this->logout_panel->Cursor = System::Windows::Forms::Cursors::Hand;
            this->logout_panel->Dock = System::Windows::Forms::DockStyle::Bottom;
            this->logout_panel->Location = System::Drawing::Point(0, 509);
            this->logout_panel->Margin = System::Windows::Forms::Padding(2, 2, 2, 4);
            this->logout_panel->Name = L"logout_panel";
            this->logout_panel->Size = System::Drawing::Size(211, 57);
            this->logout_panel->TabIndex = 6;
            this->logout_panel->Click += gcnew System::EventHandler(this, &home::logout_panel_Click);
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->BackColor = System::Drawing::Color::Transparent;
            this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label7->ForeColor = System::Drawing::Color::LightCoral;
            this->label7->Location = System::Drawing::Point(40, 22);
            this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(64, 23);
            this->label7->TabIndex = 1;
            this->label7->Text = L"Logout";
            this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            this->label7->Click += gcnew System::EventHandler(this, &home::logout_panel_Click);
            // 
            // pictureBox7
            // 
            this->pictureBox7->BackColor = System::Drawing::Color::Transparent;
            this->pictureBox7->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.Image")));
            this->pictureBox7->Location = System::Drawing::Point(8, 15);
            this->pictureBox7->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->pictureBox7->Name = L"pictureBox7";
            this->pictureBox7->Size = System::Drawing::Size(28, 30);
            this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox7->TabIndex = 0;
            this->pictureBox7->TabStop = false;
            this->pictureBox7->Click += gcnew System::EventHandler(this, &home::logout_panel_Click);
            // 
            // sidebar_panel_container
            // 
            this->sidebar_panel_container->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
            this->sidebar_panel_container->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)),
                static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(46)));
            this->sidebar_panel_container->Controls->Add(this->flowLayoutPanel1);
            this->sidebar_panel_container->Controls->Add(this->logout_panel);
            this->sidebar_panel_container->Dock = System::Windows::Forms::DockStyle::Left;
            this->sidebar_panel_container->Location = System::Drawing::Point(0, 0);
            this->sidebar_panel_container->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->sidebar_panel_container->Name = L"sidebar_panel_container";
            this->sidebar_panel_container->Size = System::Drawing::Size(211, 566);
            this->sidebar_panel_container->TabIndex = 1;
            // 
            // flowLayoutPanel1
            // 
            this->flowLayoutPanel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(46)),
                static_cast<System::Int32>(static_cast<System::Byte>(46)));
            this->flowLayoutPanel1->Controls->Add(this->Home_panel);
            this->flowLayoutPanel1->Controls->Add(this->Menu_panel);
            this->flowLayoutPanel1->Controls->Add(this->add_item_panel);
            this->flowLayoutPanel1->Controls->Add(this->Remove_item_panel);
            this->flowLayoutPanel1->Controls->Add(this->search_item_panel);
            this->flowLayoutPanel1->Controls->Add(this->dashboard_panel);
            this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Top;
            this->flowLayoutPanel1->Location = System::Drawing::Point(0, 0);
            this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
            this->flowLayoutPanel1->Size = System::Drawing::Size(211, 366);
            this->flowLayoutPanel1->TabIndex = 0;
            // 
            // content_panel
            // 
            this->content_panel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->content_panel->Location = System::Drawing::Point(211, 0);
            this->content_panel->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->content_panel->Name = L"content_panel";
            this->content_panel->Size = System::Drawing::Size(507, 566);
            this->content_panel->TabIndex = 2;
            // 
            // home
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(718, 566);
            this->Controls->Add(this->content_panel);
            this->Controls->Add(this->sidebar_panel_container);
            this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
            this->MinimumSize = System::Drawing::Size(491, 442);
            this->Name = L"home";
            this->Text = L"Pharmacy Management System";
            this->add_item_panel->ResumeLayout(false);
            this->add_item_panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
            this->Home_panel->ResumeLayout(false);
            this->Home_panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->Remove_item_panel->ResumeLayout(false);
            this->Remove_item_panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
            this->search_item_panel->ResumeLayout(false);
            this->search_item_panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
            this->Menu_panel->ResumeLayout(false);
            this->Menu_panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
            this->dashboard_panel->ResumeLayout(false);
            this->dashboard_panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
            this->logout_panel->ResumeLayout(false);
            this->logout_panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
            this->sidebar_panel_container->ResumeLayout(false);
            this->flowLayoutPanel1->ResumeLayout(false);
            this->ResumeLayout(false);

        }
#pragma endregion

    private:
        void ContentPanel_Paint(Object^ sender, PaintEventArgs^ e)
        {
            Graphics^ g = e->Graphics;
            Rectangle rect = this->content_panel->ClientRectangle;

            LinearGradientBrush^ brush = gcnew LinearGradientBrush(
                rect,
                Color::FromArgb(46, 46, 46),
                Color::FromArgb(70, 70, 70),
                45.0f);
            g->FillRectangle(brush, rect);
            delete brush;

            Pen^ borderPen = gcnew Pen(Color::FromArgb(80, 80, 80), 1);
            g->DrawRectangle(borderPen, 0, 0, rect.Width - 1, rect.Height - 1);
            delete borderPen;
        }

        void sidebar_panel_container_Paint(Object^ sender, PaintEventArgs^ e)
        {
            Graphics^ g = e->Graphics;
            Rectangle rect = this->sidebar_panel_container->ClientRectangle;

            LinearGradientBrush^ brush = gcnew LinearGradientBrush(
                rect,
                Color::FromArgb(30, 30, 30),
                Color::FromArgb(46, 46, 46),
                90.0f);
            g->FillRectangle(brush, rect);
            delete brush;

            Pen^ borderPen = gcnew Pen(Color::FromArgb(80, 80, 80), 1);
            g->DrawLine(borderPen, rect.Width - 1, 0, rect.Width - 1, rect.Height);
            delete borderPen;
        }

        void Panel_MouseEnter(Object^ sender, EventArgs^ e)
        {
            Panel^ panel = safe_cast<Panel^>(sender);
            panel->BackColor = accentColor;

            for each(Control ^ control in panel->Controls)
            {
                if (control->GetType() == Label::typeid)
                {
                    safe_cast<Label^>(control)->ForeColor = Color::White;
                }
                else if (control->GetType() == PictureBox::typeid)
                {
                    safe_cast<PictureBox^>(control)->BackColor = Color::FromArgb(70, 70, 70);
                }
            }
        }

        void Panel_MouseLeave(Object^ sender, EventArgs^ e)
        {
            Panel^ panel = safe_cast<Panel^>(sender);
            panel->BackColor = Color::Transparent;

            for each(Control ^ control in panel->Controls)
            {
                if (control->GetType() == Label::typeid)
                {
                    Label^ label = safe_cast<Label^>(control);
                    if (panel == logout_panel)
                        label->ForeColor = Color::LightCoral;
                    else
                        label->ForeColor = Color::WhiteSmoke;
                }
                else if (control->GetType() == PictureBox::typeid)
                {
                    safe_cast<PictureBox^>(control)->BackColor = Color::Transparent;
                }
            }
        }

        void sidebarTimer_Tick(Object^ sender, EventArgs^ e)
        {
            const int step = 10;

            if (sidebarExpanded)
            {
                if (sidebar_panel_container->Width > 70)
                {
                    sidebar_panel_container->Width -= step;
                    if (sidebar_panel_container->Width < 150)
                    {
                        ToggleSidebarLabels(false);

                    }
                }
                else
                {
                    sidebarTimer->Stop();
                }
            }
            else
            {
                if (sidebar_panel_container->Width < sidebarTargetWidth)
                {
                    sidebar_panel_container->Width += step;
                    if (sidebar_panel_container->Width > 150)
                    {
                        ToggleSidebarLabels(true);
                    }
                }
                else
                {
                    sidebarTimer->Stop();
                }
            }
        }

        void ToggleSidebarLabels(bool visible)
        {
            for each(Control ^ panel in flowLayoutPanel1->Controls)
            {
                if (panel->GetType() == Panel::typeid)
                {
                    for each(Control ^ control in panel->Controls)
                    {
                        if (control->GetType() == Label::typeid)
                        {
                            control->Visible = visible;
                        }
                    }
                }
            }

            for each(Control ^ control in logout_panel->Controls)
            {
                if (control->GetType() == Label::typeid)
                {
                    control->Visible = true;
                }
            }
        }

    private:
        System::Void Menu_panel_Click(System::Object^ sender, System::EventArgs^ e) {
            sidebarExpanded = !sidebarExpanded;
            sidebarTimer->Start();
        }

        System::Void Home_panel_Click(System::Object^ sender, System::EventArgs^ e) {
            // Add your home panel click logic here
        }

        System::Void add_item_panel_Click(System::Object^ sender, System::EventArgs^ e) {
            // Add your add item panel click logic here
        }

        System::Void Remove_item_panel_Click(System::Object^ sender, System::EventArgs^ e) {
            // Add your remove item panel click logic here
        }

        System::Void search_item_panel_Click(System::Object^ sender, System::EventArgs^ e) {
            // Add your search item panel click logic here
        }

        System::Void dashboard_panel_Click(System::Object^ sender, System::EventArgs^ e) {
            // Add your dashboard panel click logic here
        }

        System::Void logout_panel_Click(System::Object^ sender, System::EventArgs^ e) {
            Application::Exit();
        }
    };
}
