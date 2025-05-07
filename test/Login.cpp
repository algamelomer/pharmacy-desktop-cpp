#include "Login.h"
#include "home.h"
#include "db.h"
#include "user.h"

System::Void test::Login::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    String^ username = textBox1->Text;
    String^ password = textBox2->Text;

    if (username->Trim() == "" || password->Trim() == "") {
        MessageBox::Show("Please enter both username and password.", "Missing Information", MessageBoxButtons::OK, MessageBoxIcon::Warning);
        return;
    }

    if (!checkBox1->Checked) {
        MessageBox::Show("You must agree to the Terms and Conditions to continue.", "Terms Required", MessageBoxButtons::OK, MessageBoxIcon::Information);
        return;
    }

    if (UserDBHelper::ValidateUser(username, password)) {
        this->Hide();

        home^ homepage = gcnew home();
        homepage->ShowDialog();


        this->Close();
    }
    else {
        MessageBox::Show("Invalid username or password.", "Login Failed", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
}

System::Void test::Login::textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    if (textBox1->Text->Length < 3) {
        textBox1->ForeColor = System::Drawing::Color::Red;
    }
    else {
        textBox1->ForeColor = System::Drawing::Color::Black;
    }
}

System::Void test::Login::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    
}

System::Void test::Login::linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
    MessageBox::Show("By using this app, you agree to the following terms and conditions...", "Terms and Conditions", MessageBoxButtons::OK, MessageBoxIcon::Information);
}

System::Void test::Login::Login_Load(System::Object^ sender, System::EventArgs^ e) {
    
}