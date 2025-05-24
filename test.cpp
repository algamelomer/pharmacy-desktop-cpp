class Product {
    int Id
    String ^ Name
    int CategoryId
    int InventoryId
    double Price
    int Count
    String ^ Barcode
}


class Category {
    int Id
    String ^ Name
}


class Inventory {
    int Id
    String ^ Location
}


class Sale {
    int Id
    String ^ Date
    String ^ CustomerName
    String ^ CustomerPhone
}


class SaleItem {
    int Id
    int SaleId
    int ProductId
    int Quantity
    double total_price
}


class Customer {
    int Id
    String ^ Name
    String ^ Phone
}


class User {
    int Id
    String ^ Username
    String ^ Password
}


class Supplier {
    int Id
    String ^ Name
    String ^ Company
    String ^ Description
    String ^ Phone
}
