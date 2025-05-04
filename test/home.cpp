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

} // namespace test