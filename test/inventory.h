#pragma once

using namespace System;
using namespace System::Collections::Generic;

public ref class Inventory
{
public:
    int Id;
    String^ Location;
    String^ ToString() override
    {
        return Location;
    }
};

public ref class InventoryDBHelper
{
public:
    static bool AddInventory(Inventory^ inventory);
    static Inventory^ GetInventoryById(int id);
    static bool UpdateInventory(Inventory^ inventory);
    static bool DeleteInventory(int id);
    static System::Collections::Generic::List<Inventory^>^ GetAllInventories();
    static void InsertDummyData();
    static List<Inventory^>^ SearchInventoriesByLocation(String^ partialLocation);

};
