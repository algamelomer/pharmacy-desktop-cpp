#pragma once

using namespace System;
using namespace System::Collections::Generic;

public ref class Category
{
public:
   int Id;
   String^ Name;
   String^ ToString() override
   {
       return Name;
   }
};

public ref class CategoryDBHelper
{
public:
   static bool AddCategory(Category^ category);
   static Category^ GetCategoryById(int id);
   static bool UpdateCategory(Category^ category);
   static bool DeleteCategory(int id);
   static List<Category^>^ SearchCategoriesByName(String^ partialName);
   static System::Collections::Generic::List<Category^>^ GetAllCategories();
   static void InsertDummyData();

};
