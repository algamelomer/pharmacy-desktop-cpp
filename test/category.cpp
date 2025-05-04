#include "category.h"
#include "db.h"

using namespace System::Data::SQLite;
using namespace System::Windows::Forms;

bool CategoryDBHelper::AddCategory(Category^ category)
{
    SQLiteConnection^ conn = DBHelper::OpenConnection();
    try
    {
        String^ query = "INSERT INTO categories (name) VALUES (@name)";
        SQLiteCommand^ cmd = gcnew SQLiteCommand(query, conn);
        cmd->Parameters->AddWithValue("@name", category->Name);
        return cmd->ExecuteNonQuery() > 0;
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("AddCategory Error: " + ex->Message);
        return false;
    }
    finally
    {
        conn->Close();
    }
}

Category^ CategoryDBHelper::GetCategoryById(int id)
{
    SQLiteConnection^ conn = DBHelper::OpenConnection();
    try
    {
        String^ query = "SELECT * FROM categories WHERE id = @id";
        SQLiteCommand^ cmd = gcnew SQLiteCommand(query, conn);
        cmd->Parameters->AddWithValue("@id", id);
        SQLiteDataReader^ reader = cmd->ExecuteReader();
        if (reader->Read())
        {
            Category^ c = gcnew Category();
            c->Id = reader->GetInt32(0);
            c->Name = reader->GetString(1);
            return c;
        }
        return nullptr;
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("GetCategoryById Error: " + ex->Message);
        return nullptr;
    }
    finally
    {
        conn->Close();
    }
}

bool CategoryDBHelper::UpdateCategory(Category^ category)
{
    SQLiteConnection^ conn = DBHelper::OpenConnection();
    try
    {
        String^ query = "UPDATE categories SET name = @name WHERE id = @id";
        SQLiteCommand^ cmd = gcnew SQLiteCommand(query, conn);
        cmd->Parameters->AddWithValue("@name", category->Name);
        cmd->Parameters->AddWithValue("@id", category->Id);
        return cmd->ExecuteNonQuery() > 0;
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("UpdateCategory Error: " + ex->Message);
        return false;
    }
    finally
    {
        conn->Close();
    }
}

bool CategoryDBHelper::DeleteCategory(int id)
{
    SQLiteConnection^ conn = DBHelper::OpenConnection();
    try
    {
        String^ query = "DELETE FROM categories WHERE id = @id";
        SQLiteCommand^ cmd = gcnew SQLiteCommand(query, conn);
        cmd->Parameters->AddWithValue("@id", id);
        return cmd->ExecuteNonQuery() > 0;
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("DeleteCategory Error: " + ex->Message);
        return false;
    }
    finally
    {
        conn->Close();
    }
}
