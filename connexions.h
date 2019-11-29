#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>

class Connexions
{
private:
    QSqlDatabase db;
public:
    Connexions();
    bool ouvrirConnexion();
    void fermerConnexion();

};

#endif // CONNEXION_H
