#ifndef CONTRAT_H
#define CONTRAT_H
#include <QSqlQueryModel>
#include<QString>
#include <QDate>
#include <iostream>
typedef struct {
    QString a;
    QString j;
    QString m;
}date;
class contrat
{

public:
    contrat();
    void set_num_contrat(QString num_contrat){
        this->num_contrat=num_contrat;
    }
    void set_date_debut(QString j, QString m,  QString a){
        this->date_debut.a=a;
        this->date_debut.j=j;
        this->date_debut.m=m; }

    void set_date_fin( QString j, QString m, QString a){
        this->date_fin.a=a;
        this->date_fin.j=j;
        this->date_fin.m=m;
    }

    void set_salaire(int salaire){
        this->salaire=salaire;
    }

    void set_matricule(QString matricule){
        this->matricule=matricule;
    }
    QString get_num_contrat(){
        return num_contrat;
    }
     QString get_date_debut_jour(){
        return date_debut.j;
    }

     QString get_date_debut_mois(){
        return date_debut.m;
    }

     QString get_date_debut_annne(){
        return date_debut.a;
    }

     QString get_date_fin_annne(){
        return date_fin.a;
    }

     QString get_date_fin_mois(){
        return date_fin.m;
    }

     QString get_date_fin_jour(){
        return date_fin.j;
    }

    int get_salaire(){
        return salaire;
    }

    QString get_matricule(){
        return matricule;
    }

    bool ajouter();
    QSqlQueryModel * afficher();

    QSqlQueryModel * afficher_list();
    QSqlQueryModel * afficher_list_fin(bool *);

    bool mise_ajour();
    void chercher();
    bool supprimer();
    QString generate_date(QString j,QString m, QString a){
       if(j.length()==1){
       j='0'+j;
       }
       if(m.length()==1){
       m='0'+m;
       }
        return j+"-"+m+"-"+a;
    }

private:
    QString num_contrat,matricule;
    int salaire;
    date date_debut,date_fin;



};

#endif // CONTRAT_H
