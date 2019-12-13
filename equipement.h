#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class equipement
{public:
    equipement();
    equipement(QString,QString,QString,QString,QString);
    QString get_reference();
    QString get_nom();
    QString get_type();
    QString get_id();
    QString get_pays();
    void set_reference(QString);
    void set_nom(QString);
    void set_type(QString);
    void set_id(QString);
    void set_pays(QString);


    bool ajouter();
    QSqlQueryModel * afficher();
    QSqlQueryModel * afficherlist();
    bool supprimer(QString);
    void chercher();
    bool modifier();
QSqlQueryModel * recherche(QString valeur,int,QString);
private:
    QString reference , id , nom , type , pays;


};

#endif // EQUIPEMENT_H
