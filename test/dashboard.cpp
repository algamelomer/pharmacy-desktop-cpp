#include "dashboard.h"  
#include "SupplierForm.h"  
#include "Inventory_form.h"
#include "Category_form.h"
#include "ReturnForm.h"
using namespace test;  


void Dashboard::LoadUserControl(System::Windows::Forms::UserControl^ userControl) {
	this->mainPanel->Controls->Clear();
	userControl->Dock = System::Windows::Forms::DockStyle::Fill;
	userControl->Margin = System::Windows::Forms::Padding(0); // Remove any margin
	userControl->Padding = System::Windows::Forms::Padding(0); // Remove any padding
	userControl->AutoSize = false; // Prevent autosizing
	userControl->Size = this->mainPanel->ClientSize; // Explicitly set size to fill panel
	this->mainPanel->Controls->Add(userControl);
}

using namespace test;

System::Void Dashboard::panel1_Click(System::Object^ sender, System::EventArgs^ e) {
	ProductApp::CategoryForm^ categoryForm = gcnew ProductApp::CategoryForm();
	LoadUserControl(categoryForm);
}


System::Void Dashboard::panel4_Click(System::Object^ sender, System::EventArgs^ e) {
	ProductApp::InventoryForm^ inventoryForm = gcnew ProductApp::InventoryForm();
	LoadUserControl(inventoryForm);
}  

System::Void Dashboard::panel3_Click(System::Object^ sender, System::EventArgs^ e) {
	test::SupplierForm^ supplierForm = gcnew test::SupplierForm();
  LoadUserControl(supplierForm);  
}  


System::Void Dashboard::panel5_Click(System::Object^ sender, System::EventArgs^ e) {
	ReturnForm^ returnForm = gcnew ReturnForm();
	LoadUserControl(returnForm);
}
