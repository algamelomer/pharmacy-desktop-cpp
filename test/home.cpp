#include "home.h"
#include "Login.h"
#include "ReceiptForm.h"

namespace test {

    System::Void home::Menu_panel_Click(System::Object^ sender, System::EventArgs^ e) {
        sidebarExpanded = !sidebarExpanded;

        if (sidebarExpanded) {
            sidebar_panel_container->Width = 217;

            label1->Visible = true;
            pictureBox1->Visible = true;
            label2->Visible = true;
            pictureBox2->Visible = true;
            label3->Visible = true;
            pictureBox3->Visible = true;
            label4->Visible = true;
            pictureBox4->Visible = true;
            label5->Visible = true; 
            pictureBox5->Visible = true;
            label6->Visible = true;
            pictureBox6->Visible = true;
            label7->Visible = true;
            pictureBox7->Visible = true;
        }
        else {
            sidebar_panel_container->Width = 60;

            label1->Visible = false;
            pictureBox1->Visible = true;
            label2->Visible = false;
            pictureBox2->Visible = true;
            label3->Visible = false;
            pictureBox3->Visible = true;
            label4->Visible = false;
            pictureBox4->Visible = true;
            label5->Visible = false; 
            pictureBox5->Visible = true;
            label6->Visible = false;
            pictureBox6->Visible = true; 
            label7->Visible = false;
            pictureBox7->Visible = true; 
        }
    }

    System::Void home::Home_panel_Click(System::Object^ sender, System::EventArgs^ e) {
        content_panel->Controls->Clear();

        System::Windows::Forms::Label^ homeLabel = gcnew System::Windows::Forms::Label();
        homeLabel->Text = L"Welcome to the Home Page";
        homeLabel->AutoSize = true;
        homeLabel->Font = gcnew System::Drawing::Font(L"Arial", 16, System::Drawing::FontStyle::Bold);
        homeLabel->Location = System::Drawing::Point(50, 50);
        content_panel->Controls->Add(homeLabel);
    }

    System::Void home::add_item_panel_Click(System::Object^ sender, System::EventArgs^ e) {
        content_panel->Controls->Clear();

        System::Windows::Forms::Label^ addItemLabel = gcnew System::Windows::Forms::Label();
        addItemLabel->Text = L"Add Item Page";
        addItemLabel->AutoSize = true;
        addItemLabel->Font = gcnew System::Drawing::Font(L"Arial", 16, System::Drawing::FontStyle::Bold);
        addItemLabel->Location = System::Drawing::Point(50, 50);
        content_panel->Controls->Add(addItemLabel);
    }

    System::Void home::Remove_item_panel_Click(System::Object^ sender, System::EventArgs^ e) {
        content_panel->Controls->Clear();

        System::Windows::Forms::Label^ removeItemLabel = gcnew System::Windows::Forms::Label();
        removeItemLabel->Text = L"Remove Item Page";
        removeItemLabel->AutoSize = true;
        removeItemLabel->Font = gcnew System::Drawing::Font(L"Arial", 16, System::Drawing::FontStyle::Bold);
        removeItemLabel->Location = System::Drawing::Point(50, 50);
        content_panel->Controls->Add(removeItemLabel);
        List<int>^ purchasedIds = gcnew List<int>();
        purchasedIds->Add(4);
        purchasedIds->Add(3);
        double userCash = 5000.0;
        ReceiptForm^ receiptForm = gcnew ReceiptForm();
        receiptForm->ShowDialog();


    }

    System::Void home::search_item_panel_Click(System::Object^ sender, System::EventArgs^ e) {
        content_panel->Controls->Clear();

        ProductSearchForm^ searchForm = gcnew ProductSearchForm();
        searchForm->TopLevel = false;
        searchForm->Dock = System::Windows::Forms::DockStyle::Fill;
        searchForm->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        content_panel->Controls->Add(searchForm);
        searchForm->Show();
    }

    System::Void home::dashboard_panel_Click(System::Object^ sender, System::EventArgs^ e) {
        content_panel->Controls->Clear();

        ProductApp::ProductForm^ productPage = gcnew ProductApp::ProductForm();
        productPage->TopLevel = false;
        productPage->Dock = System::Windows::Forms::DockStyle::Fill;
        productPage->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        content_panel->Controls->Add(productPage);
        productPage->Show();

    }

    System::Void home::logout_panel_Click(System::Object^ sender, System::EventArgs^ e) {
        System::Windows::Forms::DialogResult result = MessageBox::Show(
            "Are you sure you want to logout?",
            "Confirm Logout",
            MessageBoxButtons::YesNo,
            MessageBoxIcon::Question
        );

        if (result == System::Windows::Forms::DialogResult::Yes)
        {
            content_panel->Controls->Clear();
            MessageBox::Show("You have been logged out successfully.", "Logout", MessageBoxButtons::OK, MessageBoxIcon::Information);
            this->Hide();
            Login^ loginForm = gcnew Login();
            loginForm->ShowDialog();

            this->Close();
        }

    }

}