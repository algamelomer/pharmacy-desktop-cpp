#include "inventory.h"
#include "db.h"

using namespace System::Data::SQLite;
using namespace System::Windows::Forms;
using namespace System;
using namespace System::Collections::Generic;

bool InventoryDBHelper::AddInventory(Inventory^ inventory)
{
    SQLiteConnection^ conn = DBHelper::OpenConnection();
    try
    {
        String^ query = "INSERT INTO inventory (location) VALUES (@location)";
        SQLiteCommand^ cmd = gcnew SQLiteCommand(query, conn);
        cmd->Parameters->AddWithValue("@location", inventory->Location);
        return cmd->ExecuteNonQuery() > 0;
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("AddInventory Error: " + ex->Message);
        return false;
    }
    finally
    {
        conn->Close();
    }
}

Inventory^ InventoryDBHelper::GetInventoryById(int id)
{
    SQLiteConnection^ conn = DBHelper::OpenConnection();
    try
    {
        String^ query = "SELECT * FROM inventory WHERE id = @id";
        SQLiteCommand^ cmd = gcnew SQLiteCommand(query, conn);
        cmd->Parameters->AddWithValue("@id", id);
        SQLiteDataReader^ reader = cmd->ExecuteReader();
        try {
            if (reader->Read())
            {
                Inventory^ inv = gcnew Inventory();
                inv->Id = reader->GetInt32(0);
                inv->Location = reader->GetString(1);
                return inv;
            }
            return nullptr;
        }
        finally {
            reader->Close();
        }
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("GetInventoryById Error: " + ex->Message);
        return nullptr;
    }
    finally
    {
        conn->Close();
    }
}

bool InventoryDBHelper::UpdateInventory(Inventory^ inventory)
{
    SQLiteConnection^ conn = DBHelper::OpenConnection();
    try
    {
        String^ query = "UPDATE inventory SET location = @location WHERE id = @id";
        SQLiteCommand^ cmd = gcnew SQLiteCommand(query, conn);
        cmd->Parameters->AddWithValue("@location", inventory->Location);
        cmd->Parameters->AddWithValue("@id", inventory->Id);
        return cmd->ExecuteNonQuery() > 0;
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("UpdateInventory Error: " + ex->Message);
        return false;
    }
    finally
    {
        conn->Close();
    }
}

bool InventoryDBHelper::DeleteInventory(int id)
{
    SQLiteConnection^ conn = DBHelper::OpenConnection();
    try
    {
        String^ query = "DELETE FROM inventory WHERE id = @id";
        SQLiteCommand^ cmd = gcnew SQLiteCommand(query, conn);
        cmd->Parameters->AddWithValue("@id", id);
        return cmd->ExecuteNonQuery() > 0;
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("DeleteInventory Error: " + ex->Message);
        return false;
    }
    finally
    {
        conn->Close();
    }
}

List<Inventory^>^ InventoryDBHelper::GetAllInventories()
{
	SQLiteConnection^ conn = DBHelper::OpenConnection();
	List<Inventory^>^ inventories = gcnew List<Inventory^>();
	try
	{
		String^ query = "SELECT * FROM inventory";
		SQLiteCommand^ cmd = gcnew SQLiteCommand(query, conn);
		SQLiteDataReader^ reader = cmd->ExecuteReader();
        try {
            while (reader->Read())
            {
                Inventory^ inv = gcnew Inventory();
                inv->Id = reader->GetInt32(0);
                inv->Location = reader->GetString(1);
                inventories->Add(inv);
            }
		}
        finally {
            reader->Close();
        }
	}
	catch (Exception^ ex)
	{
		MessageBox::Show("GetAllInventories Error: " + ex->Message);
	}
	finally
	{
		conn->Close();
	}
	return inventories;
}

void InventoryDBHelper::InsertDummyData()
{
	Inventory^ inv1 = gcnew Inventory();
	inv1->Location = "Main Warehouse";
	InventoryDBHelper::AddInventory(inv1);
	Inventory^ inv2 = gcnew Inventory();
	inv2->Location = "Branch Office";
	InventoryDBHelper::AddInventory(inv2);
}

List<Inventory^>^ InventoryDBHelper::SearchInventoriesByLocation(String^ partialLocation)
{
    List<Inventory^>^ results = gcnew List<Inventory^>();
    SQLiteConnection^ conn = DBHelper::OpenConnection();

    try
    {
        String^ query = "SELECT * FROM inventory WHERE location LIKE @location;";
        SQLiteCommand^ cmd = gcnew SQLiteCommand(query, conn);
        cmd->Parameters->AddWithValue("@location", "%" + partialLocation + "%");

        SQLiteDataReader^ reader = cmd->ExecuteReader();
        try
        {
            while (reader->Read())
            {
                Inventory^ inv = gcnew Inventory();
                inv->Id = reader->GetInt32(0);
                inv->Location = reader->GetString(1);
                results->Add(inv);
            }
        }
        finally
        {
            reader->Close();
        }
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("Search Error: " + ex->Message);
    }
    finally
    {
        conn->Close();
    }

    return results;
}