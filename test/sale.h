#pragma once

using namespace System;
using namespace System::Collections::Generic;

public ref class Sale
{
public:
    int Id;
    double Total;
    String^ Date;
	String^ CustomerPhone;
	String^ CustomerName;

    // CRUD Operations
    static int Add(Sale^ sale);
    static List<Sale^>^ GetAll();
    static Sale^ GetById(int id);
    static bool Edit(Sale^ sale);
    static bool Delete(int id);
    static Sale^ GetByCustomerPhone(String^ phone);
};
