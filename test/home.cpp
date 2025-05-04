#include "home.h"

namespace test {

    System::Void home::Menu_panel_Click(System::Object^ sender, System::EventArgs^ e) {
        // Toggle the sidebarExpanded flag
        sidebarExpanded = !sidebarExpanded;

        if (sidebarExpanded) {
            // Expand the sidebar
            sidebar_panel_container->Width = 217; // Original width

            // Show labels and icons for all panels
            label1->Visible = true;
            pictureBox1->Visible = true;
            label2->Visible = true;
            pictureBox2->Visible = true;
            label3->Visible = true;
            pictureBox3->Visible = true;
            label4->Visible = true;
            pictureBox4->Visible = true;
            label5->Visible = true; // Menu label
            pictureBox5->Visible = true; // Menu icon
            label6->Visible = true;
            pictureBox6->Visible = true;
            label7->Visible = true;
            pictureBox7->Visible = true;
        }
        else {
            // Collapse the sidebar
            sidebar_panel_container->Width = 60; // Reduced width to show only icons

            // Hide labels and icons for all panels except Menu_panel's icon
            label1->Visible = false;
            pictureBox1->Visible = true; // Keep icon visible
            label2->Visible = false;
            pictureBox2->Visible = true; // Keep icon visible
            label3->Visible = false;
            pictureBox3->Visible = true; // Keep icon visible
            label4->Visible = false;
            pictureBox4->Visible = true; // Keep icon visible
            label5->Visible = false; // Hide Menu label
            pictureBox5->Visible = true; // Keep Menu icon visible
            label6->Visible = false;
            pictureBox6->Visible = true; // Keep icon visible
            label7->Visible = false;
            pictureBox7->Visible = true; // Keep icon visible
        }
    }

    System::Void home::Home_panel_Click(System::Object^ sender, System::EventArgs^ e) {
        // Clear existing content
        content_panel->Controls->Clear();

        // Add Home page content (placeholder)
        System::Windows::Forms::Label^ homeLabel = gcnew System::Windows::Forms::Label();
        homeLabel->Text = L"Welcome to the Home Page";
        homeLabel->AutoSize = true;
        homeLabel->Font = gcnew System::Drawing::Font(L"Arial", 16, System::Drawing::FontStyle::Bold);
        homeLabel->Location = System::Drawing::Point(50, 50);
        content_panel->Controls->Add(homeLabel);
    }

    System::Void home::add_item_panel_Click(System::Object^ sender, System::EventArgs^ e) {
        // Clear existing content
        content_panel->Controls->Clear();

        // Add Add Item page content (placeholder)
        System::Windows::Forms::Label^ addItemLabel = gcnew System::Windows::Forms::Label();
        addItemLabel->Text = L"Add Item Page";
        addItemLabel->AutoSize = true;
        addItemLabel->Font = gcnew System::Drawing::Font(L"Arial", 16, System::Drawing::FontStyle::Bold);
        addItemLabel->Location = System::Drawing::Point(50, 50);
        content_panel->Controls->Add(addItemLabel);
    }

    System::Void home::Remove_item_panel_Click(System::Object^ sender, System::EventArgs^ e) {
        // Clear existing content
        content_panel->Controls->Clear();

        // Add Remove Item page content (placeholder)
        System::Windows::Forms::Label^ removeItemLabel = gcnew System::Windows::Forms::Label();
        removeItemLabel->Text = L"Remove Item Page";
        removeItemLabel->AutoSize = true;
        removeItemLabel->Font = gcnew System::Drawing::Font(L"Arial", 16, System::Drawing::FontStyle::Bold);
        removeItemLabel->Location = System::Drawing::Point(50, 50);
        content_panel->Controls->Add(removeItemLabel);
    }

    System::Void home::search_item_panel_Click(System::Object^ sender, System::EventArgs^ e) {
        // Clear existing content
        content_panel->Controls->Clear();

        // Add Search Item page content (using ProductSearchForm)
        ProductSearchForm^ searchForm = gcnew ProductSearchForm();
        searchForm->TopLevel = false;
        searchForm->Dock = System::Windows::Forms::DockStyle::Fill;
        searchForm->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
        content_panel->Controls->Add(searchForm);
        searchForm->Show();
    }

    System::Void home::dashboard_panel_Click(System::Object^ sender, System::EventArgs^ e) {
        // Clear existing content
        content_panel->Controls->Clear();

        // Add Dashboard page content (placeholder)
        System::Windows::Forms::Label^ dashboardLabel = gcnew System::Windows::Forms::Label();
        dashboardLabel->Text = L"Dashboard Page";
        dashboardLabel->AutoSize = true;
        dashboardLabel->Font = gcnew System::Drawing::Font(L"Arial", 16, System::Drawing::FontStyle::Bold);
        dashboardLabel->Location = System::Drawing::Point(50, 50);
        content_panel->Controls->Add(dashboardLabel);
    }

    System::Void home::logout_panel_Click(System::Object^ sender, System::EventArgs^ e) {
        // Clear existing content
        content_panel->Controls->Clear();

        // Add Logout page content (placeholder)
        System::Windows::Forms::Label^ logoutLabel = gcnew System::Windows::Forms::Label();
        logoutLabel->Text = L"Logout Page";
        logoutLabel->AutoSize = true;
        logoutLabel->Font = gcnew System::Drawing::Font(L"Arial", 16, System::Drawing::FontStyle::Bold);
        logoutLabel->Location = System::Drawing::Point(50, 50);
        content_panel->Controls->Add(logoutLabel);
    }

} // namespace test