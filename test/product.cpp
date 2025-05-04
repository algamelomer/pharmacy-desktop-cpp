#include "product.h"
#include "db.h"
using namespace System::Data::SQLite;
using namespace System::Windows::Forms;

bool ProductDBHelper::AddProduct(Product^ product)
{
    SQLiteConnection^ conn = DBHelper::OpenConnection();
    try
    {
        String^ query = "INSERT INTO products (name, category_id, inventory_id, price, count, barcode) VALUES "
            "(@name, @cat, @inv, @price, @count, @barcode)";
        SQLiteCommand^ cmd = gcnew SQLiteCommand(query, conn);
        cmd->Parameters->AddWithValue("@name", product->Name);
        cmd->Parameters->AddWithValue("@cat", product->CategoryId);
        cmd->Parameters->AddWithValue("@inv", product->InventoryId);
        cmd->Parameters->AddWithValue("@price", product->Price);
        cmd->Parameters->AddWithValue("@count", product->Count);
        cmd->Parameters->AddWithValue("@barcode", product->Barcode);
        return cmd->ExecuteNonQuery() > 0;
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("AddProduct Error: " + ex->Message);
        return false;
    }
    finally
    {
        conn->Close();
    }
}

Product^ ProductDBHelper::GetProductById(int id)
{
    SQLiteConnection^ conn = DBHelper::OpenConnection();
    try
    {
        String^ query = "SELECT * FROM products WHERE id = @id";
        SQLiteCommand^ cmd = gcnew SQLiteCommand(query, conn);
        cmd->Parameters->AddWithValue("@id", id);
        SQLiteDataReader^ reader = cmd->ExecuteReader();
        if (reader->Read())
        {
            Product^ p = gcnew Product();
            p->Id = reader->GetInt32(0);
            p->Name = reader->GetString(1);
            p->CategoryId = reader->IsDBNull(2) ? -1 : reader->GetInt32(2);
            p->InventoryId = reader->IsDBNull(3) ? -1 : reader->GetInt32(3);
            p->Price = reader->GetDouble(4);
            p->Count = reader->GetInt32(5);
            p->Barcode = reader->IsDBNull(6) ? "" : reader->GetString(6);
            return p;
        }
        return nullptr;
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("GetProductById Error: " + ex->Message);
        return nullptr;
    }
    finally
    {
        conn->Close();
    }
}

bool ProductDBHelper::UpdateProduct(Product^ product)
{
    SQLiteConnection^ conn = DBHelper::OpenConnection();
    try
    {
        String^ query = "UPDATE products SET name=@name, category_id=@cat, inventory_id=@inv, "
            "price=@price, count=@count, barcode=@barcode WHERE id=@id";
        SQLiteCommand^ cmd = gcnew SQLiteCommand(query, conn);
        cmd->Parameters->AddWithValue("@name", product->Name);
        cmd->Parameters->AddWithValue("@cat", product->CategoryId);
        cmd->Parameters->AddWithValue("@inv", product->InventoryId);
        cmd->Parameters->AddWithValue("@price", product->Price);
        cmd->Parameters->AddWithValue("@count", product->Count);
        cmd->Parameters->AddWithValue("@barcode", product->Barcode);
        cmd->Parameters->AddWithValue("@id", product->Id);
        return cmd->ExecuteNonQuery() > 0;
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("UpdateProduct Error: " + ex->Message);
        return false;
    }
    finally
    {
        conn->Close();
    }
}

bool ProductDBHelper::DeleteProduct(int id)
{
    SQLiteConnection^ conn = DBHelper::OpenConnection();
    try
    {
        String^ query = "DELETE FROM products WHERE id = @id";
        SQLiteCommand^ cmd = gcnew SQLiteCommand(query, conn);
        cmd->Parameters->AddWithValue("@id", id);
        return cmd->ExecuteNonQuery() > 0;
    }
    catch (Exception^ ex)
    {
        MessageBox::Show("DeleteProduct Error: " + ex->Message);
        return false;
    }
    finally
    {
        conn->Close();
    }
}
