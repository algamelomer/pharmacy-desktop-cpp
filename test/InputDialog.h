#pragma once

using namespace System;
using namespace System::Windows::Forms;

public ref class InputDialog : public Form
{
private:
   TextBox^ inputBox;
   Button^ okButton;
   Label^ promptLabel;

public:
   String^ InputText;

   InputDialog(String^ prompt, String^ title, String^ defaultValue)
   {
       this->Text = title;
       this->Width = 300;
       this->Height = 150;
       this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog; // Fully qualify the enum
       this->StartPosition = FormStartPosition::CenterParent;
       this->MaximizeBox = false;
       this->MinimizeBox = false;

       promptLabel = gcnew Label();
       promptLabel->Text = prompt;
       promptLabel->Top = 10;
       promptLabel->Left = 10;
       promptLabel->Width = 260;
       this->Controls->Add(promptLabel);

       inputBox = gcnew TextBox();
       inputBox->Text = defaultValue;
       inputBox->Top = 40;
       inputBox->Left = 10;
       inputBox->Width = 260;
       this->Controls->Add(inputBox);

       okButton = gcnew Button();
       okButton->Text = "OK";
       okButton->Top = 75;
       okButton->Left = 200;
       okButton->DialogResult = System::Windows::Forms::DialogResult::OK;
       this->AcceptButton = okButton;
       this->Controls->Add(okButton);
   }

   static String^ Show(String^ prompt, String^ title, String^ defaultValue)
   {
       InputDialog^ dialog = gcnew InputDialog(prompt, title, defaultValue);
       if (dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
       {
           return dialog->inputBox->Text;
       }
       return nullptr;
   }
};
