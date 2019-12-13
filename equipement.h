#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
class equipement
{
public:
    equipement();
    equipement(QString,QString,QString,QString);
    void setrefrence(QString);
    void setnom(QString);
    void settype(QString);
    void setid_fournisseur(QString);
    QString get_reference();
    QString get_nom();
    QString get_type();
    QString get_id_fournisseur();
    bool ajouter_equipement();
    bool modifier_equipement();
    bool supprimer_equipement();
    QSqlQueryModel * afficher_equipement();
    QSqlQueryModel * afficher_list();
    void chercher();
    QSqlQueryModel * recherche(QString champ,QString valeur,int etat);
private :
    QString reference;
    QString nom;
    QString type;
    QString id_fournisseur;
};

#endif // EQUIPEMENT_H
