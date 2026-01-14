# Ticket Management C++ App

This is a C++ console application that connects to a MySQL/MariaDB database to manage tickets.

C++ does **not have built-in support for MySQL**, so you need a **connector library** to communicate with the database. There are two main options:

- **MySQL Connector/C++** – Official connector from MySQL, works with C++17 and modern compilers.  
- **MariaDB Connector/C++** – Fully compatible with the MySQL protocol.

For this project, I am using **MySQL Connector/C++**.

---

## Prerequisites (Arch Linux)

1. MariaDB or MySQL installed (XAMPP or system installation).  
2. C++ compiler (`g++`) installed.  
3. MariaDB Connector/C installed (`mariadb-connector-c` package).

> Note: You do **not** need a separate MySQL C++ connector on Arch. The C API provided by MariaDB is sufficient.

---

## Compilation

1. Include the MySQL headers and link the MariaDB client library.  
2. Make sure the headers are in `/usr/include/mysql` and the library is `libmariadb`.  
3. Example compilation command:
```
g++ main.cpp -I/usr/include/mysql -L/usr/lib -lmariadb -o main
```

---

## Notes

- This setup works for **Arch Linux with XAMPP** without installing additional connectors.  
- All headers and libraries are provided by `mariadb-connector-c`.  
- You can manage users, tickets, and other tables using the provided C++ code with the MariaDB C API.


