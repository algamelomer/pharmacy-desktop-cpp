#pragma once

using namespace System;
using namespace System::Collections::Generic;

public ref class SaleItem
{
public:
    int Id;
    int SaleId;
    String^ ProductName;
    int Quantity;
    double Price;

    // CRUD Operations
    static int Add(SaleItem^ saleItem);
    static List<SaleItem^>^ GetAllBySaleId(int saleId);  // Correct declaration
    static SaleItem^ GetById(int id);
    static bool Edit(SaleItem^ saleItem);
    static bool Delete(int id);
};
