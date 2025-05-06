#include "product.h"
#include "db.h"
using namespace System::Data::SQLite;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;

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

List<Product^>^ ProductDBHelper::SearchProductsByName(String^ partialName)
{
    List<Product^>^ results = gcnew List<Product^>();
    SQLiteConnection^ conn = DBHelper::OpenConnection();

    try
    {
        String^ query = "SELECT * FROM products WHERE name LIKE @name;";
        SQLiteCommand^ cmd = gcnew SQLiteCommand(query, conn);
        cmd->Parameters->AddWithValue("@name", "%" + partialName + "%");

        SQLiteDataReader^ reader = cmd->ExecuteReader();
        try
        {
            while (reader->Read())
            {
                Product^ product = gcnew Product();
                product->Id = reader->GetInt32(0);
                product->Name = reader->GetString(1);
                product->CategoryId = reader->GetInt32(2);
                product->InventoryId = reader->GetInt32(3);
                product->Price = reader->GetDouble(4);
                product->Count = reader->GetInt32(5);
                product->Barcode = reader->GetString(6);
                results->Add(product);
            }
		}
        finally {
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

void ProductDBHelper::InsertDummyData()
{
    List<Product^>^ dummyProducts = gcnew List<Product^>();

    Product^ p1 = gcnew Product();
    p1->Name = "Aspirin";
    p1->CategoryId = 1;
    p1->InventoryId = 1;
    p1->Price = 12.5;
    p1->Count = 50;
    p1->Barcode = "A123";
    dummyProducts->Add(p1);

    Product^ p2 = gcnew Product();
    p2->Name = "Amoxicillin";
    p2->CategoryId = 1;
    p2->InventoryId = 1;
    p2->Price = 20.0;
    p2->Count = 100;
    p2->Barcode = "A456";
    dummyProducts->Add(p2);

    Product^ p3 = gcnew Product();
    p3->Name = "Ibuprofen";
    p3->CategoryId = 1;
    p3->InventoryId = 1;
    p3->Price = 8.75;
    p3->Count = 70;
    p3->Barcode = "I789";
    dummyProducts->Add(p3);

    Product^ p4 = gcnew Product();
    p4->Name = "Paracetamol";
    p4->CategoryId = 1;
    p4->InventoryId = 1;
    p4->Price = 5.0;
    p4->Count = 200;
    p4->Barcode = "P321";
    dummyProducts->Add(p4);

    Product^ p5 = gcnew Product();
    p5->Name = "Vitamin C";
    p5->CategoryId = 1;
    p5->InventoryId = 1;
    p5->Price = 15.0;
    p5->Count = 80;
    p5->Barcode = "V654";
    dummyProducts->Add(p5);

    // Add to DB
    for each (Product ^ p in dummyProducts)
    {
        AddProduct(p);
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
        try{
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
        finally {
            reader->Close();
        }
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
		int rowsAffected = cmd->ExecuteNonQuery();
        return rowsAffected;
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
