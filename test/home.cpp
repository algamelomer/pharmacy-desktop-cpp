#include "home.h"
#include "Login.h"
#include "ReceiptForm.h"
#include "Dashboard.h"
#include "Category_form.h"
#include "Inventory_form.h"
#include "SupplierForm.h"
#include "myprofile.h"

using namespace ProductApp;

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
            label5->Visible = false; 
            pictureBox5->Visible = true;
            label6->Visible = false;
            pictureBox6->Visible = true; 
            label7->Visible = false;
            pictureBox7->Visible = true; 
        }
    }

    System::Void home::Home_panel_Click(System::Object^ sender, System::EventArgs^ e) {

        // Clear previous controls
        content_panel->Controls->Clear();

        // Create a panel to fill the content area
        System::Windows::Forms::Panel^ homePagePanel = gcnew System::Windows::Forms::Panel();
        homePagePanel->Dock = System::Windows::Forms::DockStyle::Fill;
        homePagePanel->BackColor = System::Drawing::Color::FromArgb(46, 46, 46);

        // Create the centered label
        System::Windows::Forms::Label^ homeLabel = gcnew System::Windows::Forms::Label();
        homeLabel->Text = L"Welcome to the Pharmacy management";
        homeLabel->ForeColor = System::Drawing::Color::White;
        homeLabel->BackColor = System::Drawing::Color::Transparent;
        homeLabel->Font = gcnew System::Drawing::Font(L"Arial", 24, System::Drawing::FontStyle::Bold);
        homeLabel->AutoSize = true;

        // Center the label in the panel
        homeLabel->Parent = homePagePanel;
        homeLabel->Location = System::Drawing::Point(
            (homePagePanel->Width - homeLabel->PreferredWidth) / 2,
            (homePagePanel->Height - homeLabel->PreferredHeight) / 2
        );
        homeLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(
            System::Windows::Forms::AnchorStyles::None
        );

        // Add a handler to keep the label centered on resize


        homePagePanel->Controls->Add(homeLabel);
        content_panel->Controls->Add(homePagePanel);
    }

    System::Void home::add_item_panel_Click(System::Object^ sender, System::EventArgs^ e) {
        content_panel->Controls->Clear();

        ProductApp::ProductForm^ productPage = gcnew ProductApp::ProductForm();
        productPage->TopLevel = false;
        productPage->Dock = System::Windows::Forms::DockStyle::Fill;
        productPage->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        content_panel->Controls->Add(productPage);
        productPage->Show();


    }

    System::Void home::Remove_item_panel_Click(System::Object^ sender, System::EventArgs^ e) {
        content_panel->Controls->Clear();

        // Create and configure the ReceiptForm
        ReceiptForm^ receiptPage = gcnew ReceiptForm();
        receiptPage->TopLevel = false;
        receiptPage->Dock = System::Windows::Forms::DockStyle::Fill;
        receiptPage->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;

        // Add to content panel
        content_panel->Controls->Add(receiptPage);
        receiptPage->Show();
    }

    System::Void home::dashboard_panel_Click(System::Object^ sender, System::EventArgs^ e) {
        content_panel->Controls->Clear();

        Dashboard^ dashboardpage = gcnew Dashboard();
        dashboardpage->TopLevel = false;
        dashboardpage->Dock = System::Windows::Forms::DockStyle::Fill;
        dashboardpage->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;

        content_panel->Controls->Add(dashboardpage);
        dashboardpage->Show();

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