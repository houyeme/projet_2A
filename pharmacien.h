#ifndef PHARMACIEN_H
#define PHARMACIEN_H
#include <QString>
#include <QSqlQuery>
#include<QSqlQueryModel>

class pharmacien
{
public:
    pharmacien();
    pharmacien(QString,QString);
    bool authentification();
private :
    QString id, mot_de_passe;
};

#endif // PHARMACIEN_H
