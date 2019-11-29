#include "admin_panal.h"
#include "ui_admin_panal.h"
#include <iostream>
#include <QDebug>
#include "notifcation.h"
#include "qcustomplot.h"
using namespace std;
admin_panal::admin_panal(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin_panal)
{
    ui->setupUi(this);
    makePolt();
refresh();
}

admin_panal::~admin_panal()
{
    delete ui;
}
void admin_panal::afficher_notification(int *x){
    bool test;
    ui->listView->setModel(tmpcontrat.afficher_list_fin(&test));
    if((test)&&(*x<ui->listView->model()->rowCount())){
    notifcation n;
    n.afficher();
    ui->main->setCurrentIndex(2);
    *x=ui->listView->model()->rowCount();
    }
}
void admin_panal::initialiser_formulaire(){
    ui->Id->clear();
    ui->specilite->clear();
    ui->Mot_de_passe->clear();
    ui->Matricule->clear();
    ui->Nom->clear();
    ui->Prenom->clear();
    ui->Num_cabinet->clear();
}

void admin_panal::initialiser_formulaire2(){
    ui->Id_2->clear();
    ui->specilite_2->clear();
    ui->Mot_de_passe_2->clear();
    ui->Nom_2->clear();
    ui->Prenom_2->clear();
    ui->Num_cabinet_2->clear();
    ui->comboBox->setModel(tmpmedecin.afficher_liste_mat());

}
void admin_panal::initialiser_formulaire3(){
 ui->salaire->clear();
 ui->Num_contrat->clear();
 ui->dateEdit->setDate(ui->dateEdit->minimumDate());
 ui->dateEdit_2->setDate(ui->dateEdit->minimumDate());
}
void admin_panal::on_pushButton_clicked()
{
 QString id,specialite ,mot_de_passe,Matricule,Nom,Prenom;
 int Num_cabinet ;
 id=ui->Id->text();
 specialite=ui->specilite->text();
 mot_de_passe=ui->Mot_de_passe->text();
 Matricule=ui->Matricule->text();
 Nom=ui->Nom->text();
 Prenom=ui->Prenom->text();
 Num_cabinet=ui->Num_cabinet->text().toInt();
 medecin m(id,specialite,Num_cabinet ,mot_de_passe,Matricule,Nom,Prenom);
if(m.ajouter()){
refresh();
    initialiser_formulaire();
    ui->Resultat->setText(Matricule+" a été bien enregistré ");
}
}

void admin_panal::on_pushButton_2_clicked()
{ui->Resultat->setText("");
    initialiser_formulaire();
}



void admin_panal::on_pushButton_5_clicked()
{QString mat=ui->Matricule_sup->text();
  bool test=tmpmedecin.supprimer(mat);
  if(test){
  refresh();
  ui->Matricule_sup->setText("");
  }
}

void admin_panal::on_comboBox_activated(const QString &arg1)
{
tmpmedecin.chercher(arg1);
ui->Nom_2->setText(tmpmedecin.get_nom());
ui->Prenom_2->setText(tmpmedecin.get_prenom());
ui->Id_2->setText(tmpmedecin.get_id());
ui->specilite_2->setText(tmpmedecin.get_specilite());
QString cabinet=QString::number(tmpmedecin.get_numcabinet());
ui->Num_cabinet_2->setText(cabinet);
ui->Mot_de_passe_2->setText(tmpmedecin.get_mot_passe());
}

bool admin_panal::verif_formulaire_m(){
 return((ui->Nom_2->text()!="")&&( ui->Prenom_2->text()!="")&&(ui->Id_2->text()!="")&&(ui->specilite_2->text()!="")&&( ui->Mot_de_passe_2->text()!=""));
}

void admin_panal::on_pushButton_3_clicked()
{QString id ,specialite,mot_de_passe ,Nom,Prenom;
    int Num_cabinet;

    Nom=ui->Nom_2->text();
    Prenom=ui->Prenom_2->text();
    id=ui->Id_2->text();
    specialite=ui->specilite_2->text();
    Num_cabinet=ui->Num_cabinet_2->text().toInt();
    mot_de_passe=ui->Mot_de_passe_2->text();
    if(verif_formulaire_m()==false){
        ui->Resultat_2->setText("champ invalid");
    }else{
    if(tmpmedecin.mise_ajour(tmpmedecin.get_mat(),id,specialite,Num_cabinet,mot_de_passe,Nom,Prenom)){
refresh();
ui->Resultat_2->setText(tmpmedecin.get_mat()+"a été bien modifié");
initialiser_formulaire2();
    }
    }

}

void admin_panal::on_pushButton_4_clicked()
{
    refresh();
    initialiser_formulaire2();

}

void admin_panal::on_comboBox_2_activated(const QString &arg1)
{
ui->Matricule_sup->setText(arg1);
}
void admin_panal::refresh(){
    ui->numero_contrat_list->setModel(tmpcontrat.afficher_list());
    ui->tab_medecin->setModel(tmpmedecin.afficher());
    ui->comboBox->setModel(tmpmedecin.afficher_liste_mat());
    ui->comboBox_2->setModel(tmpmedecin.afficher_liste_mat());
    ui->comboBox_5->setModel(tmppersonnel.afficher_list());
    ui->tab_contrat->setModel(tmpcontrat.afficher());
ui->numero_contrat_list_2->setModel(tmpcontrat.afficher_list());
ui->tab_pharmacien->setModel(tmppharmacien.afficher());
ui->comboBox_3->setModel(tmppharmacien.afficher_liste_ph());
ui->comboBox_4->setModel(tmppharmacien.afficher_liste_ph());
ui->tab_responsable->setModel(tmpresponsable.afficher());
ui->comboBox_6->setModel(tmpresponsable.afficher_liste_res());
ui->comboBox_7->setModel(tmpresponsable.afficher_liste_res());
ui->tab_secretaire->setModel(tmpsecretaire.afficher());
ui->comboBox_8->setModel(tmpsecretaire.afficher_liste_res());
ui->comboBox_9->setModel(tmpsecretaire.afficher_liste_res());
ui->tab_chauffeur->setModel(tmpch.afficher());
ui->comboBox_10->setModel(tmpch.afficher_liste_res());
ui->comboBox_11->setModel(tmpch.afficher_liste_res());
afficher_notification(&x);
}

void admin_panal::on_comboBox_5_activated(const QString &arg1)
{
tmpcontrat.set_matricule(arg1);
}



void admin_panal::on_dateEdit_userDateChanged(const QDate &date)
{
   date_debut=date;
    tmpcontrat.set_date_debut(QString::number(date.day()),QString::number(date.month()),QString::number(date.year()));
}

void admin_panal::on_dateEdit_2_userDateChanged(const QDate &date)
{   date_fin=date;
    tmpcontrat.set_date_fin(QString::number(date.day()),QString::number(date.month()),QString::number(date.year()));
}

void admin_panal::on_pushButton_6_clicked()
{QString num_contrat=ui->Num_contrat->text();
    tmpcontrat.set_num_contrat(num_contrat);
    int salaire=ui->salaire->text().toInt();
    tmpcontrat.set_salaire(salaire);
   if(date_debut>=date_fin){
       ui->Resultat_3->setText(" date debut doit etre < date fin ");

   }else{
    if(tmpcontrat.ajouter())
    { initialiser_formulaire3();
       ui->Resultat_3->setText(num_contrat+"a été bien enregisté");
       refresh();
   }
   }
}

void admin_panal::on_dateEdit_3_userDateChanged(const QDate &date)
{
    date_debut=date;
tmpcontrat.set_date_debut(QString::number(date.day()),QString::number(date.month()),QString::number(date.year()));
}

void admin_panal::on_dateEdit_4_userDateChanged(const QDate &date)
{
    date_fin=date;

    tmpcontrat.set_date_fin(QString::number(date.day()),QString::number(date.month()),QString::number(date.year()));
}

void admin_panal::on_pushButton_9_clicked()
{
    if(date_debut<date_fin){
    tmpcontrat.set_salaire(ui->salaire_2->text().toInt());
    if(tmpcontrat.mise_ajour()){
        refresh();
        ui->Resultat_4->setText(tmpcontrat.get_num_contrat()+" a été bien modifié ");
        initialiser_formulaire12();
    }}
    else{
       ui->Resultat_4->setText("date debut doit etre < date fin");
    }
}

void admin_panal::on_numero_contrat_list_activated(const QString &arg1)
{
    tmpcontrat.set_num_contrat(arg1);
    tmpcontrat.chercher();
QString salaire= QString::number(tmpcontrat.get_salaire());
ui->salaire_2->setText(salaire);
ui->date_debut_valeur->setText(tmpcontrat.generate_date(tmpcontrat.get_date_debut_jour(),tmpcontrat.get_date_debut_mois(),tmpcontrat.get_date_debut_annne()));
ui->date_fin_valeur->setText(tmpcontrat.generate_date(tmpcontrat.get_date_fin_jour(),tmpcontrat.get_date_fin_mois(),tmpcontrat.get_date_fin_annne()));

}
void admin_panal::on_pushButton_10_clicked()
{    tmpcontrat.set_num_contrat(ui->num_contrat_sup->text());
    tmpcontrat.supprimer();
refresh();
}

void admin_panal::on_numero_contrat_list_2_activated(const QString &arg1)
{
   ui->num_contrat_sup->setText(arg1);
}

void admin_panal::on_pushButton_7_clicked()
{
    initialiser_formulaire3();

}

void admin_panal::on_pushButton_11_clicked()
{pharmacien ph(ui->Id_3->text(),ui->Mot_de_passe_3->text(),ui->Matricule_3->text(),ui->Nom_3->text(),ui->Prenom_3->text());
if( ph.ajouter())
   {    ui->Resultat_5->setText(ui->Matricule_3->text() + " a été bien enregisté");
    initialiser_formulaire4();
    refresh();
}

}
void admin_panal::initialiser_formulaire4(){
    ui->Id_3->clear();
  ui->Mot_de_passe_3->clear();
  ui->Matricule_3->clear();
ui->Nom_3->clear();
ui->Prenom_3->clear();
}


void admin_panal::on_comboBox_4_activated(const QString &arg1)
{
ui->Matricule_sup_2->setText(arg1);
}


void admin_panal::on_pushButton_15_clicked()
{
if(tmppersonnel.supprimer(ui->Matricule_sup_2->text())){
    refresh();
    ui->Matricule_sup_2->clear();
}
}

void admin_panal::on_comboBox_3_activated(const QString &arg1)
{
    tmppharmacien.chercher(arg1);
    tmppharmacien.Set_mat(arg1);
    ui->Nom_4->setText(tmppharmacien.get_nom());
    ui->Prenom_4->setText(tmppharmacien.get_prenom());
    ui->Id_4->setText(tmppharmacien.get_id());
    ui->Mot_de_passe_4->setText(tmppharmacien.get_mot_de_passe());

}

void admin_panal::initialiser_formulaire5(){
    ui->Nom_4->clear();
    ui->Prenom_4->clear();
    ui->Id_4->clear();
    ui->Mot_de_passe_4->clear();
}
bool admin_panal::verif_formulaire_ph(){
    return((ui->Nom_4->text()!="")&&(ui->Prenom_4->text()!="")&&(ui->Id_4->text()!="")&&(ui->Mot_de_passe_4->text()!=""));

}
void admin_panal::on_pushButton_13_clicked()
{
    if(verif_formulaire_ph()==false){
        ui->Resultat_6->setText("champs invalid");
    }else{
    if(tmppharmacien.mise_ajour(tmppharmacien.get_mat(),ui->Id_4->text(),ui->Mot_de_passe_4->text(),ui->Nom_4->text(),ui->Prenom_4->text())){
        refresh();
        initialiser_formulaire5();
        ui->Resultat_6->setText(tmppharmacien.get_mat() +" a ete bien modifié");
    }
    }
}

void admin_panal::on_pushButton_14_clicked()
{
    initialiser_formulaire5();
    refresh();
}

void admin_panal::on_pushButton_12_clicked()
{
    initialiser_formulaire4();
}
void admin_panal::initialiser_formulaire6(){
    ui->Id_5->clear();
    ui->Mot_de_passe_5->clear();
    ui->domaine->clear();
    ui->Matricule_4->clear();
    ui->Nom_5->clear();
    ui->Prenom_5->clear();
}
void admin_panal::on_pushButton_16_clicked()
{
    responsable r(ui->Id_5->text(),ui->Mot_de_passe_5->text(),ui->domaine->text(),ui->Matricule_4->text(),ui->Nom_5->text(),ui->Prenom_5->text());
    if( r.ajouter())
       {    ui->Resultat_7->setText(ui->Matricule_4->text() + " a été bien enregisté");
        refresh();
        initialiser_formulaire6();
    }
}

void admin_panal::on_comboBox_6_activated(const QString &arg1)
{
    tmpresponsable.Set_mat(arg1);
    tmpresponsable.chercher();
ui->Id_6->setText(tmpresponsable.get_id());
ui->Mot_de_passe_6->setText(tmpresponsable.get_mot_de_passe());
ui->domaine_2->setText(tmpresponsable.get_domaine());
ui->Nom_6->setText(tmpresponsable.get_nom());
ui->Prenom_6->setText(tmpresponsable.get_prenom());
}
bool admin_panal::verif_formulaire_r(){
  return ((ui->Id_6->text()!="")&&( ui->Mot_de_passe_6->text()!="")&&(ui->domaine_2->text()!="")&&(ui->Nom_6->text()!="")&&(ui->Prenom_6->text()!=""));
}
void admin_panal::initialiser_formulaire7(){

    ui->Id_6->clear();
    ui->Mot_de_passe_6->clear();
    ui->domaine_2->clear();
    ui->Nom_6->clear();
    ui->Prenom_6->clear();
}
void admin_panal::on_pushButton_18_clicked()
{
if(verif_formulaire_r()){
    tmpresponsable.mise_ajour(tmpresponsable.get_mat(),ui->Id_6->text(),ui->Mot_de_passe_6->text(),ui->domaine_2->text(),ui->Nom_6->text(),ui->Prenom_6->text());
    ui->Resultat_8->setText(tmpresponsable.get_mat()+" a ete bien modifié ");
    refresh();
    initialiser_formulaire7();
}else{
ui->Resultat_8->setText( "champs invalid ");
}
}

void admin_panal::on_pushButton_19_clicked()
{
    initialiser_formulaire7();
    refresh();
    ui->Resultat_8->setText("");
}

void admin_panal::on_comboBox_7_activated(const QString &arg1)
{
ui->Matricule_sup_3->setText(arg1);
}

void admin_panal::on_pushButton_20_clicked()
{
    if(tmpresponsable.supprimer(ui->Matricule_sup_3->text())){
        refresh();
        ui->Matricule_sup_3->clear();
    }
}
void admin_panal::initialiser_formulaire8(){

    ui->Id_7->clear();
    ui->Mot_de_passe_7->clear();
    ui->Matricule_5->clear();
    ui->Nom_7->clear();
    ui->Prenom_7->clear();
}
void admin_panal::on_pushButton_22_clicked()
{QString id,mot_de_passe,Matricule,Nom,Prenom;
    id=ui->Id_7->text();
    mot_de_passe=ui->Mot_de_passe_7->text();
    Matricule=ui->Matricule_5->text();
    Nom=ui->Nom_7->text();
    Prenom=ui->Prenom_7->text();
    secretaire s(id,mot_de_passe,Matricule,Nom,Prenom);
    if(s.ajouter()){
       refresh();
       initialiser_formulaire8();
       ui->Resultat_9->setText(Matricule+" a été bien enregisté ");
   }

}

void admin_panal::on_comboBox_8_activated(const QString &arg1)
{
    tmpsecretaire.Set_mat(arg1);
    tmpsecretaire.chercher();
ui->Id_8->setText(tmpsecretaire.get_id());
ui->Mot_de_passe_8->setText(tmpsecretaire.get_mot_de_passe());
ui->Nom_8->setText(tmpsecretaire.get_nom());
ui->Prenom_8->setText(tmpsecretaire.get_prenom());

}
void admin_panal::initialiser_formulaire9(){
    ui->Id_8->clear();
    ui->Mot_de_passe_8->clear();
    ui->Nom_8->clear();
    ui->Prenom_8->clear();

}

bool admin_panal::verif_formulaire_s(){
   return ((ui->Id_8->text()!="")&&( ui->Mot_de_passe_8->text()!="")&&(ui->Nom_8->text()!="")&&(ui->Prenom_8->text()!=""));

}
void admin_panal::on_pushButton_24_clicked()
    {
    if(verif_formulaire_s()){
        tmpsecretaire.mise_ajour(tmpsecretaire.get_mat(),ui->Id_8->text(),ui->Mot_de_passe_8->text(),ui->Nom_8->text(),ui->Prenom_8->text());
        ui->Resultat_10->setText(tmpsecretaire.get_mat()+" a ete bien modifié ");
        refresh();
        initialiser_formulaire9();
    }else{
    ui->Resultat_10->setText( "champs invalid ");
    }
    }


void admin_panal::on_comboBox_9_activated(const QString &arg1)
{
    ui->Matricule_sup_4->setText(arg1);

}

void admin_panal::on_pushButton_25_clicked()
{
    if(tmpsecretaire.supprimer(ui->Matricule_sup_4->text())){
        refresh();
        ui->Matricule_sup_4->clear();
    }
}


void admin_panal::initialiser_formulaire10(){
    ui->Id_9->clear();
    ui->Mot_de_passe_9->clear();
    ui->Nom_9->clear();
    ui->Prenom_9->clear();

}
void admin_panal::on_pushButton_26_clicked()
{
    QString id,mot_de_passe,Matricule,Nom,Prenom;
        id=ui->Id_9->text();
        mot_de_passe=ui->Mot_de_passe_9->text();
        Matricule=ui->Matricule_6->text();
        Nom=ui->Nom_9->text();
        Prenom=ui->Prenom_9->text();
        chauffeur ch(id,mot_de_passe,Matricule,Nom,Prenom);
        if(ch.ajouter()){
           refresh();
           initialiser_formulaire10();
           ui->Resultat_11->setText(Matricule+" a été bien enregisté ");
       }

}

void admin_panal::on_comboBox_10_activated(const QString &arg1)
{
    tmpch.Set_mat(arg1);
    tmpch.chercher();
    ui->Id_10->setText(tmpch.get_id());
    ui->Nom_10->setText(tmpch.get_nom());
    ui->Prenom_10->setText(tmpch.get_prenom());
    ui->Mot_de_passe_10->setText(tmpch.get_mot_de_passe());

}

void admin_panal::initialiser_formulaire11(){

    ui->Id_10->clear();
    ui->Mot_de_passe_10->clear();
    ui->Nom_10->clear();
    ui->Prenom_10->clear();

}

bool admin_panal::verif_formulaire_ch(){
 return((ui->Nom_10->text()!="")&&( ui->Prenom_10->text()!="")&&(ui->Mot_de_passe_10->text()!="")&&( ui->Id_10->text()!=""));
}
void admin_panal::on_pushButton_28_clicked()
{
    if(verif_formulaire_ch()){
        tmpch.mise_ajour(tmpch.get_mat(),ui->Id_10->text(),ui->Mot_de_passe_10->text(),ui->Nom_10->text(),ui->Prenom_10->text());
        ui->Resultat_12->setText(tmpch.get_mat()+" a ete bien modifié ");
        refresh();
        initialiser_formulaire11();
    }else{
    ui->Resultat_12->setText( "champs invalid ");
    }

}




void admin_panal::on_comboBox_11_activated(const QString &arg1)
{
    ui->Matricule_sup_5->setText(arg1);
}

void admin_panal::on_pushButton_30_clicked()
{
    if(tmpsecretaire.supprimer(ui->Matricule_sup_5->text())){
        refresh();
        ui->Matricule_sup_5->clear();
    }
}

void admin_panal::initialiser_formulaire12()
{ui->date_debut_valeur->clear();
    ui->date_fin_valeur->clear();
ui->salaire_2->clear();
ui->dateEdit_3->setDate(ui->dateEdit->minimumDate());
ui->dateEdit_4->setDate(ui->dateEdit->minimumDate());
}



void admin_panal::on_champs_activated(const QString &arg1)
{
ui->valeur->setDisabled(false);
champ=champ+arg1;
ui->checkBox->setDisabled(false);
}


void admin_panal::on_valeur_textChanged(const QString &arg1)
{
valeur=arg1;
ui->tab_medecin->setModel(tmpmedecin.recherche(champ,arg1,ordre));

}

void admin_panal::on_champs_activated(int index)
{
    if((index>0)&&(index<=3)){
        champ="P.";
    }
    else if(index>3){
        champ="M.";
    }
    else {
        champ="";
    }
}


void admin_panal::on_checkBox_stateChanged(int arg1)
{
ordre=arg1;
ui->tab_medecin->setModel(tmpmedecin.recherche(champ,valeur,ordre));
}



void admin_panal::makePolt()
{


       ///////////////////////////////////////////////////////////////////////
       // set dark background gradient:
          QLinearGradient gradient(0, 0, 0, 400);
          gradient.setColorAt(0, QColor(90, 90, 90));
          gradient.setColorAt(0.38, QColor(105, 105, 105));
          gradient.setColorAt(1, QColor(70, 70, 70));
          ui->customPlot->setBackground(QBrush(gradient));


          // create empty bar chart objects:
          QCPBars *amande = new QCPBars(ui->customPlot->xAxis, ui->customPlot->yAxis);
          amande->setAntialiased(false);
          amande->setStackingGap(1);
           //set names and colors:
          amande->setName("Salaires");
          amande->setPen(QPen(QColor(0, 168, 140).lighter(130)));
          amande->setBrush(QColor(0, 168, 140));
          // stack bars on top of each other:


          // prepare x axis with country labels:
          QVector<double> ticks;
          QVector<QString> labels;

          QSqlQuery q;
          int i=0;
          q.exec("select num_contrat from contrat");
          while (q.next()) {
              QString adresse= q.value(0).toString();
              i++;
              ticks<<i;
              labels <<adresse;
          }
          QSharedPointer<QCPAxisTickerText> textTicker(new QCPAxisTickerText);
          textTicker->addTicks(ticks, labels);
          ui->customPlot->xAxis->setTicker(textTicker);
          ui->customPlot->xAxis->setTickLabelRotation(60);
          ui->customPlot->xAxis->setSubTicks(false);
          ui->customPlot->xAxis->setTickLength(0, 4);
          ui->customPlot->xAxis->setRange(0, 8);
          ui->customPlot->xAxis->setBasePen(QPen(Qt::white));
          ui->customPlot->xAxis->setTickPen(QPen(Qt::white));
          ui->customPlot->xAxis->grid()->setVisible(true);
          ui->customPlot->xAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));
          ui->customPlot->xAxis->setTickLabelColor(Qt::white);
          ui->customPlot->xAxis->setLabelColor(Qt::white);

          // prepare y axis:
          ui->customPlot->yAxis->setRange(0,3000);
          ui->customPlot->yAxis->setPadding(5); // a bit more space to the left border
          ui->customPlot->yAxis->setLabel("Statistiques");
          ui->customPlot->yAxis->setBasePen(QPen(Qt::white));
          ui->customPlot->yAxis->setTickPen(QPen(Qt::white));
          ui->customPlot->yAxis->setSubTickPen(QPen(Qt::white));
          ui->customPlot->yAxis->grid()->setSubGridVisible(true);
          ui->customPlot->yAxis->setTickLabelColor(Qt::white);
          ui->customPlot->yAxis->setLabelColor(Qt::white);
          ui->customPlot->yAxis->grid()->setPen(QPen(QColor(130, 130, 130), 0, Qt::SolidLine));
          ui->customPlot->yAxis->grid()->setSubGridPen(QPen(QColor(130, 130, 130), 0, Qt::DotLine));

          // Add data:

          QVector<double> PlaceData;
          QSqlQuery q1("select salaire from contrat ");
          while (q1.next()) {
                        int  nbr_fautee = q1.value(0).toInt();
                        PlaceData<< nbr_fautee;
                          }
          amande->setData(ticks, PlaceData);
          // setup legend:
          ui->customPlot->legend->setVisible(true);
          ui->customPlot->axisRect()->insetLayout()->setInsetAlignment(0, Qt::AlignTop|Qt::AlignHCenter);
          ui->customPlot->legend->setBrush(QColor(255, 255, 255, 100));
          ui->customPlot->legend->setBorderPen(Qt::NoPen);
          QFont legendFont = font();
          legendFont.setPointSize(10);
          ui->customPlot->legend->setFont(legendFont);
          ui->customPlot->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom);






}

