#pragma once

using namespace System;
using namespace System::Collections::Generic;

public ref class Product
{
public:
    int Id;
    String^ Name;
    int CategoryId;
    int InventoryId;
    double Price;
    int Count;
    String^ Barcode;
};

public ref class ProductDBHelper
{
public:
    static bool AddProduct(Product^ product);
    static Product^ GetProductById(int id);
    static bool UpdateProduct(Product^ product);
    static bool DeleteProduct(int id);
    static List<Product^>^ SearchProductsByName(String^ partialName);
    static void InsertDummyData();

};
