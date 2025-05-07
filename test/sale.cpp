#include "Sale.h"
#include <chrono>
#include <ctime>
#include "db.h"
using namespace System::Data::SQLite;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;

int Sale::Add(Sale^ sale)
{
    String^ connString = "Data Source=pharmacy.db;Version=3;";
    SQLiteConnection^ conn = gcnew SQLiteConnection(connString);
    conn->Open();

    // Get current time and format as "yyyy-mm-dd"
    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    struct tm timeStruct;
    localtime_s(&timeStruct, &now);
    char buffer[80];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", &timeStruct);
    String^ currentDate = gcnew String(buffer);

    sale->Date = currentDate;

    String^ query = "INSERT INTO sales (date) VALUES (@date); SELECT last_insert_rowid();";
    SQLiteCommand^ cmd = gcnew SQLiteCommand(query, conn);
    cmd->Parameters->AddWithValue("@date", sale->Date);

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

    String^ query = "SELECT id, date FROM sales";
    SQLiteCommand^ cmd = gcnew SQLiteCommand(query, conn);
    SQLiteDataReader^ reader = cmd->ExecuteReader();

    while (reader->Read())
    {
        Sale^ s = gcnew Sale();
        s->Id = reader->GetInt32(0);
        s->Date = reader->GetString(1);
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

    String^ query = "SELECT id, date FROM sales WHERE id = @id";
    SQLiteCommand^ cmd = gcnew SQLiteCommand(query, conn);
    cmd->Parameters->AddWithValue("@id", id);
    SQLiteDataReader^ reader = cmd->ExecuteReader();

    if (reader->Read())
    {
        sale = gcnew Sale();
        sale->Id = reader->GetInt32(0);
        sale->Date = reader->GetString(1);
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

    String^ query = "UPDATE sales SET date = @date WHERE id = @id";
    SQLiteCommand^ cmd = gcnew SQLiteCommand(query, conn);
    cmd->Parameters->AddWithValue("@id", sale->Id);
    cmd->Parameters->AddWithValue("@date", sale->Date);

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
