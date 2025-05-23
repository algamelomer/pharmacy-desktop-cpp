# Pharmacy Desktop Management System

A comprehensive desktop application for pharmacy management, developed in C++ using Windows Forms. The system is designed to streamline daily pharmacy operations, including inventory, sales, suppliers, customers, and reporting.

## Overview

This project is a full-featured Pharmacy Management System intended for use by pharmacy staff to efficiently manage all aspects of pharmacy operations. The application provides a modern, user-friendly interface and automates many manual processes, reducing errors and saving time. It is suitable for small to medium-sized pharmacies seeking a reliable, offline solution.

### Key Benefits
- **Centralized Management:** All pharmacy data (products, customers, suppliers, sales, inventory) is managed in one place.
- **Efficiency:** Automates repetitive tasks such as stock updates, billing, and reporting.
- **Accuracy:** Reduces human error in inventory and sales management.
- **Security:** User authentication ensures only authorized personnel can access sensitive data.
- **Insights:** Built-in dashboard and reports help in making informed business decisions.

## Main Features

- **User Management:** Secure login system with user roles and permissions.
- **Product Management:** Add, edit, delete, and categorize medicines and products, with barcode support.
- **Inventory Control:** Real-time stock tracking, low-stock alerts, and automatic updates after sales/purchases.
- **Category Management:** Organize products into customizable categories.
- **Supplier Management:** Manage supplier details and purchase transactions.
- **Customer Management:** Store customer information and classify by type (e.g., regular, VIP).
- **Sales & Billing:** Generate, print, and manage sales receipts and invoices.
- **Returns Management:** Handle product returns and automatically update inventory.
- **Dashboard & Reports:** Visual dashboard for quick statistics and detailed business reports.
- **Database Integration:** Uses SQLite for fast, local data storage.
- **Modern UI:** Intuitive navigation and forms for ease of use.

## Technical Architecture
- **Programming Language:** C++ with .NET Framework
- **UI Framework:** Windows Forms
- **Database:** SQLite
- **Design Pattern:** Follows the MVC (Model-View-Controller) pattern

## Project Structure & File Descriptions

```
test/
├── Main.cpp                # Application entry point; initializes and runs the main form.
├── Login.h / Login.cpp     # Login form and logic for user authentication.
├── home.h / home.cpp       # Main dashboard/home screen after login.
├── dashboard.h / dashboard.cpp # Analytics dashboard showing sales, inventory, and other statistics.
├── category.h / category.cpp    # Manage product categories (add, edit, delete categories).
├── inventory.h / inventory.cpp  # Inventory management (stock tracking, updates, alerts).
├── product.h / product.cpp      # Product/medicine management (CRUD operations for products).
├── customer.h / customer.cpp    # Customer management (add, edit, delete, classify customers).
├── SupplierDBManage.h / SupplierDBManage.cpp # Supplier management (details, purchase records).
├── ReceiptForm.h / ReceiptForm.cpp # Sales receipt and billing (generate and print receipts).
├── ReturnForm.h                # Handle product returns and update inventory.
├── db.h / db.cpp           # Handles all SQLite database operations (CRUD, queries, connection).
├── Resources/              # Images and static resources (e.g., medicine icons).
├── x64/Debug/              # Build output and binaries.
├── ...                     # Other forms and dialogs (e.g., profile, dialogs for editing/adding data).
```

### Main Components

#### 1. Entry Point
- **Main.cpp:** Initializes the database and launches the login form.

#### 2. Database Layer
- **db.h / db.cpp:** Contains the DBHelper class for database creation, connection, and CRUD operations.
- **Tables:**
  - `users`: Stores user credentials
  - `categories`: Product categories
  - `inventory`: Inventory locations
  - `products`: Product details
  - `customers`: Customer information
  - `sales`: Sales transactions
  - `sales_items`: Items in each sale
  - `suppliers`: Supplier information

#### 3. User Interface Forms
- **Login:** User authentication
- **Home:** Main navigation and quick access
- **Dashboard:** Overview and statistics
- **ProductForm:** Manage products (add, edit, delete, search)
- **InventoryForm:** Manage inventory locations and stock
- **CategoryForm:** Manage product categories
- **SupplierForm:** Manage suppliers
- **ReceiptForm:** Sales and billing
- **ReturnForm:** Handle product returns

#### 4. Core Models
- **Product:**
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
  ```
- **Category:**
  ```cpp
  class Category {
      int Id;
      String^ Name;
  };
  ```
- **Inventory:**
  ```cpp
  class Inventory {
      int Id;
      String^ Location;
  };
  ```
- **Sale:**
  ```cpp
  class Sale {
      int Id;
      String^ Date;
      String^ CustomerName;
      String^ CustomerPhone;
  };
  ```
- **SaleItem:**
  ```cpp
  class SaleItem {
      int Id;
      int SaleId;
      int ProductId;
      int Quantity;
      double total_price;
  };
  ```
- **Customer:**
  ```cpp
  class Customer {
      int Id;
      String^ Name;
      String^ Phone;
  };
  ```
- **User:**
  ```cpp
  class User {
      int Id;
      String^ Username;
      String^ Password;
  };
  ```
- **Supplier:**
  ```cpp
  class Supplier {
      int Id;
      String^ Name;
      String^ Company;
      String^ Description;
      String^ Phone;
  };
  ```

#### 5. Controllers/Helpers
- **ProductDBHelper:** Handles product database operations
- **CategoryDBHelper:** Handles category database operations
- **InventoryDBHelper:** Handles inventory database operations
- **UserDBHelper:** Handles authentication and user data
- **SupplierDBManage:** Handles supplier database operations
- **DBHelper:** Core class for database connection and setup

## Workflow

1. **Login:** User enters credentials, validated by UserDBHelper. On success, user is directed to the Home screen.
2. **Product Management:** Search, add, edit, or delete products. Barcode support for quick lookup.
3. **Sales:** Create new invoices, select customer type, add products, set quantities, auto-calculate totals, print or save invoice.
4. **Returns:** Select returned products, set return quantities, inventory auto-updated.
5. **Suppliers:** Add, edit, search, or delete suppliers.
6. **Inventory:** Add/edit inventory locations, update stock, search inventory.
7. **Categories:** Add/edit/delete product categories.

## Database Schema
- **users:** User credentials
- **categories:** Product categories
- **inventory:** Inventory locations
- **products:** Product details
- **customers:** Customer information
- **sales:** Sales transactions
- **sales_items:** Items in each sale
- **suppliers:** Supplier information

## System Requirements
- **Operating System:** Windows 7 or later
- **.NET Framework:** 4.5 or later
- **Storage:** 100 MB minimum
- **RAM:** 2 GB minimum

## Installation & Setup
1. Open `test.sln` in Visual Studio.
2. Restore NuGet packages if prompted (System.Data.SQLite is included in `packages/`).
3. Build the solution.
4. Run the application. On first run, the database (`pharmacy.db`) will be created automatically.

## Usage

- **Login:** Start by logging in with your credentials.
- **Dashboard:** View key statistics and quick links.
- **Products:** Manage medicines and categories.
- **Inventory:** Monitor and update stock levels.
- **Suppliers:** Add or update supplier information.
- **Customers:** Manage customer data and types.
- **Sales:** Process sales, print receipts, and view sales history.


## Contribution

Contributions and suggestions are welcome! Please open an Issue or Pull Request.



---
