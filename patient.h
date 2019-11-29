#ifndef PATIENT_H
#define PATIENT_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>
#include <QSound>
class patient
{
public:
    patient();
    patient(QString,QString,QString,QString,QString);
    void setreference(QString);
    void setnom(QString);
    void setprenom(QString);
    void setdatedenaissance(QString);
    void setsexe(QString);
    QString get_reference();
    QString get_nom();
    QString get_prenom();
    QString get_datedenaissance();
    QString get_sexe();
    bool ajouter_patient();
    bool modifier_patient();
    bool archiver_patient();
    QSqlQueryModel * afficher_patient();
    QSqlQueryModel * afficher_liste_patient();
    QSqlQueryModel * recherche(QString,QString,int);
    void chercher();
    private:
    QString reference;
    QString nom;
    QString prenom;
    QString date_de_naissance;
    QString sexe;
};

#endif // PATIENT_H
