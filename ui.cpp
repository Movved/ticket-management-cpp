#include "ui.h"
#include <cstring>

using namespace std;

void clearScreen()
{
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void showWelcome()
{
    clearScreen();

    cout << CYAN << BOLD;
    cout << "████████╗██╗ ██████╗██╗  ██╗███████╗████████╗\n";
    cout << "╚══██╔══╝██║██╔════╝██║ ██╔╝██╔════╝╚══██╔══╝\n";
    cout << "   ██║   ██║██║     █████╔╝ █████╗     ██║   \n";
    cout << "   ██║   ██║██║     ██╔═██╗ ██╔══╝     ██║   \n";
    cout << "   ██║   ██║╚██████╗██║  ██╗███████╗   ██║   \n";
    cout << "   ╚═╝   ╚═╝ ╚═════╝╚═╝  ╚═╝╚══════╝   ╚═╝   \n";
    cout << RESET << endl;

    cout << BOLD << "           SYSTÈME DE GESTION DES TICKETS" << RESET << endl;
    cout << YELLOW << "           Clair • Rapide • En ligne de commande\n\n" << RESET;
}

void showMenu()
{
    cout << BLUE << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n" << RESET;
    cout << " 1  Lister les tickets\n";
    cout << " 2  Voir détail d'un ticket\n";
    cout << " 3  Ajouter un ticket\n";
    cout << " 4  Modifier le statut\n";
    cout << " 5  Supprimer un ticket\n";
    cout << " 0  Quitter\n";
    cout << BLUE << "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━\n" << RESET;
    cout << "👉 Votre choix : ";
}

const char* colorStatus(const string& statut)
{
    if (statut == "open")
        return GREEN;
    if (statut == "closed")
        return RED;
    if (statut == "in_progress")
        return YELLOW;

    return RESET;
}
