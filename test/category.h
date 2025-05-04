#pragma once

using namespace System;

public ref class Category
{
public:
    int Id;
    String^ Name;
};

public ref class CategoryDBHelper
{
public:
    static bool AddCategory(Category^ category);
    static Category^ GetCategoryById(int id);
    static bool UpdateCategory(Category^ category);
    static bool DeleteCategory(int id);
};
