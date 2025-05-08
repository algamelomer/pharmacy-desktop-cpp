#include "category.h"
#include "db.h"

using namespace System::Data::SQLite;
using namespace System::Windows::Forms;
using namespace System;
using namespace System::Collections::Generic;

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
        try {
            if (reader->Read())
            {
                Category^ c = gcnew Category();
                c->Id = reader->GetInt32(0);
                c->Name = reader->GetString(1);
                return c;
            }
            return nullptr;
        }
        finally {
            reader->Close();
        }
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

List<Category^>^ CategoryDBHelper::SearchCategoriesByName(String^ partialName)
{
    List<Category^>^ results = gcnew List<Category^>();
    SQLiteConnection^ conn = DBHelper::OpenConnection();

    try
    {
        String^ query = "SELECT * FROM categories WHERE name LIKE @name;";
        SQLiteCommand^ cmd = gcnew SQLiteCommand(query, conn);
        cmd->Parameters->AddWithValue("@name", "%" + partialName + "%");

        SQLiteDataReader^ reader = cmd->ExecuteReader();
        try
        {
            while (reader->Read())
            {
                Category^ category = gcnew Category();
                category->Id = reader->GetInt32(0);
                category->Name = reader->GetString(1);
                results->Add(category);
            }
        }
        finally
        {
            reader->Close();
        }
    }
    catch (Exception^ ex)
    {
        System::Windows::Forms::MessageBox::Show("Search Error: " + ex->Message);
    }
    finally
    {
        conn->Close();
    }

    return results;
}

List<Category^>^ CategoryDBHelper::GetAllCategories()
{
	SQLiteConnection^ conn = DBHelper::OpenConnection();
	List<Category^>^ categories = gcnew List<Category^>();
	try
	{
		String^ query = "SELECT * FROM categories";
		SQLiteCommand^ cmd = gcnew SQLiteCommand(query, conn);
		SQLiteDataReader^ reader = cmd->ExecuteReader();
		
        try {
            while (reader->Read())
            {
                Category^ c = gcnew Category();
                c->Id = reader->GetInt32(0);
                c->Name = reader->GetString(1);
                categories->Add(c);
            }
        }
        finally {
            reader->Close();
        }
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("GetAllCategories Error: " + ex->Message);
	}
	finally
	{

		conn->Close();
	}
	return categories;
}


void CategoryDBHelper::InsertDummyData()
{
    SQLiteConnection^ conn = DBHelper::OpenConnection();
    try
    {
        String^ query = "INSERT INTO categories (name) VALUES (@name)";
        SQLiteCommand^ cmd = gcnew SQLiteCommand(query, conn);

        // List of medical categories
        array<String^>^ medicalCategories = gcnew array<String^> {
            "Cardiology",
                "Neurology",
                "Pediatrics",
                "Orthopedics",
                "Dermatology",
                "Oncology",
                "Radiology",
                "Psychiatry",
                "Gynecology",
                "Urology"
        };

        for each (String ^ category in medicalCategories)
        {
            cmd->Parameters->Clear(); // Clear parameters for each iteration
            cmd->Parameters->AddWithValue("@name", category);
            cmd->ExecuteNonQuery();
        }
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("InsertDummyData Error: " + ex->Message);
    }
    finally
    {
        conn->Close();
    }
}