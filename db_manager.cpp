#include "db_manager.h"
#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include "ui.h"

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
        cout << BOLD << CYAN ;
       cout << "+----+------------------------------+-------------+------------+" << endl;
        cout << "| ID | Titre                        | Statut      | Cree Par   |" << endl;
        cout << "+----+------------------------------+-------------+------------+" << endl;
        cout << RESET;        

        while (res->next()) {
            string statut = res->getString("status");
            cout << colorStatus(statut) << "| "
                 << setw(2) << left << res->getInt("id") << " | "
                 << setw(28) << left << res->getString("title") << " | "
                 << setw(11) << left << res->getString("status") << " | "
                 << setw(10) << left << res->getString("created_by") << " |"
                 << RESET <<endl;
        }
        
        
        cout << CYAN <<BOLD<< "+----+------------------------------+-------------+------------+" << RESET <<endl;
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
        if(stmt->executeUpdate(query))
            cout <<GREEN<<"Votre ticket est ajoute avec succes!"<<RESET<<endl;
         else cout<< RED << "Un Problem Lors d'ajout est Survenue! "  << RESET<<endl;

        delete stmt;

    }catch(sql::SQLException& e){
        cout << "Add ticket error: " << e.what() << endl;
    }
}



void DBManager::updateTicketStatus(const int& id, const char* s) 
{
    if (!conn) return;

    try {
        std::string query = "UPDATE tickets SET status = '";
        query += s;
        query += "' WHERE id=";
        query += std::to_string(id);
        
        sql::Statement* stmt = conn->createStatement();
        
        if(stmt->executeUpdate(query) > 0)
            cout <<GREEN<<"Votre ticket est mettre a jour avec succes!"<<RESET<<endl;
        else cout<< RED << "Aucun ticket trouvé avec l'ID " << id << RESET<<endl;

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
        if(stmt->executeUpdate(query) > 0)
        cout <<GREEN<<"Votre ticket est supprime avec succes!"<<RESET<<endl;
        else cout<< RED << "Aucun ticket trouvé avec l'ID " << id << RESET<<endl;
        delete stmt;

    }catch(sql::SQLException& e){
        cout << "suppression ticket error: " << e.what() << endl;
    }
}

void DBManager::voirDetail(const int& id) const {
    if (!conn) return;

    try {
        sql::Statement* stmt = conn->createStatement();
        
        string query = "SELECT * FROM tickets WHERE id=" + to_string(id);
        sql::ResultSet* res = stmt->executeQuery(query);

        if (res->next()){
            cout << "\n--- Détails du ticket ---\n";
            cout << "ID        : " << res->getInt("id") << endl;
            cout << "Titre     : " << res->getString("title") << endl;
            cout << "Description: " << res->getString("description") << endl;
            cout << "Statut    : " << res->getString("status") << endl;
            cout << "Cree Par: " << res->getString("created_by") << endl;
            cout << "-------------------------\n";
        } else {
            cout << RED << "Aucun ticket trouvé avec l'ID " << id << RESET <<  endl;
        }

        delete res;
        delete stmt;

    } catch (sql::SQLException& e) {
        cout << "Erreur lors de la récupération du ticket: " << e.what() << endl;
    }
}