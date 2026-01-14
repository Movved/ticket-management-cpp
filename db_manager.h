#include <mysql_connection.h>
#include <cppconn/driver.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>
#include <cppconn/exception.h>

#include "ticket.h"

class DBManager {
private:
    sql::Driver* driver;
    sql::Connection* conn;

public:
    DBManager(const char* host, const char* user, const char* password, const char* database);
    ~DBManager();

    void addTicket(const ticket& t);
    void addTicket(const char* title, const char* description, const char* status, const char* created_by);
     void listTickets() const;
     void voirDetail(const int& id) const;
     void updateTicketStatus(const int& id, const char* status);
     void deleteTicket(const int& id);
};
