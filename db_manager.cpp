#include "db_manager.h"
#include <iostream>
#include <cstring>
#include <string>

using namespace std;

DBManager::DBManager(const char* host, const char* user, const char* password, const char* database)
{
   try {
        driver = get_driver_instance();
        conn = driver->connect(host, user, password);
        conn->setSchema(database);
    } catch (sql::SQLException& e) {
        cout << "DB Connection error: " << e.what() << endl;
        conn = nullptr;
    }
}



DBManager::~DBManager()
{
    if (conn) {
        delete conn;
    }
}



void DBManager::listTickets() const
{
    if (!conn) return;
    try {
        sql::Statement* stmt = conn->createStatement();
        sql::ResultSet* res = stmt->executeQuery("SELECT * FROM tickets");
        while (res->next()) {
            cout << "ID: " << res->getInt("id")
                 << ", Title: " << res->getString("title")
                 << ", Description: " << res->getString("description")
                 << ", Status: " << res->getString("status")
                 << ", Created by: " << res->getString("created_by")
                 << endl;
        }
        delete res;
        delete stmt;
    } catch (sql::SQLException& e) {
        cout << "List tickets error: " << e.what() << endl;
    }
}

void DBManager::addTicket(const ticket& t)
{
    addTicket(t.getTitre(),t.getDescription(),t.getStatut(),t.getCreePar());
}

void DBManager::addTicket(const char* t, const char* d, const char* s, const char* c)
{
    if (!conn) return;

    try {
        char query[1024];
        strcpy(query, "INSERT INTO tickets(title, description, status, created_by) VALUES('");
        strcat(query, t);
        strcat(query, "', '");
        strcat(query, d);
        strcat(query, "', '");
        strcat(query, s);
        strcat(query, "', '");
        strcat(query, c);
        strcat(query, "')");

        sql::Statement* stmt = conn->createStatement();
        stmt->execute(query);
        cout <<"Votre ticket est ajoute avec succes!"<<endl;
        delete stmt;

    }catch(sql::SQLException& e){
        cout << "Add ticket error: " << e.what() << endl;
    }
}



void DBManager::updateTicketStatus(const int& id, const char* s) 
{
    if (!conn) return;

    try {
        char query[1024];
        strcpy(query, "UPDATE tickets SET status = '");
        strcat(query, s);
        strcat(query, "'");

        sql::Statement* stmt = conn->createStatement();
        stmt->execute(query);
        cout <<"Votre ticket est mettre a jour avec succes!"<<endl;
        delete stmt;

    }catch(sql::SQLException& e){
        cout << "update ticket error: " << e.what() << endl;
    }
}

void DBManager::deleteTicket(const int& id)
{
    if (!conn) return;

    try {
        string query = "DELETE FROM tickets WHERE id= '";
        query +=to_string(id);
        query+="'";

        sql::Statement* stmt = conn->createStatement();
        stmt->execute(query);
        cout <<"Votre ticket est supprime avec succes!"<<endl;
        delete stmt;

    }catch(sql::SQLException& e){
        cout << "update ticket error: " << e.what() << endl;
    }
}

