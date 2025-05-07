#include "user.h"
#include "category.h"
#include "inventory.h"
#include "product.h"
#include "db.h"
using namespace System::IO;
using namespace System::Data::SQLite;

// Helper method to open a connection to the database
SQLiteConnection^ DBHelper::OpenConnection()
{
    String^ connStr = "Data Source=pharmacy.db;Version=3;";
    SQLiteConnection^ connection = gcnew SQLiteConnection(connStr);
    connection->Open();
    return connection;
}


void DBHelper::CreateDatabaseIfNotExists(String^ dbFile)
{
    if (!File::Exists(dbFile))
    {
        SQLiteConnection^ connection = OpenConnection();

        // Create users table
        String^ createUsers = "CREATE TABLE IF NOT EXISTS users ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
            "username TEXT NOT NULL, "
            "password TEXT NOT NULL);";
        SQLiteCommand^ command = gcnew SQLiteCommand(createUsers, connection);
        command->ExecuteNonQuery();

        // Default admin user
        String^ insertAdmin = "INSERT INTO users (username, password) VALUES ('admin', '1234');";
        command = gcnew SQLiteCommand(insertAdmin, connection);
        command->ExecuteNonQuery();

        // Create categories table
        String^ createCategories = "CREATE TABLE IF NOT EXISTS categories ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
            "name TEXT NOT NULL);";
        command = gcnew SQLiteCommand(createCategories, connection);
        command->ExecuteNonQuery();

        // Create inventory table
        String^ createInventory = "CREATE TABLE IF NOT EXISTS inventory ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
            "location TEXT NOT NULL);";
        command = gcnew SQLiteCommand(createInventory, connection);
        command->ExecuteNonQuery();

        // Create products table
        String^ createProducts = "CREATE TABLE IF NOT EXISTS products ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
            "name TEXT NOT NULL, "
            "category_id INTEGER, "
            "inventory_id INTEGER, "
            "price REAL NOT NULL, "
            "count INTEGER NOT NULL, "
            "barcode TEXT, "
            "FOREIGN KEY (category_id) REFERENCES categories(id) ON DELETE SET NULL, "
            "FOREIGN KEY (inventory_id) REFERENCES inventory(id) ON DELETE SET NULL);";

        command = gcnew SQLiteCommand(createProducts, connection);
        command->ExecuteNonQuery();

        // Create sales table
        String^ createSales = "CREATE TABLE IF NOT EXISTS sales ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
            "date TEXT NOT NULL);";
        command = gcnew SQLiteCommand(createSales, connection);
        command->ExecuteNonQuery();

        // Create sales_items table
        String^ createSalesItems = "CREATE TABLE IF NOT EXISTS sales_items ("
            "id INTEGER PRIMARY KEY AUTOINCREMENT, "
            "sale_id INTEGER NOT NULL, "
            "product_id INTEGER NOT NULL, "
            "quantity INTEGER NOT NULL, "
            "total_price REAL NOT NULL, "
            "FOREIGN KEY (sale_id) REFERENCES sales(id), "
            "FOREIGN KEY (product_id) REFERENCES products(id));";
        command = gcnew SQLiteCommand(createSalesItems, connection);
        command->ExecuteNonQuery();


        connection->Close();
    }
}

