#include "Login.h"
//#include "db.h"
//#include "product.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main(array<String^>^ args) {
	 //use only if you want have changed the db structure
	//DBHelper::CreateDatabaseIfNotExists("pharmacy.db");
	// //dummy data for the products
	//ProductDBHelper::InsertDummyData();
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew test::Login);
}