#pragma once
#include "medicine_management.h"

namespace test {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class home : public System::Windows::Forms::Form
    {
    public:
        home(void)
        {
            InitializeComponent();
        }

    protected:
        ~home()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::Panel^ Home_panel;
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::PictureBox^ pictureBox1;
    private: System::Windows::Forms::Panel^ Remove_item_panel;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::PictureBox^ pictureBox2;
    private: System::Windows::Forms::Panel^ dashboard_panel;
    private: System::Windows::Forms::Label^ label6;
    private: System::Windows::Forms::PictureBox^ pictureBox6;
    private: System::Windows::Forms::Panel^ Menu_panel;
    private: System::Windows::Forms::Label^ label5;
    private: System::Windows::Forms::PictureBox^ pictureBox5;
    private: System::Windows::Forms::Panel^ logout_panel;
    private: System::Windows::Forms::Label^ label7;
    private: System::Windows::Forms::PictureBox^ pictureBox7;
    private: System::Windows::Forms::Panel^ sidebar_panel_container;
    private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;
    private: System::Windows::Forms::Panel^ content_panel;
    private: System::Windows::Forms::Panel^ add_item_panel;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::PictureBox^ pictureBox3;
    private: System::Windows::Forms::Timer^ sidebarTimer;
    private: bool sidebarExpanded = true;
    private: int targetWidth;
    private: int animationStep = 10;

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(home::typeid));
            this->Home_panel = (gcnew System::Windows::Forms::Panel());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->Remove_item_panel = (gcnew System::Windows::Forms::Panel());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
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
            this->add_item_panel = (gcnew System::Windows::Forms::Panel());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
            this->content_panel = (gcnew System::Windows::Forms::Panel());
            this->sidebarTimer = (gcnew System::Windows::Forms::Timer());
            this->Home_panel->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->Remove_item_panel->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
            this->Menu_panel->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
            this->dashboard_panel->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
            this->logout_panel->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
            this->sidebar_panel_container->SuspendLayout();
            this->flowLayoutPanel1->SuspendLayout();
            this->add_item_panel->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
            this->SuspendLayout();
            // 
            // Home_panel
            // 
            this->Home_panel->Controls->Add(this->label1);
            this->Home_panel->Controls->Add(this->pictureBox1);
            this->Home_panel->Cursor = System::Windows::Forms::Cursors::Hand;
            this->Home_panel->Location = System::Drawing::Point(3, 102);
            this->Home_panel->Margin = System::Windows::Forms::Padding(3, 2, 3, 6);
            this->Home_panel->Name = L"Home_panel";
            this->Home_panel->Size = System::Drawing::Size(299, 92);
            this->Home_panel->TabIndex = 3;
            this->Home_panel->Click += gcnew System::EventHandler(this, &home::Home_panel_Click);
            this->Home_panel->MouseEnter += gcnew System::EventHandler(this, &home::Panel_MouseEnter);
            this->Home_panel->MouseLeave += gcnew System::EventHandler(this, &home::Panel_MouseLeave);
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->BackColor = System::Drawing::Color::Transparent;
            this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->ForeColor = System::Drawing::Color::WhiteSmoke;
            this->label1->Location = System::Drawing::Point(53, 21);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(95, 37);
            this->label1->TabIndex = 1;
            this->label1->Text = L"Home";
            this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->label1->Click += gcnew System::EventHandler(this, &home::Home_panel_Click);
            this->label1->MouseEnter += gcnew System::EventHandler(this, &home::Panel_MouseEnter);
            this->label1->MouseLeave += gcnew System::EventHandler(this, &home::Panel_MouseLeave);
            // 
            // pictureBox1
            // 
            this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
            this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
            this->pictureBox1->Location = System::Drawing::Point(9, 18);
            this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(39, 39);
            this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox1->TabIndex = 0;
            this->pictureBox1->TabStop = false;
            this->pictureBox1->Click += gcnew System::EventHandler(this, &home::Home_panel_Click);
            this->pictureBox1->MouseEnter += gcnew System::EventHandler(this, &home::Panel_MouseEnter);
            this->pictureBox1->MouseLeave += gcnew System::EventHandler(this, &home::Panel_MouseLeave);
            // 
            // Remove_item_panel
            // 
            this->Remove_item_panel->Controls->Add(this->label2);
            this->Remove_item_panel->Controls->Add(this->pictureBox2);
            this->Remove_item_panel->Cursor = System::Windows::Forms::Cursors::Hand;
            this->Remove_item_panel->Location = System::Drawing::Point(3, 202);
            this->Remove_item_panel->Margin = System::Windows::Forms::Padding(3, 2, 3, 6);
            this->Remove_item_panel->Name = L"Remove_item_panel";
            this->Remove_item_panel->Size = System::Drawing::Size(299, 92);
            this->Remove_item_panel->TabIndex = 4;
            this->Remove_item_panel->Click += gcnew System::EventHandler(this, &home::Remove_item_panel_Click);
            this->Remove_item_panel->MouseEnter += gcnew System::EventHandler(this, &home::Panel_MouseEnter);
            this->Remove_item_panel->MouseLeave += gcnew System::EventHandler(this, &home::Panel_MouseLeave);
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->BackColor = System::Drawing::Color::Transparent;
            this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label2->ForeColor = System::Drawing::Color::WhiteSmoke;
            this->label2->Location = System::Drawing::Point(53, 23);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(103, 35);
            this->label2->TabIndex = 1;
            this->label2->Text = L"Receipt";
            this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->label2->Click += gcnew System::EventHandler(this, &home::Remove_item_panel_Click);
            this->label2->MouseEnter += gcnew System::EventHandler(this, &home::Panel_MouseEnter);
            this->label2->MouseLeave += gcnew System::EventHandler(this, &home::Panel_MouseLeave);
            // 
            // pictureBox2
            // 
            this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
            this->pictureBox2->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
            this->pictureBox2->Location = System::Drawing::Point(9, 18);
            this->pictureBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->pictureBox2->Name = L"pictureBox2";
            this->pictureBox2->Size = System::Drawing::Size(39, 39);
            this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox2->TabIndex = 0;
            this->pictureBox2->TabStop = false;
            this->pictureBox2->Click += gcnew System::EventHandler(this, &home::Remove_item_panel_Click);
            this->pictureBox2->MouseEnter += gcnew System::EventHandler(this, &home::Panel_MouseEnter);
            this->pictureBox2->MouseLeave += gcnew System::EventHandler(this, &home::Panel_MouseLeave);
            // 
            // Menu_panel
            // 
            this->Menu_panel->BackColor = System::Drawing::Color::Transparent;
            this->Menu_panel->Controls->Add(this->label5);
            this->Menu_panel->Controls->Add(this->pictureBox5);
            this->Menu_panel->Cursor = System::Windows::Forms::Cursors::Hand;
            this->Menu_panel->Location = System::Drawing::Point(3, 2);
            this->Menu_panel->Margin = System::Windows::Forms::Padding(3, 2, 3, 6);
            this->Menu_panel->Name = L"Menu_panel";
            this->Menu_panel->Size = System::Drawing::Size(299, 92);
            this->Menu_panel->TabIndex = 5;
            this->Menu_panel->Click += gcnew System::EventHandler(this, &home::Menu_panel_Click);
            this->Menu_panel->MouseEnter += gcnew System::EventHandler(this, &home::Panel_MouseEnter);
            this->Menu_panel->MouseLeave += gcnew System::EventHandler(this, &home::Panel_MouseLeave);
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->BackColor = System::Drawing::Color::Transparent;
            this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label5->ForeColor = System::Drawing::Color::WhiteSmoke;
            this->label5->Location = System::Drawing::Point(63, 27);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(90, 37);
            this->label5->TabIndex = 1;
            this->label5->Text = L"Menu";
            this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->label5->Click += gcnew System::EventHandler(this, &home::Menu_panel_Click);
            this->label5->MouseEnter += gcnew System::EventHandler(this, &home::Panel_MouseEnter);
            this->label5->MouseLeave += gcnew System::EventHandler(this, &home::Panel_MouseLeave);
            // 
            // pictureBox5
            // 
            this->pictureBox5->BackColor = System::Drawing::Color::Transparent;
            this->pictureBox5->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
            this->pictureBox5->Location = System::Drawing::Point(12, 18);
            this->pictureBox5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->pictureBox5->Name = L"pictureBox5";
            this->pictureBox5->Size = System::Drawing::Size(45, 46);
            this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox5->TabIndex = 0;
            this->pictureBox5->TabStop = false;
            this->pictureBox5->Click += gcnew System::EventHandler(this, &home::Menu_panel_Click);
            this->pictureBox5->MouseEnter += gcnew System::EventHandler(this, &home::Panel_MouseEnter);
            this->pictureBox5->MouseLeave += gcnew System::EventHandler(this, &home::Panel_MouseLeave);
            // 
            // dashboard_panel
            // 
            this->dashboard_panel->Controls->Add(this->label6);
            this->dashboard_panel->Controls->Add(this->pictureBox6);
            this->dashboard_panel->Cursor = System::Windows::Forms::Cursors::Hand;
            this->dashboard_panel->Location = System::Drawing::Point(3, 402);
            this->dashboard_panel->Margin = System::Windows::Forms::Padding(3, 2, 3, 6);
            this->dashboard_panel->Name = L"dashboard_panel";
            this->dashboard_panel->Size = System::Drawing::Size(299, 92);
            this->dashboard_panel->TabIndex = 5;
            this->dashboard_panel->Click += gcnew System::EventHandler(this, &home::dashboard_panel_Click);
            this->dashboard_panel->MouseEnter += gcnew System::EventHandler(this, &home::Panel_MouseEnter);
            this->dashboard_panel->MouseLeave += gcnew System::EventHandler(this, &home::Panel_MouseLeave);
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->BackColor = System::Drawing::Color::Transparent;
            this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label6->ForeColor = System::Drawing::Color::WhiteSmoke;
            this->label6->Location = System::Drawing::Point(53, 21);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(141, 35);
            this->label6->TabIndex = 1;
            this->label6->Text = L"Dashboard";
            this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->label6->Click += gcnew System::EventHandler(this, &home::dashboard_panel_Click);
            this->label6->MouseEnter += gcnew System::EventHandler(this, &home::Panel_MouseEnter);
            this->label6->MouseLeave += gcnew System::EventHandler(this, &home::Panel_MouseLeave);
            // 
            // pictureBox6
            // 
            this->pictureBox6->BackColor = System::Drawing::Color::Transparent;
            this->pictureBox6->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
            this->pictureBox6->Location = System::Drawing::Point(9, 18);
            this->pictureBox6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->pictureBox6->Name = L"pictureBox6";
            this->pictureBox6->Size = System::Drawing::Size(39, 39);
            this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox6->TabIndex = 0;
            this->pictureBox6->TabStop = false;
            this->pictureBox6->Click += gcnew System::EventHandler(this, &home::dashboard_panel_Click);
            this->pictureBox6->MouseEnter += gcnew System::EventHandler(this, &home::Panel_MouseEnter);
            this->pictureBox6->MouseLeave += gcnew System::EventHandler(this, &home::Panel_MouseLeave);
            // 
            // logout_panel
            // 
            this->logout_panel->Controls->Add(this->label7);
            this->logout_panel->Controls->Add(this->pictureBox7);
            this->logout_panel->Cursor = System::Windows::Forms::Cursors::Hand;
            this->logout_panel->Dock = System::Windows::Forms::DockStyle::Bottom;
            this->logout_panel->Location = System::Drawing::Point(0, 672);
            this->logout_panel->Margin = System::Windows::Forms::Padding(3, 2, 3, 6);
            this->logout_panel->Name = L"logout_panel";
            this->logout_panel->Size = System::Drawing::Size(307, 92);
            this->logout_panel->TabIndex = 6;
            this->logout_panel->Click += gcnew System::EventHandler(this, &home::logout_panel_Click);
            this->logout_panel->MouseEnter += gcnew System::EventHandler(this, &home::Panel_MouseEnter);
            this->logout_panel->MouseLeave += gcnew System::EventHandler(this, &home::Panel_MouseLeave);
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->BackColor = System::Drawing::Color::Transparent;
            this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label7->ForeColor = System::Drawing::Color::WhiteSmoke;
            this->label7->Location = System::Drawing::Point(56, 25);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(109, 37);
            this->label7->TabIndex = 1;
            this->label7->Text = L"Logout";
            this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->label7->Click += gcnew System::EventHandler(this, &home::logout_panel_Click);
            this->label7->MouseEnter += gcnew System::EventHandler(this, &home::Panel_MouseEnter);
            this->label7->MouseLeave += gcnew System::EventHandler(this, &home::Panel_MouseLeave);
            // 
            // pictureBox7
            // 
            this->pictureBox7->BackColor = System::Drawing::Color::Transparent;
            this->pictureBox7->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.Image")));
            this->pictureBox7->Location = System::Drawing::Point(12, 20);
            this->pictureBox7->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->pictureBox7->Name = L"pictureBox7";
            this->pictureBox7->Size = System::Drawing::Size(39, 39);
            this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox7->TabIndex = 0;
            this->pictureBox7->TabStop = false;
            this->pictureBox7->Click += gcnew System::EventHandler(this, &home::logout_panel_Click);
            this->pictureBox7->MouseEnter += gcnew System::EventHandler(this, &home::Panel_MouseEnter);
            this->pictureBox7->MouseLeave += gcnew System::EventHandler(this, &home::Panel_MouseLeave);
            // 
            // sidebar_panel_container
            // 
            this->sidebar_panel_container->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
            this->sidebar_panel_container->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(70)));
            this->sidebar_panel_container->Controls->Add(this->flowLayoutPanel1);
            this->sidebar_panel_container->Controls->Add(this->logout_panel);
            this->sidebar_panel_container->Dock = System::Windows::Forms::DockStyle::Left;
            this->sidebar_panel_container->Location = System::Drawing::Point(0, 0);
            this->sidebar_panel_container->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->sidebar_panel_container->Name = L"sidebar_panel_container";
            this->sidebar_panel_container->Size = System::Drawing::Size(307, 764);
            this->sidebar_panel_container->TabIndex = 1;
            // 
            // flowLayoutPanel1
            // 
            this->flowLayoutPanel1->Controls->Add(this->Menu_panel);
            this->flowLayoutPanel1->Controls->Add(this->Home_panel);
            this->flowLayoutPanel1->Controls->Add(this->Remove_item_panel);
            this->flowLayoutPanel1->Controls->Add(this->add_item_panel);
            this->flowLayoutPanel1->Controls->Add(this->dashboard_panel);
            this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Top;
            this->flowLayoutPanel1->Location = System::Drawing::Point(0, 0);
            this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
            this->flowLayoutPanel1->Size = System::Drawing::Size(307, 602);
            this->flowLayoutPanel1->TabIndex = 0;
            // 
            // add_item_panel
            // 
            this->add_item_panel->Controls->Add(this->label3);
            this->add_item_panel->Controls->Add(this->pictureBox3);
            this->add_item_panel->Cursor = System::Windows::Forms::Cursors::Hand;
            this->add_item_panel->Location = System::Drawing::Point(3, 302);
            this->add_item_panel->Margin = System::Windows::Forms::Padding(3, 2, 3, 6);
            this->add_item_panel->Name = L"add_item_panel";
            this->add_item_panel->Size = System::Drawing::Size(299, 92);
            this->add_item_panel->TabIndex = 2;
            this->add_item_panel->Click += gcnew System::EventHandler(this, &home::add_item_panel_Click);
            this->add_item_panel->MouseEnter += gcnew System::EventHandler(this, &home::Panel_MouseEnter);
            this->add_item_panel->MouseLeave += gcnew System::EventHandler(this, &home::Panel_MouseLeave);
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->BackColor = System::Drawing::Color::Transparent;
            this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label3->ForeColor = System::Drawing::Color::WhiteSmoke;
            this->label3->Location = System::Drawing::Point(53, 21);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(147, 37);
            this->label3->TabIndex = 1;
            this->label3->Text = L"Medicines";
            this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->label3->Click += gcnew System::EventHandler(this, &home::add_item_panel_Click);
            this->label3->MouseEnter += gcnew System::EventHandler(this, &home::Panel_MouseEnter);
            this->label3->MouseLeave += gcnew System::EventHandler(this, &home::Panel_MouseLeave);
            // 
            // pictureBox3
            // 
            this->pictureBox3->BackColor = System::Drawing::Color::Transparent;
            this->pictureBox3->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
            this->pictureBox3->Location = System::Drawing::Point(9, 18);
            this->pictureBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->pictureBox3->Name = L"pictureBox3";
            this->pictureBox3->Size = System::Drawing::Size(39, 39);
            this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox3->TabIndex = 0;
            this->pictureBox3->TabStop = false;
            this->pictureBox3->Click += gcnew System::EventHandler(this, &home::add_item_panel_Click);
            this->pictureBox3->MouseEnter += gcnew System::EventHandler(this, &home::Panel_MouseEnter);
            this->pictureBox3->MouseLeave += gcnew System::EventHandler(this, &home::Panel_MouseLeave);
            // 
            // content_panel
            // 
            this->content_panel->BackColor = System::Drawing::Color::White;
            this->content_panel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->content_panel->Location = System::Drawing::Point(307, 0);
            this->content_panel->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->content_panel->Name = L"content_panel";
            this->content_panel->Size = System::Drawing::Size(716, 764);
            this->content_panel->TabIndex = 2;
            // 
            // sidebarTimer
            // 
            this->sidebarTimer->Interval = 10;
            this->sidebarTimer->Tick += gcnew System::EventHandler(this, &home::SidebarTimer_Tick);
            // 
            // home
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->AutoSize = true;
            this->ClientSize = System::Drawing::Size(1023, 764);
            this->Controls->Add(this->content_panel);
            this->Controls->Add(this->sidebar_panel_container);
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
            this->Name = L"home";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Pharmacy Management System";
            this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
            this->Load += gcnew System::EventHandler(this, &home::home_Load);
            this->Home_panel->ResumeLayout(false);
            this->Home_panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->Remove_item_panel->ResumeLayout(false);
            this->Remove_item_panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
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
            this->add_item_panel->ResumeLayout(false);
            this->add_item_panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
            this->ResumeLayout(false);
        }
#pragma endregion

    private: System::Void Menu_panel_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void Home_panel_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void add_item_panel_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void Remove_item_panel_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void dashboard_panel_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void logout_panel_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void HomePagePanel_Resize(System::Object^ sender, System::EventArgs^ e);
    private: System::Void Panel_MouseEnter(System::Object^ sender, System::EventArgs^ e);
    private: System::Void Panel_MouseLeave(System::Object^ sender, System::EventArgs^ e);
    private: System::Void SidebarTimer_Tick(System::Object^ sender, System::EventArgs^ e);
    private: System::Void home_Load(System::Object^ sender, System::EventArgs^ e) {
        Home_panel_Click(sender, e);
    }
    };
}