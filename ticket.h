class ticket{
public :
    ticket(const char* titre_,const char* description_,const char* statut_,const char* creePar_);
    ~ticket();
    char* getTitre() const { return titre; }
    char* getDescription() const { return description; }
    char* getStatut() const { return statut; }
    char* getCreePar() const { return creePar; }
    void setStatut(const char* nvStatut);
private:
    char* titre;
    char* description;
    char* statut;
    char* creePar;
};
