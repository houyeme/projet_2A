#ifndef SECRETAIRE_H
#define SECRETAIRE_H
#include<QSqlQueryModel>
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QSound>

class secretaire
{
public:
    secretaire();
    secretaire(QString,QString);
     bool authentification();
private:
QString id, mot_de_passe;
};


#endif // SECRETAIRE_H
