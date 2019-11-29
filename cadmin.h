#ifndef CADMIN_H
#define CADMIN_H


#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class cadmin
{
public:
    cadmin();
    cadmin(QString,QString);
    bool authentification();
private:
    QString id;
    QString mot_de_passe;
};

#endif // CADMIN_H
