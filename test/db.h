#pragma once
using namespace System;
using namespace System::Data::SQLite;

public ref class DBHelper
{
public:
    static void CreateDatabaseIfNotExists(String^ dbFile);
    static SQLiteConnection^ OpenConnection();
};
