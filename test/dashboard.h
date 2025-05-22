#pragma once

namespace test {
    // Add these event handler assignments in InitializeComponent after each label/pictureBox is created

    // For panel1 (Category)

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Dashboard
	/// </summary>
	public ref class Dashboard : public System::Windows::Forms::Form
	{
	public:
		Dashboard(void)
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


	protected:

	protected:

	protected:

	private:
		void LoadUserControl(System::Windows::Forms::UserControl^ userControl);
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
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
			this->mainPanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(46)),
				static_cast<System::Int32>(static_cast<System::Byte>(46)));
			this->mainPanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->mainPanel->Location = System::Drawing::Point(0, 0);
			this->mainPanel->Name = L"mainPanel";
			this->mainPanel->Padding = System::Windows::Forms::Padding(0, 153, 0, 0);
			this->mainPanel->Size = System::Drawing::Size(1101, 562);
			this->mainPanel->TabIndex = 0;
			this->mainPanel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Dashboard::mainPanel_Paint);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->panel5);
			this->panel2->Controls->Add(this->panel4);
			this->panel2->Controls->Add(this->panel1);
			this->panel2->Controls->Add(this->panel3);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1101, 153);
			this->panel2->TabIndex = 1;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Dashboard::panel2_Paint);
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->pictureBox4);
			this->panel5->Controls->Add(this->label4);
			this->panel5->Cursor = System::Windows::Forms::Cursors::Hand;
			this->panel5->Location = System::Drawing::Point(658, 0);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(161, 153);
			this->panel5->TabIndex = 3;
			this->panel5->Click += gcnew System::EventHandler(this, &Dashboard::panel5_Click);
			// 
			// pictureBox4
			// 
			this->pictureBox4->Dock = System::Windows::Forms::DockStyle::Top;
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(0, 0);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(161, 92);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox4->TabIndex = 2;
			this->pictureBox4->TabStop = false;
			this->pictureBox4->Click += gcnew System::EventHandler(this, &Dashboard::panel5_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(48, 115);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(69, 25);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Return";
			this->label4->Click += gcnew System::EventHandler(this, &Dashboard::panel5_Click);
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->pictureBox3);
			this->panel4->Controls->Add(this->label2);
			this->panel4->Cursor = System::Windows::Forms::Cursors::Hand;
			this->panel4->Location = System::Drawing::Point(353, 0);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(161, 153);
			this->panel4->TabIndex = 2;
			this->panel4->Click += gcnew System::EventHandler(this, &Dashboard::panel4_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->Dock = System::Windows::Forms::DockStyle::Top;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(0, 0);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(161, 92);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 2;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Click += gcnew System::EventHandler(this, &Dashboard::panel4_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(38, 115);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(92, 25);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Inventory";
			this->label2->Click += gcnew System::EventHandler(this, &Dashboard::panel4_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->panel1->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel1->Location = System::Drawing::Point(940, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(161, 153);
			this->panel1->TabIndex = 1;
			this->panel1->Click += gcnew System::EventHandler(this, &Dashboard::panel1_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Top;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->InitialImage = nullptr;
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(161, 92);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Dashboard::panel1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(46, 115);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(92, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Category";
			this->label1->Click += gcnew System::EventHandler(this, &Dashboard::panel1_Click);
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->label3);
			this->panel3->Controls->Add(this->pictureBox2);
			this->panel3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->panel3->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel3->Location = System::Drawing::Point(0, 0);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(161, 153);
			this->panel3->TabIndex = 2;
			this->panel3->Click += gcnew System::EventHandler(this, &Dashboard::panel3_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(40, 115);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(84, 25);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Supplier";
			this->label3->Click += gcnew System::EventHandler(this, &Dashboard::panel3_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Dock = System::Windows::Forms::DockStyle::Top;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(0, 0);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(161, 92);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 2;
			this->pictureBox2->TabStop = false;
			this->pictureBox2->Click += gcnew System::EventHandler(this, &Dashboard::panel3_Click);
			// 
			// Dashboard
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(46)), static_cast<System::Int32>(static_cast<System::Byte>(46)),
				static_cast<System::Int32>(static_cast<System::Byte>(46)));
			this->ClientSize = System::Drawing::Size(1101, 562);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->mainPanel);
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
					CenterPanel4And5();
    }
    private: void CenterPanel4And5() {
					int panel2Width = this->panel2->Width;
					int panel2Height = this->panel2->Height;

					// Center panel4
					int panel4Width = this->panel4->Width;
					int panel4Height = this->panel4->Height;
					int centerX4 = (panel2Width - panel4Width) / 3;
					int centerY4 = (panel2Height - panel4Height) / 2;
					this->panel4->Location = System::Drawing::Point(centerX4, centerY4);

					// Center panel5
					int panel5Width = this->panel5->Width;
					int panel5Height = this->panel5->Height;
					int centerX5 = (panel2Width - panel5Width) /1.5;
					int centerY5 = (panel2Height - panel5Height) / 2;
					this->panel5->Location = System::Drawing::Point(centerX5, centerY5);
    }

    // Replace all calls to CenterPanel4() with CenterPanel4And5()
  

    private: System::Void panel2_Resize(System::Object^ sender, System::EventArgs^ e) {
					CenterPanel4And5();
    }

	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void listView1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}

			 
//private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
      


			private: System::Void panel4_Click(System::Object^ sender, System::EventArgs^ e);

			private: System::Void panel1_Click(System::Object^ sender, System::EventArgs^ e);

			private: System::Void panel3_Click(System::Object^ sender, System::EventArgs^ e);


			private: System::Void panel5_Click(System::Object^ sender, System::EventArgs^ e);
	// This can stay empty or be used for drawing, but it's not needed for click.
//}
//private: System::Void panel4_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
//	// This can stay empty or be used for drawing, but it's not needed for click.
//}
//	   private: System::Void panel3_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
//		   // This can stay empty or be used for drawing, but it's not needed for click.
//	   }
//private: System::Void panel1_Click(System::Object^ sender, System::EventArgs^ e) {
//	LoadUserControl(gcnew CategoryPage());
//}
//
//private: System::Void panel3_Click(System::Object^ sender, System::EventArgs^ e) {
//	LoadUserControl(gcnew SupplierPage());
//}
//
//private: System::Void panel4_Click(System::Object^ sender, System::EventArgs^ e) {
//	LoadUserControl(gcnew InventoryPage());
//}


//private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);
//private: System::Void panel4_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);
//private: System::Void panel3_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);

private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void mainPanel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void pictureBox4_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
