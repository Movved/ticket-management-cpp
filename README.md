# Ticket Management C++ App

This is a C++ console application that connects to a MySQL/MariaDB database to manage tickets.

C++ does **not have built-in support for MySQL**, so you need a **connector library** to communicate with the database. There are two main options:

- **MySQL Connector/C++** – Official connector from MySQL, works with C++17 and modern compilers.  
- **MariaDB Connector/C++** – Fully compatible with the MySQL protocol.

For this project, I am using **MySQL Connector/C++**.

---

## Prerequisites (Arch Linux)

1. Install MySQL Connector/c++. If in arch linux you can install it from the AUR :
```
yay -S mysql-connector-c++
```


---

## Compilation


```
g++ -std=c++14 *.cpp -Iinclude -lmysqlcppconn -o main 
```
## Compilation
```
./main
```
---

## Notes

- This setup works for **Arch Linux with XAMPP** without installing additional connectors.  
- All headers and libraries are provided by `mariadb-connector-c`.  
- You can manage users, tickets, and other tables using the provided C++ code with the MariaDB C API.


