#pragma once

namespace test {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class Login : public System::Windows::Forms::Form
    {
    public:
        Login(void)
        {
            InitializeComponent();
        }

    protected:
        ~Login()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Label^ label1;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::TextBox^ textBox1;
    private: System::Windows::Forms::TextBox^ textBox2;
    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::CheckBox^ checkBox1;
    private: System::Windows::Forms::LinkLabel^ linkLabel1;
    private: System::Windows::Forms::Button^ button1;
    private: System::Windows::Forms::Button^ button2;
    private: System::Windows::Forms::PictureBox^ pbLogo;
    private: System::Windows::Forms::Label^ lblTitle;
    private: System::Windows::Forms::Panel^ panelLeft;

    private:
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Login::typeid));
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->textBox2 = (gcnew System::Windows::Forms::TextBox());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
            this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->pbLogo = (gcnew System::Windows::Forms::PictureBox());
            this->lblTitle = (gcnew System::Windows::Forms::Label());
            this->panelLeft = (gcnew System::Windows::Forms::Panel());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo))->BeginInit();
            this->panelLeft->SuspendLayout();
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
                static_cast<System::Int32>(static_cast<System::Byte>(200)));
            this->label1->Location = System::Drawing::Point(480, 37);
            this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(151, 54);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Sign in";
            this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(440, 160);
            this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(87, 23);
            this->label2->TabIndex = 1;
            this->label2->Text = L"Username";
            // 
            // textBox1
            // 
            this->textBox1->BackColor = System::Drawing::Color::WhiteSmoke;
            this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->textBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBox1->Location = System::Drawing::Point(440, 185);
            this->textBox1->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(333, 34);
            this->textBox1->TabIndex = 2;
            this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            this->textBox1->TextChanged += gcnew System::EventHandler(this, &Login::textBox1_TextChanged);
            // 
            // textBox2
            // 
            this->textBox2->BackColor = System::Drawing::Color::WhiteSmoke;
            this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->textBox2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->textBox2->Location = System::Drawing::Point(440, 271);
            this->textBox2->Margin = System::Windows::Forms::Padding(7, 6, 7, 6);
            this->textBox2->Name = L"textBox2";
            this->textBox2->PasswordChar = '*';
            this->textBox2->Size = System::Drawing::Size(333, 34);
            this->textBox2->TabIndex = 3;
            this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(440, 246);
            this->label3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(80, 23);
            this->label3->TabIndex = 4;
            this->label3->Text = L"Password";
            // 
            // checkBox1
            // 
            this->checkBox1->AutoSize = true;
            this->checkBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->checkBox1->Location = System::Drawing::Point(440, 320);
            this->checkBox1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->checkBox1->Name = L"checkBox1";
            this->checkBox1->Size = System::Drawing::Size(95, 24);
            this->checkBox1->TabIndex = 5;
            this->checkBox1->Text = L"I agree to";
            this->checkBox1->UseVisualStyleBackColor = true;
            // 
            // linkLabel1
            // 
            this->linkLabel1->ActiveLinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
                static_cast<System::Int32>(static_cast<System::Byte>(150)));
            this->linkLabel1->AutoSize = true;
            this->linkLabel1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->linkLabel1->LinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
                static_cast<System::Int32>(static_cast<System::Byte>(200)));
            this->linkLabel1->Location = System::Drawing::Point(553, 320);
            this->linkLabel1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->linkLabel1->Name = L"linkLabel1";
            this->linkLabel1->Size = System::Drawing::Size(150, 20);
            this->linkLabel1->TabIndex = 6;
            this->linkLabel1->TabStop = true;
            this->linkLabel1->Text = L"Terms and conditions";
            this->linkLabel1->VisitedLinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
                static_cast<System::Int32>(static_cast<System::Byte>(150)));
            this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &Login::linkLabel1_LinkClicked);
            // 
            // button1
            // 
            this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
                static_cast<System::Int32>(static_cast<System::Byte>(200)));
            this->button1->FlatAppearance->BorderSize = 0;
            this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button1->ForeColor = System::Drawing::Color::White;
            this->button1->Location = System::Drawing::Point(440, 357);
            this->button1->Margin = System::Windows::Forms::Padding(13, 12, 13, 12);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(333, 49);
            this->button1->TabIndex = 7;
            this->button1->Text = L"Sign In";
            this->button1->UseVisualStyleBackColor = false;
            this->button1->Click += gcnew System::EventHandler(this, &Login::button1_Click);
            // 
            // button2
            // 
            this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(200)), static_cast<System::Int32>(static_cast<System::Byte>(230)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->button2->FlatAppearance->BorderSize = 0;
            this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->button2->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->button2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
                static_cast<System::Int32>(static_cast<System::Byte>(200)));
            this->button2->Location = System::Drawing::Point(440, 418);
            this->button2->Margin = System::Windows::Forms::Padding(13, 12, 13, 12);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(333, 37);
            this->button2->TabIndex = 8;
            this->button2->Text = L"Don\'t have an account\? Sign Up";
            this->button2->UseVisualStyleBackColor = false;
            this->button2->Click += gcnew System::EventHandler(this, &Login::button2_Click);
            // 
            // pbLogo
            // 
            this->pbLogo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbLogo.Image")));
            this->pbLogo->Location = System::Drawing::Point(67, 62);
            this->pbLogo->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->pbLogo->Name = L"pbLogo";
            this->pbLogo->Size = System::Drawing::Size(200, 185);
            this->pbLogo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
            this->pbLogo->TabIndex = 0;
            this->pbLogo->TabStop = false;
            // 
            // lblTitle
            // 
            this->lblTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->lblTitle->ForeColor = System::Drawing::Color::White;
            this->lblTitle->Location = System::Drawing::Point(40, 258);
            this->lblTitle->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->lblTitle->Name = L"lblTitle";
            this->lblTitle->Size = System::Drawing::Size(253, 148);
            this->lblTitle->TabIndex = 1;
            this->lblTitle->Text = L"Pharmacy\nManagement\nSystem";
            this->lblTitle->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // panelLeft
            // 
            this->panelLeft->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(50)),
                static_cast<System::Int32>(static_cast<System::Byte>(70)));
            this->panelLeft->Controls->Add(this->pbLogo);
            this->panelLeft->Controls->Add(this->lblTitle);
            this->panelLeft->Dock = System::Windows::Forms::DockStyle::Left;
            this->panelLeft->Location = System::Drawing::Point(0, 0);
            this->panelLeft->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->panelLeft->Name = L"panelLeft";
            this->panelLeft->Size = System::Drawing::Size(333, 554);
            this->panelLeft->TabIndex = 9;
            // 
            // Login
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(245)),
                static_cast<System::Int32>(static_cast<System::Byte>(249)));
            this->ClientSize = System::Drawing::Size(867, 554);
            this->Controls->Add(this->panelLeft);
            this->Controls->Add(this->button2);
            this->Controls->Add(this->button1);
            this->Controls->Add(this->linkLabel1);
            this->Controls->Add(this->checkBox1);
            this->Controls->Add(this->label3);
            this->Controls->Add(this->textBox2);
            this->Controls->Add(this->textBox1);
            this->Controls->Add(this->label2);
            this->Controls->Add(this->label1);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
            this->MaximizeBox = false;
            this->Name = L"Login";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Login";
            this->Load += gcnew System::EventHandler(this, &Login::Login_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbLogo))->EndInit();
            this->panelLeft->ResumeLayout(false);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private:
        System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e);
        System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
        System::Void linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e);
        System::Void Login_Load(System::Object^ sender, System::EventArgs^ e);
    };
}