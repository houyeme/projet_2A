#ifndef CONNEXION_H
#define CONNEXION_H
#include <QSqlDatabase>
#include <QString>
#include <QSqlError>

class connexion
{
public:
    connexion();
    bool ouvrirconnexion();
};

#endif // CONNEXION_H
