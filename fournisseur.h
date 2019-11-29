#ifndef FOURNISSEUR_H
#define FOURNISSEUR_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class fournisseur
{public:
    fournisseur();
    fournisseur(QString,QString,QString,QString,QString,QString);
    QString get_id();
    QString get_nom();
    QString get_prenom();
    QString get_telephone();
    QString get_adresse();
    QString get_domaine();
    void set_id(QString);
    void set_nom(QString);
    void set_prenom(QString);
    void set_telephone(QString);
    void set_adresse(QString);
    void set_domaine(QString);

    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficherlist();
    bool supprimer(QString);
    void chercher();
    bool modifier();
    QSqlQueryModel * recherche(QString valeur);
    //GET ID FROM FOURNISSEUR
    QSqlQueryModel * GetIdModelFournisseur();


private:
    QString id,nom,prenom,telephone,adresse,domaine;


};
#endif // FOURNISSEUR_H
