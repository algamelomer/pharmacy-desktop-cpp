#pragma once
#include "Supplier.h"
using namespace System::Collections::Generic;

public ref class SupplierDBManage {
public:
    static void InsertSupplier(Supplier^ supplier);
    static void UpdateSupplier(Supplier^ supplier);
    static void DeleteSupplier(int supplierId);
    static List<Supplier^>^ SearchSuppliers(String^ keyword);
    static void InsertDummySuppliers();
};