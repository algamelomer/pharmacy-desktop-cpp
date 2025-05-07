#pragma once

using namespace System;
using namespace System::Collections::Generic;

public ref class Sale
{
public:
    int Id;
    String^ Date;

    // CRUD Operations
    static int Add(Sale^ sale);
    static List<Sale^>^ GetAll();
    static Sale^ GetById(int id);
    static bool Edit(Sale^ sale);
    static bool Delete(int id);
};
