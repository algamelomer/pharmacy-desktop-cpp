#pragma once

using namespace System;

public ref class Inventory
{
public:
    int Id;
    String^ Location;
};

public ref class InventoryDBHelper
{
public:
    static bool AddInventory(Inventory^ inventory);
    static Inventory^ GetInventoryById(int id);
    static bool UpdateInventory(Inventory^ inventory);
    static bool DeleteInventory(int id);
};
