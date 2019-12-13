#ifndef MEDICAMENT_H
#define MEDICAMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "qcustomplot.h"

class medicament
{
public:
    medicament();
    medicament(QString,QString, int,int);
    void setrefrence(QString);
    void setetat(QString);
    void setquantitte(int);
    void setprix(int);
    QString get_reference();
    QString get_etat();
    int get_quantite();
    int get_prix();
    bool ajouter_medicament();
    bool modifier_medicament();
    bool supprimer_medicament();
    QSqlQueryModel * afficher_medicament();
    QSqlQueryModel * afficher_list();
    void chercher();
    QSqlQueryModel * recherche(QString champ,QString valeur,int etat);
    void statistique(QVector<double>*,QVector<QString>*);

private:
    QString reference;
    QString etat;
    int quantite;
    int prix;
};

#endif // MEDICAMENT_H
