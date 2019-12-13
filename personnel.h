#ifndef PERSONNEL_H
#define PERSONNEL_H
#include<QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
class personnel
{
public:
    personnel();
    personnel(QString New_Mat,QString New_Nom, QString New_Prenom);
    QString get_nom(){
        return Nom;}
    QString get_prenom()
    {
        return Prenom;}

    QString get_mat(){
        return Matricule;
    }
    void Set_mat(QString Matricule){
        this->Matricule=Matricule;
    }
    bool ajouter();
    bool supprimer(QString);
    bool mise_ajour(QString,QString,QString);
    bool chercher(QString);
    QSqlQueryModel *afficher_list();


protected:
    QString Matricule;
    QString Nom;
    QString Prenom;
    QString Num_CONTRAT;
};

#endif // PERSONNEL_H
