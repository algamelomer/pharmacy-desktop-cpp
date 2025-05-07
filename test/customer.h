#pragma once

using namespace System;

public ref class Customer
{
public:
    int Id;
    String^ Name;
    String^ Phone;

    static int AddOrGetId(String^ name, String^ phone);
    Customer(String^ name, String^ phone)
    {
        Name = name;
        Phone = phone;
    }
};
