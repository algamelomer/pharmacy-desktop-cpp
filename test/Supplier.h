#pragma once
using namespace System;

public ref class Supplier {
public:
    int Id;
    String^ Name;
    String^ Company;
    String^ Description;
    String^ Phone;

    Supplier(int id, String^ name, String^ company, String^ description, String^ phone) {
        Id = id;
        Name = name;
        Company = company;
        Description = description;
        Phone = phone;
    }
};