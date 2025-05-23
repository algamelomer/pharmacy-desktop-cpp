# Pharmacy Desktop Management System

A professional and comprehensive desktop application for managing pharmacy operations, built in C++ using Windows Forms. This system streamlines daily activities including inventory, sales, suppliers, customers, and business reporting.

---

## ✨ Overview

This Pharmacy Management System is tailored for pharmacy staff to manage operations with greater efficiency, accuracy, and ease. Featuring a modern UI, the software automates routine tasks and minimizes manual errors, making it ideal for small to medium-sized pharmacies that require a dependable offline solution.

### 📈 Key Benefits

* **Centralized Management:** Seamlessly handle products, inventory, customers, suppliers, and transactions in one place.
* **Time Efficiency:** Automates repetitive processes such as inventory updates, billing, and report generation.
* **Enhanced Accuracy:** Significantly reduces errors in inventory tracking and sales.
* **Data Security:** Role-based access control and user authentication.
* **Business Insights:** In-app dashboard and reporting features support informed decision-making.

---

## 📝 Features

* **User Authentication:** Secure login with roles and permissions.
* **Product Management:** Full CRUD functionality with barcode scanning support.
* **Inventory Control:** Real-time tracking, low-stock alerts, and auto stock updates.
* **Category Management:** Easily group and manage product categories.
* **Supplier Management:** Record supplier information and purchase data.
* **Customer Management:** Manage and classify customers (e.g., VIP, regular).
* **Sales & Invoicing:** Generate and print receipts and invoices.
* **Returns Handling:** Manage product returns with automatic inventory adjustments.
* **Dashboard & Reporting:** Intuitive dashboard and detailed reports.
* **Offline Storage:** Uses SQLite for efficient local data handling.
* **Modern UI:** User-friendly interface with clean navigation and forms.

---

## 🔧 Technical Architecture

* **Language:** C++ (.NET Framework)
* **UI Framework:** Windows Forms
* **Database:** SQLite
* **Design Pattern:** MVC (Model-View-Controller)

---

## 📂 Project Structure

```
test/
├── Main.cpp                      # Entry point
├── Login.h / Login.cpp           # Login form
├── home.h / home.cpp             # Main dashboard
├── dashboard.h / dashboard.cpp   # Statistics dashboard
├── category.h / category.cpp     # Manage categories
├── inventory.h / inventory.cpp   # Inventory tracking
├── product.h / product.cpp       # Product CRUD
├── customer.h / customer.cpp     # Customer data management
├── SupplierDBManage.h/.cpp       # Supplier operations
├── ReceiptForm.h / ReceiptForm.cpp # Billing system
├── ReturnForm.h                  # Product returns
├── db.h / db.cpp                 # Database handling
├── Resources/                    # Icons and assets
├── x64/Debug/                    # Binaries and build output
```

---

## 📅 Core Models

```cpp
class Product {
    int Id;
    String^ Name;
    int CategoryId;
    int InventoryId;
    double Price;
    int Count;
    String^ Barcode;
};

class Category {
    int Id;
    String^ Name;
};

class Inventory {
    int Id;
    String^ Location;
};

class Sale {
    int Id;
    String^ Date;
    String^ CustomerName;
    String^ CustomerPhone;
};

class SaleItem {
    int Id;
    int SaleId;
    int ProductId;
    int Quantity;
    double total_price;
};

class Customer {
    int Id;
    String^ Name;
    String^ Phone;
};

class User {
    int Id;
    String^ Username;
    String^ Password;
};

class Supplier {
    int Id;
    String^ Name;
    String^ Company;
    String^ Description;
    String^ Phone;
};
```

---

## 🛠️ Controllers & Helpers

* **ProductDBHelper:** Manages product operations
* **CategoryDBHelper:** Handles category logic
* **InventoryDBHelper:** Tracks inventory actions
* **UserDBHelper:** Login and role validation
* **SupplierDBManage:** Supplier data operations
* **DBHelper:** Main class for SQLite connection and queries

---

## ⚖️ Workflow

1. **Login:** Secure authentication
2. **Dashboard:** Overview of sales and inventory
3. **Manage Products:** CRUD operations and barcode lookup
4. **Sales:** Add to invoice, calculate total, print receipt
5. **Returns:** Update inventory post-return
6. **Suppliers & Categories:** Manage records
7. **Inventory:** Track and update stock levels

---

## 📊 Database Schema

* `users`
* `categories`
* `inventory`
* `products`
* `customers`
* `sales`
* `sales_items`
* `suppliers`

---

## 📅 Requirements

* **OS:** Windows 7+
* **.NET Framework:** 4.5+
* **Storage:** 100 MB+
* **RAM:** 2 GB+

---

## 💻 Installation

1. Open `test.sln` in Visual Studio
2. Restore NuGet packages if prompted (System.Data.SQLite)
3. Build and run
4. On first launch, `pharmacy.db` is auto-created

---

## 🔍 Usage

* **Login:** Enter credentials to access the system
* **Dashboard:** View key metrics
* **Manage:** Products, categories, inventory, customers, suppliers
* **Sales:** Create, print, and track receipts
* **Reports:** Gain insights with built-in reports

---

## 👥 Contributing

We welcome contributions! Fork the repo, create a new branch, and submit a Pull Request with clear descriptions.
