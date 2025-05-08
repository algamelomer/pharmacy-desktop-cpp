#include "SupplierDBManage.h"
#include "Supplier.h"
#include "db.h"

void SupplierDBManage::InsertSupplier(Supplier^ supplier) {
    SQLiteConnection^ conn = DBHelper::OpenConnection();
    String^ query = "INSERT INTO suppliers (name, company, description, phone) VALUES (@name, @company, @description, @phone)";
    SQLiteCommand^ cmd = gcnew SQLiteCommand(query, conn);
    cmd->Parameters->AddWithValue("@name", supplier->Name);
    cmd->Parameters->AddWithValue("@company", supplier->Company);
    cmd->Parameters->AddWithValue("@description", supplier->Description);
    cmd->Parameters->AddWithValue("@phone", supplier->Phone);
    cmd->ExecuteNonQuery();
    conn->Close();
}

void SupplierDBManage::UpdateSupplier(Supplier^ supplier) {
    SQLiteConnection^ conn = DBHelper::OpenConnection();
    String^ query = "UPDATE suppliers SET name=@name, company=@company, description=@description, phone=@phone WHERE id=@id";
    SQLiteCommand^ cmd = gcnew SQLiteCommand(query, conn);
    cmd->Parameters->AddWithValue("@name", supplier->Name);
    cmd->Parameters->AddWithValue("@company", supplier->Company);
    cmd->Parameters->AddWithValue("@description", supplier->Description);
    cmd->Parameters->AddWithValue("@phone", supplier->Phone);
    cmd->Parameters->AddWithValue("@id", supplier->Id);
    cmd->ExecuteNonQuery();
    conn->Close();
}

void SupplierDBManage::DeleteSupplier(int supplierId) {
    SQLiteConnection^ conn = DBHelper::OpenConnection();
    String^ query = "DELETE FROM suppliers WHERE id=@id";
    SQLiteCommand^ cmd = gcnew SQLiteCommand(query, conn);
    cmd->Parameters->AddWithValue("@id", supplierId);
    cmd->ExecuteNonQuery();
    conn->Close();
}

List<Supplier^>^ SupplierDBManage::SearchSuppliers(String^ keyword) {
    List<Supplier^>^ suppliers = gcnew List<Supplier^>();
    SQLiteConnection^ conn = DBHelper::OpenConnection();
    String^ query = "SELECT * FROM suppliers WHERE name LIKE @keyword OR company LIKE @keyword OR phone LIKE @keyword";
    SQLiteCommand^ cmd = gcnew SQLiteCommand(query, conn);
    cmd->Parameters->AddWithValue("@keyword", "%" + keyword + "%");
    SQLiteDataReader^ reader = cmd->ExecuteReader();
    while (reader->Read()) {
        Supplier^ s = gcnew Supplier(
            Convert::ToInt32(reader["id"]),
            reader["name"]->ToString(),
            reader["company"]->ToString(),
            reader["description"]->ToString(),
            reader["phone"]->ToString()
        );
        suppliers->Add(s);
    }
    conn->Close();
    return suppliers;
}

void SupplierDBManage::InsertDummySuppliers() {
    List<Supplier^>^ dummySuppliers = gcnew List<Supplier^>();

    Supplier^ s1 = gcnew Supplier(0, "Ahmed Ali", "HealthCo", "Medical equipment supplier", "01012345678");
    Supplier^ s2 = gcnew Supplier(0, "Sara Nabil", "MediLife", "Pharmaceutical distributor", "01087654321");
    Supplier^ s3 = gcnew Supplier(0, "Mohamed Saeed", "BioCare", "Supplier of supplements", "01123456789");

    dummySuppliers->Add(s1);
    dummySuppliers->Add(s2);
    dummySuppliers->Add(s3);

    for each (Supplier ^ s in dummySuppliers) {
        // Avoid duplicate phone numbers
        List<Supplier^>^ existing = SearchSuppliers(s->Phone);
        if (existing->Count == 0) {
            InsertSupplier(s);
        }
    }
}


