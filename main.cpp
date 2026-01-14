#include <iostream>
#include "db_manager.h"

using namespace std;

int main() {
    DBManager db("localhost", "root", "", "ticket_system");

    int choix;

    do {
        cout << endl <<"============================="<<endl;
        cout << "      Ticket Management      "<<endl;
        cout << "============================="<<endl;
        cout << "1. Ajouter  Ticket"<<endl;
        cout << "2. Voir Les Tickets"<<endl;
        cout << "3. Mettre a jour Status d'un Ticket"<<endl;
        cout << "4. Supprumer Ticket"<<endl;
        cout << "0. Quitter"<<endl;
        cout << "Entrer votre choix: ";
        cin >> choix;
        cin.ignore(); 

        if (choix == 1){
            char title[100], description[500], status[20], created_by[50];
            cout << "Entrer Titre: "; cin.getline(title, 100);
            cout << "Entrer Description: "; cin.getline(description, 500);
            cout << "Entrer Status (open/closed): "; cin.getline(status, 20);
            cout << "Creer Par : "; cin.getline(created_by, 50);
            
            ticket t(title, description, status, created_by);
            db.addTicket(t);

        }else if (choix == 2){
            cout << "--- Liste des Tickets ---"<<endl;
            db.listTickets();

        }else if (choix == 3){
            int id;
            char status[20];
            cout << "Entrer ID de ticket a mettre a jour: "; cin >> id; cin.ignore();
            cout << "Enter nouveau statut (open/closed): "; cin.getline(status, 20);

            db.updateTicketStatus(id, status);

        }else if (choix == 4){
            int id;
            cout << "Enter Ticket ID to delete: "; cin >> id; cin.ignore();
            db.deleteTicket(id);
        }else if (choix == 0){
            cout << "Quittons le programme. Bye!"<<endl;
        }else{
            cout << "Choix Invalide!"<<endl;
        }

    } while (choix != 0);

    return 0;
}
