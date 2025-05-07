#include "Sale.h"
#include "Customer.h"
#include <chrono>
#include <ctime>

using namespace System::Data::SQLite;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;

int Sale::Add(Sale^ sale)
{
    String^ connString = "Data Source=pharmacy.db;Version=3;";
    SQLiteConnection^ conn = gcnew SQLiteConnection(connString);
    conn->Open();

    // Get current time and format as yyyy-mm-dd
    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    struct tm timeStruct;
    localtime_s(&timeStruct, &now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", &timeStruct);
    sale->Date = gcnew String(buffer);

    // Get or insert customer
    int customerId = Customer::AddOrGetId(sale->CustomerName, sale->CustomerPhone);

    // Insert sale
    String^ query = "INSERT INTO sales (date, customer_id) VALUES (@date, @customer_id); SELECT last_insert_rowid();";
    SQLiteCommand^ cmd = gcnew SQLiteCommand(query, conn);
    cmd->Parameters->AddWithValue("@date", sale->Date);
    cmd->Parameters->AddWithValue("@customer_id", customerId);

    int saleId = Convert::ToInt32(cmd->ExecuteScalar());
    conn->Close();
    return saleId;
}

List<Sale^>^ Sale::GetAll()
{
    List<Sale^>^ sales = gcnew List<Sale^>();
    String^ connString = "Data Source=pharmacy.db;Version=3;";
    SQLiteConnection^ conn = gcnew SQLiteConnection(connString);
    conn->Open();

    String^ query = "SELECT s.id, s.date, c.phone, c.name FROM sales s LEFT JOIN customers c ON s.customer_id = c.id";
    SQLiteCommand^ cmd = gcnew SQLiteCommand(query, conn);
    SQLiteDataReader^ reader = cmd->ExecuteReader();

    while (reader->Read())
    {
        Sale^ s = gcnew Sale();
        s->Id = reader->GetInt32(0);
        s->Date = reader->GetString(1);
        s->CustomerPhone = reader->IsDBNull(2) ? "" : reader->GetString(2);
        s->CustomerName = reader->IsDBNull(3) ? "" : reader->GetString(3);
        sales->Add(s);
    }

    reader->Close();
    conn->Close();
    return sales;
}

Sale^ Sale::GetById(int id)
{
    Sale^ sale = nullptr;
    String^ connString = "Data Source=pharmacy.db;Version=3;";
    SQLiteConnection^ conn = gcnew SQLiteConnection(connString);
    conn->Open();

    String^ query = "SELECT s.id, s.date, c.phone, c.name FROM sales s LEFT JOIN customers c ON s.customer_id = c.id WHERE s.id = @id";
    SQLiteCommand^ cmd = gcnew SQLiteCommand(query, conn);
    cmd->Parameters->AddWithValue("@id", id);
    SQLiteDataReader^ reader = cmd->ExecuteReader();

    if (reader->Read())
    {
        sale = gcnew Sale();
        sale->Id = reader->GetInt32(0);
        sale->Date = reader->GetString(1);
        sale->CustomerPhone = reader->IsDBNull(2) ? "" : reader->GetString(2);
        sale->CustomerName = reader->IsDBNull(3) ? "" : reader->GetString(3);
    }

    reader->Close();
    conn->Close();
    return sale;
}

bool Sale::Edit(Sale^ sale)
{
    String^ connString = "Data Source=pharmacy.db;Version=3;";
    SQLiteConnection^ conn = gcnew SQLiteConnection(connString);
    conn->Open();

    // Update customer or insert if not exists
    int customerId = Customer::AddOrGetId(sale->CustomerName, sale->CustomerPhone);

    String^ query = "UPDATE sales SET date = @date, customer_id = @customer_id WHERE id = @id";
    SQLiteCommand^ cmd = gcnew SQLiteCommand(query, conn);
    cmd->Parameters->AddWithValue("@id", sale->Id);
    cmd->Parameters->AddWithValue("@date", sale->Date);
    cmd->Parameters->AddWithValue("@customer_id", customerId);

    int rowsAffected = cmd->ExecuteNonQuery();
    conn->Close();
    return rowsAffected > 0;
}

bool Sale::Delete(int id)
{
    String^ connString = "Data Source=pharmacy.db;Version=3;";
    SQLiteConnection^ conn = gcnew SQLiteConnection(connString);
    conn->Open();

    String^ query = "DELETE FROM sales WHERE id = @id";
    SQLiteCommand^ cmd = gcnew SQLiteCommand(query, conn);
    cmd->Parameters->AddWithValue("@id", id);

    int rowsAffected = cmd->ExecuteNonQuery();
    conn->Close();
    return rowsAffected > 0;
}

Sale^ Sale::GetByCustomerPhone(String^ phone)
{
    Sale^ sale = nullptr;
    String^ connString = "Data Source=pharmacy.db;Version=3;";
    SQLiteConnection^ conn = gcnew SQLiteConnection(connString);
    conn->Open();

    String^ query = "SELECT s.id, s.date, c.phone, c.name FROM sales s LEFT JOIN customers c ON s.customer_id = c.id WHERE c.phone = @phone LIMIT 1";
    SQLiteCommand^ cmd = gcnew SQLiteCommand(query, conn);
    cmd->Parameters->AddWithValue("@phone", phone);
    SQLiteDataReader^ reader = cmd->ExecuteReader();

    if (reader->Read())
    {
        sale = gcnew Sale();
        sale->Id = reader->GetInt32(0);
        sale->Date = reader->GetString(1);
        sale->CustomerPhone = reader->IsDBNull(2) ? "" : reader->GetString(2);
        sale->CustomerName = reader->IsDBNull(3) ? "" : reader->GetString(3);
    }

    reader->Close();
    conn->Close();
    return sale;
}
