#include "rendez_vous.h"
#include <QDebug>
#include<QString>
#include<QSqlQueryModel>
rendez_vous::rendez_vous()
{}
rendez_vous::rendez_vous(QString id_sec, QString reference,QDate date_rendez_vous,int num_rendez_vous,QString id_med){
this->id_sec=id_sec;
this->reference=reference;
this->date_rendez_vous=date_rendez_vous;
this->num_rendez_vous=num_rendez_vous;
this->id_med=id_med;
}

void rendez_vous::setid_sec(QString id_sec){
  this->id_sec=id_sec;
}
void rendez_vous::setreference(QString reference){
  this->reference=reference;
}
void rendez_vous::setdate_rendez_vous(QDate date_rendez_vous ){
    this->date_rendez_vous=date_rendez_vous;
}

void rendez_vous::settime_rendez_vous(QTime time_rendez_vous ){
    this->time_rendez_vous=time_rendez_vous;
}
void rendez_vous::setnum_rendez_vous(int num_rendez_vous){
    this->num_rendez_vous=num_rendez_vous;
}
void rendez_vous::setid_med(QString id_med){
  this->id_med=id_med;
}
QString rendez_vous::get_id_sec(){
    return id_sec;
}
QString rendez_vous::get_reference(){
    return reference;
}
QDate rendez_vous::get_date_rendez_vous(){
    return date_rendez_vous;
}

QTime rendez_vous::get_time_rendez_vous(){
    return time_rendez_vous;
}
int rendez_vous::get_num_rendez_vous(){
    return num_rendez_vous;
}
QString rendez_vous::get_id_med(){
    return id_med;
}
QString rendez_vous::generate_date(int j, int m, int a){
    QString jch=QString::number(j);
    QString mch=QString::number(m);
    if(jch.length()==1){
        jch="0"+jch;
    }
    if(mch.length()==1){
        mch="0"+mch;
    }
    return QString::number(a)+"-"+mch+"-"+jch;
}

QString rendez_vous::generate_time(int heure, int minute, int seconde){
    QString heurech=QString::number(heure);
    QString minutech=QString::number(minute);
    QString secondech=QString::number(seconde);

    if(heurech.length()==1){
        heurech='0'+heurech;
    }
    if(minutech.length()==1){
        minutech='0'+minutech;
    }
    if(secondech.length()==1){
        secondech='0'+secondech;
    }
    return heurech+':'+minutech+':'+secondech;
}
bool rendez_vous::ajouter_rendez_vous (){
    QSqlQuery query;
QString ch=generate_date(date_rendez_vous.day(),date_rendez_vous.month(),date_rendez_vous.year())+" "+generate_time(time_rendez_vous.hour(),time_rendez_vous.minute(),time_rendez_vous.second());
qDebug()<<ch;
    query.prepare("insert into rendez_vous (id_secretaire,references_patient,num_rendez_vous,id_med,date_rendez_vous)"
                  " values(:id_sec,:reference,:num_rendez_vous,:id_med,to_date(:ch,'yyyy-mm-dd hh24:mi:ss'))");
    query.bindValue(":id_sec",id_sec);
    query.bindValue(":reference",reference);
    query.bindValue(":ch",ch);
    query.bindValue(":num_rendez_vous",num_rendez_vous );
    query.bindValue(":id_med",id_med);

    return    query.exec();
};

QSqlQueryModel * rendez_vous::afficher_rendez_vous(){

    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from rendez_vous");
        return model;

}
bool rendez_vous::recherche_rendez_vous(){
    QSqlQuery query;
    QString ch=generate_date(date_rendez_vous.day(),date_rendez_vous.month(),date_rendez_vous.year())+" "+generate_time(time_rendez_vous.hour(),time_rendez_vous.minute(),time_rendez_vous.second());
    query.prepare("select id_med , date_rendez_vous from rendez_vous where id_med=:id_med and date_rendez_vous=to_date(:ch,'yyyy-mm-dd hh24:mi:ss')");
    query.bindValue(":ch",ch);
    query.bindValue(":id_med",id_med);
    query.exec();
    QString test_id;
    QString ch1;
    while(query.next()){
       test_id=query.value(0).toString();
    ch1=query.value(1).toString();
    }
    bool test=(test_id==id_med);

    return  test;
}
bool rendez_vous::modifier_rendez_vous(){

        QSqlQuery query;
        query.prepare("update rendez_vous set id_secretaire=:id_sec,references_patient=:reference,date_rendez_vous=:date_rendez_vous,id_med=:id_med where num_rendez_vous=:num_rendez_vous");
        query.bindValue(":num_rendez_vous",num_rendez_vous);
        query.bindValue(":id_sec",id_sec);
        query.bindValue(":reference",reference);
        query.bindValue(":id_med",id_med);
        query.bindValue(":date_rendez_vous",date_rendez_vous);
        return    query.exec();


}
void rendez_vous::chercher (){

QSqlQuery query1;
query1.prepare("select id_secretaire,references_patient,date_rendez_vous,id_med from rendez_vous where num_rendez_vous=:num_rendez_vous");
query1.bindValue(":reference",reference);
query1.bindValue(":num_rendez_vous",num_rendez_vous);
query1.exec();
while(query1.next())
{
id_sec = query1.value(0).toString();
reference = query1.value(1).toString();
date_rendez_vous = query1.value(2).toDate();
id_med = query1.value(3).toString();
}
}
QSqlQueryModel* rendez_vous::afficher_liste_rendez_vous(){
    QSqlQueryModel *model= new QSqlQueryModel ();
    model->setQuery("select num_rendez_vous from rendez_vous");

    return  model;
}
bool rendez_vous::archiver_rendez_vous(){

 QSqlQuery query;

 query.prepare("Delete from rendez_vous where NUM_RENDEZ_VOUS= :num_rendez_vous ");
 query.bindValue(":num_rendez_vous",num_rendez_vous);
 return    query.exec();
 }
QSqlQueryModel * rendez_vous::recherche (QString champ ,QString valeur,int etat)
{
    QSqlQueryModel * model=new QSqlQueryModel();
    QSqlQuery query;
    if(etat==0)
    {query.prepare("SELECT * FROM rendez_vous  where "+champ+" LIKE :valeur order by num_rendez_vous");}
    else
    {
         query.prepare("SELECT * FROM rendez_vous  where "+champ+" LIKE :valeur order by num_rendez_vous desc");
    }
    valeur="%"+valeur+"%";
    query.bindValue(":valeur",valeur);
    query.exec();
    model->setQuery(query);
    return  model;

}
