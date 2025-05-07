#include "Customer.h"
using namespace System::Data::SQLite;

int Customer::AddOrGetId(String^ name, String^ phone)
{
    String^ connString = "Data Source=pharmacy.db;Version=3;";
    SQLiteConnection^ conn = gcnew SQLiteConnection(connString);
    conn->Open();

    // Try to get existing customer
    String^ selectQuery = "SELECT id FROM customers WHERE phone = @phone";
    SQLiteCommand^ selectCmd = gcnew SQLiteCommand(selectQuery, conn);
    selectCmd->Parameters->AddWithValue("@phone", phone);
    Object^ result = selectCmd->ExecuteScalar();

    if (result != nullptr) {
        conn->Close();
        return Convert::ToInt32(result);
    }

    // Insert new customer
    String^ insertQuery = "INSERT INTO customers (name, phone) VALUES (@name, @phone); SELECT last_insert_rowid();";
    SQLiteCommand^ insertCmd = gcnew SQLiteCommand(insertQuery, conn);
    insertCmd->Parameters->AddWithValue("@name", name);
    insertCmd->Parameters->AddWithValue("@phone", phone);
    int customerId = Convert::ToInt32(insertCmd->ExecuteScalar());

    conn->Close();
    return customerId;
}
