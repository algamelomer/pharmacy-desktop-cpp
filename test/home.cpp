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
        System::ComponentModel::ComponentResourceManager^ resources = gcnew System::ComponentModel::ComponentResourceManager(home::typeid);

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
        System::ComponentModel::ComponentResourceManager^ resources = gcnew System::ComponentModel::ComponentResourceManager(home::typeid);

        content_panel->Controls->Clear();

        System::Windows::Forms::Panel^ homePagePanel = gcnew System::Windows::Forms::Panel();
        homePagePanel->Dock = System::Windows::Forms::DockStyle::Fill;
        homePagePanel->BackColor = System::Drawing::Color::FromArgb(46, 46, 46);

        // Create the centered image (medicine image from resx)
        System::Windows::Forms::PictureBox^ medicineImage = gcnew System::Windows::Forms::PictureBox();
        // Use the resources variable where needed
        medicineImage->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"medicine")));
        medicineImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
        medicineImage->BackColor = System::Drawing::Color::Transparent;

        // Create the centered label
        System::Windows::Forms::Label^ homeLabel = gcnew System::Windows::Forms::Label();
        homeLabel->Text = L"Welcome to the Pharmacy Management";
        homeLabel->ForeColor = System::Drawing::Color::White;
        homeLabel->BackColor = System::Drawing::Color::Transparent;
        homeLabel->Font = gcnew System::Drawing::Font(L"Arial", 24, System::Drawing::FontStyle::Bold);
        homeLabel->AutoSize = true;

        // Add controls to the panel
        homePagePanel->Controls->Add(medicineImage);
        homePagePanel->Controls->Add(homeLabel);

        float panelWidth = static_cast<float>(homePagePanel->Width);
        float panelHeight = static_cast<float>(homePagePanel->Height);
        float imageWidth = static_cast<float>(medicineImage->Width);
        float imageHeight = static_cast<float>(medicineImage->Height);
        float labelHeight = static_cast<float>(homeLabel->PreferredHeight);

        medicineImage->Location = System::Drawing::Point(
            static_cast<int>((panelWidth - imageWidth) / 2),
            static_cast<int>((panelHeight - (imageHeight + labelHeight + 20)) / 2)
        );
        homeLabel->Location = System::Drawing::Point(
            static_cast<int>((panelWidth - static_cast<float>(homeLabel->PreferredWidth)) / 2),
            medicineImage->Bottom + 20
        );

        homePagePanel->Resize += gcnew System::EventHandler(this, &home::HomePagePanel_Resize);

        content_panel->Controls->Add(homePagePanel);
    }

    System::Void home::HomePagePanel_Resize(System::Object^ sender, System::EventArgs^ e) {
        System::Windows::Forms::Panel^ panel = safe_cast<System::Windows::Forms::Panel^>(sender);
        if (panel->Controls->Count < 2) return; 

        System::Windows::Forms::PictureBox^ image = safe_cast<System::Windows::Forms::PictureBox^>(panel->Controls[0]);
        System::Windows::Forms::Label^ label = safe_cast<System::Windows::Forms::Label^>(panel->Controls[1]);

        float panelWidth = static_cast<float>(panel->Width);
        float panelHeight = static_cast<float>(panel->Height);
        float imageWidth = static_cast<float>(image->Width);
        float imageHeight = static_cast<float>(image->Height);
        float labelHeight = static_cast<float>(label->PreferredHeight);

        image->Location = System::Drawing::Point(
            static_cast<int>((panelWidth - imageWidth) / 2),
            static_cast<int>((panelHeight - (imageHeight + labelHeight + 20)) / 2)
        );
        label->Location = System::Drawing::Point(
            static_cast<int>((panelWidth - static_cast<float>(label->PreferredWidth)) / 2),
            image->Bottom + 20
        );
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