#include "Login.h"
#include "home.h"
#include "db.h"
#include "SupplierDBManage.h"
#include "product.h"
#include "inventory.h"
#include "category.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main(array<String^>^ args) {
	//use only if you have changed the db structure
   DBHelper::CreateDatabaseIfNotExists("pharmacy.db");
   // dummy data for the products Note: use it after creating the db otherwise you will face some issues
 //ProductDBHelper::InsertDummyData();
 //  InventoryDBHelper::InsertDummyData();
	//SupplierDBManage::InsertDummySuppliers();


	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	//test::Login^ form = gcnew test::Login();
	// this sould be the main code
	 	Application::Run(gcnew test::Login);
	// we run this now only for debugging faster
	//Application::Run(gcnew test::home);
}