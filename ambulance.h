#ifndef AMBULANCE_H
#define AMBULANCE_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class ambulance
{
public:
    ambulance();
    ambulance(QString,QString,QString);
    bool ajouter();
    bool supprimer(QString);
    bool modifier();
   QSqlQueryModel* afficher();
   QSqlQueryModel* afficher_list();
   QSqlQueryModel *  recherche(QString);
    void setmatricule(QString);
    void setetat(QString);
    void setdateentretient(QString);
    void chercher();

    QString getmatricule();
    QString getetat();
    QString getdateentretient();


private:
     QString matricule_v;
     QString etat;
    QString date_dernier_entretient;
};

#endif // AMBULANCE_H
