#pragma once  

using namespace System;  
using namespace System::Windows::Forms;  

public ref class CustomerTypeDialog : public Form  
{  
private:  
   Button^ newCustomerButton;  
   Button^ oldCustomerButton;  
   String^ selectedCustomerType;  

public:  
   property String^ SelectedCustomerType  
   {  
       String^ get()  
       {  
           return selectedCustomerType;  
       }  
   }  

   CustomerTypeDialog()  
   {  
       InitializeComponent();  
   }  

private:  
   void InitializeComponent()  
   {  
       this->Text = "Select Customer Type";  
       this->Width = 300;  
       this->Height = 150;  

       newCustomerButton = gcnew Button();  
       newCustomerButton->Text = "New Customer";  
       newCustomerButton->Top = 20;  
       newCustomerButton->Left = 30;  
       newCustomerButton->Click += gcnew EventHandler(this, &CustomerTypeDialog::OnNewCustomerClick);  
       this->Controls->Add(newCustomerButton);  

       oldCustomerButton = gcnew Button();  
       oldCustomerButton->Text = "Old Customer";  
       oldCustomerButton->Top = 20;  
       oldCustomerButton->Left = 150;  
       oldCustomerButton->Click += gcnew EventHandler(this, &CustomerTypeDialog::OnOldCustomerClick);  
       this->Controls->Add(oldCustomerButton);  
   }  

   void OnNewCustomerClick(Object^ sender, EventArgs^ e)  
   {  
       selectedCustomerType = "new";  
       this->DialogResult = System::Windows::Forms::DialogResult::OK;  
       this->Close();  
   }  

   void OnOldCustomerClick(Object^ sender, EventArgs^ e)  
   {  
       selectedCustomerType = "old";  
       this->DialogResult = System::Windows::Forms::DialogResult::OK;  
       this->Close();  
   }  
};
