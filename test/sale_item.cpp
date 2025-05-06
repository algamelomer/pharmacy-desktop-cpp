#include "sale_item.h"
#include "db.h"

using namespace System::Data::SQLite;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;

int SaleItem::Add(SaleItem^ saleItem)
{
    String^ connString = "Data Source=pharmacy.db;Version=3;";
    SQLiteConnection^ conn = gcnew SQLiteConnection(connString);
    conn->Open();

    String^ query = "INSERT INTO sale_items (sale_id, product_name, quantity, price) VALUES (@sale_id, @product_name, @quantity, @price); SELECT last_insert_rowid();";
    SQLiteCommand^ cmd = gcnew SQLiteCommand(query, conn);
    cmd->Parameters->AddWithValue("@sale_id", saleItem->SaleId);
    cmd->Parameters->AddWithValue("@product_name", saleItem->ProductName);
    cmd->Parameters->AddWithValue("@quantity", saleItem->Quantity);
    cmd->Parameters->AddWithValue("@price", saleItem->Price);

    int saleItemId = Convert::ToInt32(cmd->ExecuteScalar());
    conn->Close();
    return saleItemId;
}

List<SaleItem^>^ SaleItem::GetAllBySaleId(int saleId)  // Correct definition
{
    List<SaleItem^>^ saleItems = gcnew List<SaleItem^>();
    String^ connString = "Data Source=pharmacy.db;Version=3;";
    SQLiteConnection^ conn = gcnew SQLiteConnection(connString);
    conn->Open();

    String^ query = "SELECT id, sale_id, product_name, quantity, price FROM sale_items WHERE sale_id = @sale_id";
    SQLiteCommand^ cmd = gcnew SQLiteCommand(query, conn);
    cmd->Parameters->AddWithValue("@sale_id", saleId);
    SQLiteDataReader^ reader = cmd->ExecuteReader();

    while (reader->Read())
    {
        SaleItem^ item = gcnew SaleItem();
        item->Id = reader->GetInt32(0);
        item->SaleId = reader->GetInt32(1);
        item->ProductName = reader->GetString(2);
        item->Quantity = reader->GetInt32(3);
        item->Price = reader->GetDouble(4);
        saleItems->Add(item);
    }

    reader->Close();
    conn->Close();
    return saleItems;
}

SaleItem^ SaleItem::GetById(int id)
{
    SaleItem^ saleItem = nullptr;
    String^ connString = "Data Source=pharmacy.db;Version=3;";
    SQLiteConnection^ conn = gcnew SQLiteConnection(connString);
    conn->Open();

    String^ query = "SELECT id, sale_id, product_name, quantity, price FROM sale_items WHERE id = @id";
    SQLiteCommand^ cmd = gcnew SQLiteCommand(query, conn);
    cmd->Parameters->AddWithValue("@id", id);
    SQLiteDataReader^ reader = cmd->ExecuteReader();

    if (reader->Read())
    {
        saleItem = gcnew SaleItem();
        saleItem->Id = reader->GetInt32(0);
        saleItem->SaleId = reader->GetInt32(1);
        saleItem->ProductName = reader->GetString(2);
        saleItem->Quantity = reader->GetInt32(3);
        saleItem->Price = reader->GetDouble(4);
    }

    reader->Close();
    conn->Close();
    return saleItem;
}

bool SaleItem::Edit(SaleItem^ saleItem)
{
    String^ connString = "Data Source=pharmacy.db;Version=3;";
    SQLiteConnection^ conn = gcnew SQLiteConnection(connString);
    conn->Open();

    String^ query = "UPDATE sale_items SET sale_id = @sale_id, product_name = @product_name, quantity = @quantity, price = @price WHERE id = @id";
    SQLiteCommand^ cmd = gcnew SQLiteCommand(query, conn);
    cmd->Parameters->AddWithValue("@id", saleItem->Id);
    cmd->Parameters->AddWithValue("@sale_id", saleItem->SaleId);
    cmd->Parameters->AddWithValue("@product_name", saleItem->ProductName);
    cmd->Parameters->AddWithValue("@quantity", saleItem->Quantity);
    cmd->Parameters->AddWithValue("@price", saleItem->Price);

    int rowsAffected = cmd->ExecuteNonQuery();
    conn->Close();
    return rowsAffected > 0;
}

bool SaleItem::Delete(int id)
{
    String^ connString = "Data Source=pharmacy.db;Version=3;";
    SQLiteConnection^ conn = gcnew SQLiteConnection(connString);
    conn->Open();

    String^ query = "DELETE FROM sale_items WHERE id = @id";
    SQLiteCommand^ cmd = gcnew SQLiteCommand(query, conn);
    cmd->Parameters->AddWithValue("@id", id);

    int rowsAffected = cmd->ExecuteNonQuery();
    conn->Close();
    return rowsAffected > 0;
}
