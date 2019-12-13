#ifndef CADMIN_H
#define CADMIN_H

#include "personnel.h"
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class cadmin: public personnel
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
