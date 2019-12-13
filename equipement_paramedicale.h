#ifndef equipement_paramedicale_H
#define equipement_paramedicale_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QSqlQueryModel>
#include <QSqlQuery>
class equipement_paramedicale
{
public:
    equipement_paramedicale();
    equipement_paramedicale(QString,QString,QString,QString);
    void setrefrence(QString);
    void setnom(QString);
    void settype(QString);
    void setid_fournisseur(QString);
    QString get_reference();
    QString get_nom();
    QString get_type();
    QString get_id_fournisseur();
    bool ajouter_equipement_paramedicale();
    bool modifier_equipement_paramedicale();
    bool supprimer_equipement_paramedicale();
    QSqlQueryModel * afficher_equipement_paramedicale();
    QSqlQueryModel * afficher_list();
    void chercher();
    QSqlQueryModel * recherche(QString champ,QString valeur,int etat);
private :
    QString reference;
    QString nom;
    QString type;
    QString id_fournisseur;
};

#endif // equipement_paramedicale_H
