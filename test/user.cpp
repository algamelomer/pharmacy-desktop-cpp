#include "db.h"
#include "user.h"

bool UserDBHelper::ValidateUser(String^ username, String^ password)
{
    SQLiteConnection^ conn = DBHelper::OpenConnection();
    try
    {
        String^ query = "SELECT COUNT(*) FROM users WHERE username = @user AND password = @pass";
        SQLiteCommand^ cmd = gcnew SQLiteCommand(query, conn);
        cmd->Parameters->AddWithValue("@user", username);
        cmd->Parameters->AddWithValue("@pass", password);
        int count = Convert::ToInt32(cmd->ExecuteScalar());
        return (count > 0);
    }
    catch (Exception^ ex)
    {
        System::Windows::Forms::MessageBox::Show("DB Error: " + ex->Message);
        return false;
    }
    finally
    {
        conn->Close();
    }
}
