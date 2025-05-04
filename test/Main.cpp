#include "Login.h"
#include "db.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main(array<String^>^ args) {
	DBHelper::CreateDatabaseIfNotExists("pharmacy.db");

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew test::Login);
}