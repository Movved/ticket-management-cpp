#include <iostream>
#include <cstring>
#include "ticket.h"
using namespace std;

ticket::ticket(const char* titre_,const char* description_,const char* statut_,const char* creePar_)
{
    titre = new char[(strlen(titre_)+1)];
    description = new char[(strlen(description_)+1)];
    statut = new char[(strlen(statut_)+1)];
    creePar = new char[(strlen(creePar_)+1)];

    strcpy(titre,titre_);
    strcpy(description,description_);
    strcpy(statut,statut_);
    strcpy(creePar,creePar_);
}
ticket::~ticket()
{
    delete [] titre;
    delete [] description;
    delete [] statut;
    delete [] creePar;
}
void ticket::setStatut(const char* nvStatut)
{
    delete [] statut;
    statut = new char[(strlen(nvStatut)+1)];
    strcpy(statut,nvStatut);
}