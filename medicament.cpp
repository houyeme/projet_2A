#include "medicament.h"

medicament::medicament()
{


}
medicament::medicament(QString r,QString e, int q,int p)
{
    reference=r;
    etat=e;
    quantite=q;
    prix=p;

}
void medicament:: setrefrence(QString r)
{
    reference=r;
}
void medicament:: setetat(QString e)
{
   etat=e;
}
void medicament:: setquantitte(int q)
{
   quantite=q;
}
void medicament:: setprix(int p)
{
  prix=p;
}
QString medicament:: get_reference()
{
    return reference;
}
QString medicament::get_etat()
{
    return etat;
}
int medicament:: get_quantite()
{
    return quantite;
}
int medicament::get_prix()
{
    return prix;
}
bool medicament::ajouter_medicament()
{
    QSqlQuery query;

    query.prepare("INSERT INTO medicament (reference,etat,quantite,prix) " "VALUES (:reference,:etat,:quantite,:prix)");
    query.bindValue(":reference",reference);
    query.bindValue(":etat",etat);
    query.bindValue(":quantite",quantite);
  query.bindValue(":prix", prix);

    return    query.exec();

}
bool medicament::modifier_medicament(){

        QSqlQuery query;
        query.prepare("update medicament set etat=:etat,quantite=:quantite,prix=:prix where reference=:reference");
        query.bindValue(":reference",reference);
        query.bindValue(":etat",etat);
        query.bindValue(":quantite",quantite);
        query.bindValue(":prix", prix);
        return    query.exec();

}
bool medicament:: supprimer_medicament()
{
QSqlQuery query;
query.prepare("Delete from medicament where reference = :reference ");
query.bindValue(":reference", reference);
return    query.exec();
}
QSqlQueryModel * medicament::afficher_medicament()
{QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from medicament");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("etat"));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));

    return model;
}

QSqlQueryModel * medicament::afficher_list()
{QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select reference from medicament");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));


        return model;
  }

void medicament::chercher()
{
    QSqlQuery query1;
    query1.prepare("SELECT etat,quantite,prix FROM medicament WHERE reference =:reference");
    query1.bindValue(":reference",reference);
    query1.exec();
    while(query1.next())
    {
    etat = query1.value(0).toString();
    quantite = query1.value(1).toInt();
    prix = query1.value(2).toInt();
    }
    }

QSqlQueryModel * medicament:: recherche(QString champ,QString valeur,int etat)
{
    QSqlQueryModel * model=new QSqlQueryModel();

    QSqlQuery query;
    if(etat==0)
   { query.prepare("SELECT * FROM MEDICAMENT WHERE ("+champ+" LIKE :valeur) order by reference");}
    else   { query.prepare("SELECT * FROM MEDICAMENT WHERE ("+champ+" LIKE :valeur) order by reference desc");}
    valeur="%"+valeur+"%";
    query.bindValue(":valeur",valeur);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("REFERENCE"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("etat"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("quantite"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("prix"));
    return model;

}

 void medicament::statistique(QVector<double>* ticks,QVector<QString> *labels)
 {   QSqlQuery q;
     int i=0;
     q.exec("select reference from medicament");
     while (q.next()) {
         QString refer = q.value(0).toString();
         i++;
         *ticks<<i;
         *labels <<refer;
 }
 }
