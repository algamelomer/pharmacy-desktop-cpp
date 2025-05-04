#pragma once

namespace test {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Summary for home
    /// </summary>
    public ref class home : public System::Windows::Forms::Form
    {
    public:
        home(void)
        {
            InitializeComponent();
            //
            //TODO: Add the constructor code here
            //
        }

    protected:
        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        ~home()
        {
            if (components)
            {
                delete components;
            }
        }
    private: System::Windows::Forms::Panel^ add_item_panel;
    protected:

    protected:

    private: System::Windows::Forms::Label^ label3;
    private: System::Windows::Forms::PictureBox^ pictureBox3;
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
    private: System::Windows::Forms::Panel^ search_item_panel;

    private: System::Windows::Forms::Label^ label4;
    private: System::Windows::Forms::PictureBox^ pictureBox4;
    private: System::Windows::Forms::Panel^ logout_panel;

    private: System::Windows::Forms::Label^ label7;
    private: System::Windows::Forms::PictureBox^ pictureBox7;
    private: System::Windows::Forms::Panel^ sidebar_panel_container;
    private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;

    private: bool sidebarExpanded = true;

    protected:

    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
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
            this->add_item_panel->Location = System::Drawing::Point(3, 142);
            this->add_item_panel->Margin = System::Windows::Forms::Padding(3, 3, 3, 6);
            this->add_item_panel->Name = L"add_item_panel";
            this->add_item_panel->Size = System::Drawing::Size(208, 56);
            this->add_item_panel->TabIndex = 2;
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->BackColor = System::Drawing::Color::Transparent;
            this->label3->Font = (gcnew System::Drawing::Font(L"Script MT Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label3->Location = System::Drawing::Point(54, 18);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(81, 24);
            this->label3->TabIndex = 1;
            this->label3->Text = L"Add item";
            this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // pictureBox3
            // 
            this->pictureBox3->BackColor = System::Drawing::Color::Transparent;
            this->pictureBox3->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
            this->pictureBox3->Location = System::Drawing::Point(9, 9);
            this->pictureBox3->Name = L"pictureBox3";
            this->pictureBox3->Size = System::Drawing::Size(39, 39);
            this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox3->TabIndex = 0;
            this->pictureBox3->TabStop = false;
            // 
            // Home_panel
            // 
            this->Home_panel->Controls->Add(this->label1);
            this->Home_panel->Controls->Add(this->pictureBox1);
            this->Home_panel->Cursor = System::Windows::Forms::Cursors::Hand;
            this->Home_panel->Location = System::Drawing::Point(3, 77);
            this->Home_panel->Margin = System::Windows::Forms::Padding(3, 3, 3, 6);
            this->Home_panel->Name = L"Home_panel";
            this->Home_panel->Size = System::Drawing::Size(208, 56);
            this->Home_panel->TabIndex = 3;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->BackColor = System::Drawing::Color::Transparent;
            this->label1->Font = (gcnew System::Drawing::Font(L"Script MT Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label1->Location = System::Drawing::Point(54, 18);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(58, 24);
            this->label1->TabIndex = 1;
            this->label1->Text = L"Home";
            this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // pictureBox1
            // 
            this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
            this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
            this->pictureBox1->Location = System::Drawing::Point(9, 9);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(39, 39);
            this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox1->TabIndex = 0;
            this->pictureBox1->TabStop = false;
            // 
            // Remove_item_panel
            // 
            this->Remove_item_panel->Controls->Add(this->label2);
            this->Remove_item_panel->Controls->Add(this->pictureBox2);
            this->Remove_item_panel->Cursor = System::Windows::Forms::Cursors::Hand;
            this->Remove_item_panel->Location = System::Drawing::Point(3, 207);
            this->Remove_item_panel->Margin = System::Windows::Forms::Padding(3, 3, 3, 6);
            this->Remove_item_panel->Name = L"Remove_item_panel";
            this->Remove_item_panel->Size = System::Drawing::Size(208, 56);
            this->Remove_item_panel->TabIndex = 4;
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->BackColor = System::Drawing::Color::Transparent;
            this->label2->Font = (gcnew System::Drawing::Font(L"Script MT Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label2->Location = System::Drawing::Point(54, 18);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(109, 24);
            this->label2->TabIndex = 1;
            this->label2->Text = L"Remove item";
            this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // pictureBox2
            // 
            this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
            this->pictureBox2->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
            this->pictureBox2->Location = System::Drawing::Point(9, 9);
            this->pictureBox2->Name = L"pictureBox2";
            this->pictureBox2->Size = System::Drawing::Size(39, 39);
            this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox2->TabIndex = 0;
            this->pictureBox2->TabStop = false;
            // 
            // search_item_panel
            // 
            this->search_item_panel->Controls->Add(this->label4);
            this->search_item_panel->Controls->Add(this->pictureBox4);
            this->search_item_panel->Cursor = System::Windows::Forms::Cursors::Hand;
            this->search_item_panel->Location = System::Drawing::Point(3, 272);
            this->search_item_panel->Margin = System::Windows::Forms::Padding(3, 3, 3, 6);
            this->search_item_panel->Name = L"search_item_panel";
            this->search_item_panel->Size = System::Drawing::Size(208, 56);
            this->search_item_panel->TabIndex = 5;
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->BackColor = System::Drawing::Color::Transparent;
            this->label4->Font = (gcnew System::Drawing::Font(L"Script MT Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label4->Location = System::Drawing::Point(54, 18);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(99, 24);
            this->label4->TabIndex = 1;
            this->label4->Text = L"Search item";
            this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // pictureBox4
            // 
            this->pictureBox4->BackColor = System::Drawing::Color::Transparent;
            this->pictureBox4->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
            this->pictureBox4->Location = System::Drawing::Point(9, 9);
            this->pictureBox4->Name = L"pictureBox4";
            this->pictureBox4->Size = System::Drawing::Size(39, 39);
            this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox4->TabIndex = 0;
            this->pictureBox4->TabStop = false;
            // 
            // Menu_panel
            // 
            this->Menu_panel->BackColor = System::Drawing::Color::Transparent;
            this->Menu_panel->Controls->Add(this->label5);
            this->Menu_panel->Controls->Add(this->pictureBox5);
            this->Menu_panel->Cursor = System::Windows::Forms::Cursors::Hand;
            this->Menu_panel->Location = System::Drawing::Point(3, 3);
            this->Menu_panel->Margin = System::Windows::Forms::Padding(3, 3, 3, 6);
            this->Menu_panel->Name = L"Menu_panel";
            this->Menu_panel->Size = System::Drawing::Size(208, 65);
            this->Menu_panel->TabIndex = 5;
            this->Menu_panel->Click += gcnew System::EventHandler(this, &home::Menu_panel_Click);
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->BackColor = System::Drawing::Color::Transparent;
            this->label5->Font = (gcnew System::Drawing::Font(L"Script MT Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label5->Location = System::Drawing::Point(54, 18);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(57, 24);
            this->label5->TabIndex = 1;
            this->label5->Text = L"Menu";
            this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->label5->Click += gcnew System::EventHandler(this, &home::Menu_panel_Click);
            // 
            // pictureBox5
            // 
            this->pictureBox5->BackColor = System::Drawing::Color::Transparent;
            this->pictureBox5->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
            this->pictureBox5->Location = System::Drawing::Point(9, 9);
            this->pictureBox5->Name = L"pictureBox5";
            this->pictureBox5->Size = System::Drawing::Size(45, 45);
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
            this->dashboard_panel->Location = System::Drawing::Point(3, 337);
            this->dashboard_panel->Margin = System::Windows::Forms::Padding(3, 3, 3, 6);
            this->dashboard_panel->Name = L"dashboard_panel";
            this->dashboard_panel->Size = System::Drawing::Size(208, 56);
            this->dashboard_panel->TabIndex = 5;
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->BackColor = System::Drawing::Color::Transparent;
            this->label6->Font = (gcnew System::Drawing::Font(L"Script MT Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label6->Location = System::Drawing::Point(54, 18);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(98, 24);
            this->label6->TabIndex = 1;
            this->label6->Text = L"Dashboard";
            this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // pictureBox6
            // 
            this->pictureBox6->BackColor = System::Drawing::Color::Transparent;
            this->pictureBox6->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
            this->pictureBox6->Location = System::Drawing::Point(9, 9);
            this->pictureBox6->Name = L"pictureBox6";
            this->pictureBox6->Size = System::Drawing::Size(39, 39);
            this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox6->TabIndex = 0;
            this->pictureBox6->TabStop = false;
            // 
            // logout_panel
            // 
            this->logout_panel->Controls->Add(this->label7);
            this->logout_panel->Controls->Add(this->pictureBox7);
            this->logout_panel->Cursor = System::Windows::Forms::Cursors::Hand;
            this->logout_panel->Dock = System::Windows::Forms::DockStyle::Bottom;
            this->logout_panel->Location = System::Drawing::Point(0, 558);
            this->logout_panel->Margin = System::Windows::Forms::Padding(3, 3, 3, 6);
            this->logout_panel->Name = L"logout_panel";
            this->logout_panel->Size = System::Drawing::Size(217, 56);
            this->logout_panel->TabIndex = 6;
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->BackColor = System::Drawing::Color::Transparent;
            this->label7->Font = (gcnew System::Drawing::Font(L"Script MT Bold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label7->Location = System::Drawing::Point(54, 18);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(67, 24);
            this->label7->TabIndex = 1;
            this->label7->Text = L"Logout";
            this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // pictureBox7
            // 
            this->pictureBox7->BackColor = System::Drawing::Color::Transparent;
            this->pictureBox7->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.Image")));
            this->pictureBox7->Location = System::Drawing::Point(9, 9);
            this->pictureBox7->Name = L"pictureBox7";
            this->pictureBox7->Size = System::Drawing::Size(39, 39);
            this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox7->TabIndex = 0;
            this->pictureBox7->TabStop = false;
            // 
            // sidebar_panel_container
            // 
            this->sidebar_panel_container->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
            this->sidebar_panel_container->Controls->Add(this->flowLayoutPanel1);
            this->sidebar_panel_container->Controls->Add(this->logout_panel);
            this->sidebar_panel_container->Dock = System::Windows::Forms::DockStyle::Left;
            this->sidebar_panel_container->Location = System::Drawing::Point(0, 0);
            this->sidebar_panel_container->Name = L"sidebar_panel_container";
            this->sidebar_panel_container->Size = System::Drawing::Size(217, 614);
            this->sidebar_panel_container->TabIndex = 1;
            this->sidebar_panel_container->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &home::sidebar_panel_container_Paint);
            // 
            // flowLayoutPanel1
            // 
            this->flowLayoutPanel1->Controls->Add(this->Menu_panel);
            this->flowLayoutPanel1->Controls->Add(this->Home_panel);
            this->flowLayoutPanel1->Controls->Add(this->add_item_panel);
            this->flowLayoutPanel1->Controls->Add(this->Remove_item_panel);
            this->flowLayoutPanel1->Controls->Add(this->search_item_panel);
            this->flowLayoutPanel1->Controls->Add(this->dashboard_panel);
            this->flowLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Top;
            this->flowLayoutPanel1->Location = System::Drawing::Point(0, 0);
            this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
            this->flowLayoutPanel1->Size = System::Drawing::Size(217, 409);
            this->flowLayoutPanel1->TabIndex = 0;
            // 
            // home
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(844, 614);
            this->Controls->Add(this->sidebar_panel_container);
            this->Name = L"home";
            this->Text = L"home";
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
    private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
    }

    private: System::Void flowLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
    }
    private: System::Void Menu_panel_Click(System::Object^ sender, System::EventArgs^ e);
    private: System::Void sidebar_panel_container_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
    }
};
}