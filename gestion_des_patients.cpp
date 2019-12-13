#include "gestion_des_patients.h"
#include "ui_gestion_des_patients.h"
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include "statistiques.h"
#include <QCheckBox>
#include <QPrinter>
#include <qpagedpaintdevice.h>
#include <QDialog>
#include <QPrintDialog>
#include "notifcation.h"
#include "statistique.h"
#include <QMediaPlayer>
gestion_des_patients::gestion_des_patients(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_des_patients)
{
    ui->setupUi(this);
    refresh();
        ui->prenom->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
        ui->nom->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
        ui->prenom_2->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
        ui->nom_2->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
    QPixmap pix("C:/Users/user/Downloads/rayen_bg.png");
    ui->label_5->setPixmap(pix);
    QPixmap pix1("C:/Users/user/Downloads/rayen_bg.png");
    ui->label_10->setPixmap(pix1);
    QPixmap pix2("C:/Users/user/Downloads/rayen_bg.png");
    ui->label_14->setPixmap(pix2);
    QPixmap pix4("C:/Users/user/Downloads/rayen_bg.png");
    ui->label_15->setPixmap(pix4);
    QPixmap pix5("C:/Users/user/Downloads/rayen_bg.png");
    ui->label_16->setPixmap(pix5);
    QPixmap pix6("C:/Users/user/Downloads/rayen_bg.png");
    ui->label_21->setPixmap(pix5);
    QPixmap pix7("C:/Users/user/Downloads/rayen_bg.png");
    ui->label_22->setPixmap(pix5);
    QPixmap pix8("C:/Users/user/Downloads/rayen_bg.png");
    ui->label_31->setPixmap(pix5);
    QPixmap pix9("C:/Users/user/Downloads/rayen_bg.png");
    ui->label_32->setPixmap(pix5);



}

gestion_des_patients::~gestion_des_patients()
{
    delete ui;
}

void gestion_des_patients::on_dateEdit_userDateChanged(const QDate &date)
{
    tmppatient.setdatedenaissance(date.toString());

}

void gestion_des_patients::on_ajouter_clicked()
{

    tmppatient.setreference(ui->reference->text());
    tmppatient.setnom(ui->nom->text());
    tmppatient.setprenom(ui->prenom->text());
    tmppatient.setsexe(sexe);
    if(ui->nom->hasAcceptableInput() && ui->prenom->hasAcceptableInput())
 {  if( tmppatient.ajouter_patient()){ refresh();
           notifcation n("News","Un nouveau patient a été ajouté !") ;
           player = new QMediaPlayer;
                   connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
                   player->setMedia(QUrl::fromLocalFile("C:/Users/ASUS/Downloads/ajout succe.mp3"));
                   player->setVolume(1000);
                   player->play();
          n.afficher();



}
}
}


void gestion_des_patients::on_archiver_clicked()
{

if(tmppatient.archiver_patient()){
    refresh();
    ui->supprimer->clear();
    player = new QMediaPlayer;
            connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
            player->setMedia(QUrl::fromLocalFile("C:/Users/ASUS/Downloads/supp succ.mp3"));
            player->setVolume(1000);
            player->play();
}

}

void gestion_des_patients::on_modifier_p_clicked()
{
    tmppatient.setnom(ui->nom_2->text());
    tmppatient.setprenom(ui->prenom_2->text());

       bool test=tmppatient.modifier_patient();
if(ui->nom_2->hasAcceptableInput() && ui->prenom_2->hasAcceptableInput()){
       if(test){refresh();
           player = new QMediaPlayer;
                   connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
                   player->setMedia(QUrl::fromLocalFile("C:/Users/ASUS/Downloads/modif succ.mp3"));
                   player->setVolume(1000);
                   player->play();}
 }
}
void gestion_des_patients::refresh(){
    ui->tabpatient->setModel(tmppatient.afficher_patient());
    ui->comboBox_2->setModel(tmppatient.afficher_liste_patient());
    ui->comboBox->setModel(tmppatient.afficher_liste_patient());
ui->references_patient->setModel(tmppatient.afficher_liste_patient());
ui->tabrendez->setModel(tmprend.afficher_rendez_vous());
ui->comboBox_3->setModel(tmprend.afficher_liste_rendez_vous());
ui->comboBox_4->setModel(tmprend.afficher_liste_rendez_vous());
ui->comboBox_6->setModel(tmpmedecin.afficher_liste_id());
ui->comboBox_7->setModel(tmpmedecin.afficher_liste_id());
}

void gestion_des_patients::on_comboBox_activated(const QString &arg1)
{
    tmppatient.setreference(arg1);
    tmppatient.chercher();
    ui->nom_2->setText(tmppatient.get_nom());
    ui->prenom_2->setText(tmppatient.get_prenom());
    ui->old_date->setText(tmppatient.get_datedenaissance());
}

void gestion_des_patients::on_comboBox_2_activated(const QString &arg1)
{
ui->supprimer->setText(arg1);
}

void gestion_des_patients::on_dateEdit_3_userDateChanged(const QDate &date)
{
    tmppatient.setdatedenaissance(date.toString());
}

void gestion_des_patients::on_recherche_tri_textChanged(const QString &arg1)
{
    ui->tabpatient->setModel(tmppatient.recherche(champ,arg1,etat));
   valeur=arg1;
}

void gestion_des_patients::on_checkBox_stateChanged(int arg1)
{
    etat=arg1;
    ui->tabpatient->setModel(tmppatient.recherche(champ,valeur,etat));

}

void gestion_des_patients::on_ajouter_2_clicked()
{
    tmprend.setid_med(ui->id_medecin->text());
    tmprend.setid_sec(ui->id_sec->text());
    tmprend.setnum_rendez_vous(ui->num->text().toInt());
    qDebug()<<tmprend.get_id_sec()<<tmprend.get_reference()<<tmprend.get_num_rendez_vous()<<tmprend.get_id_med();
    QTime nv_time;
    QDate nv_date;
    if(tmprend.chercher()){
        QMessageBox::warning(this, tr("ERREUR"), tr("rendez_vous déja existe.\n"));
    }else{
    while (tmprend.recherche_rendez_vous()){
        nv_time=tmprend.get_time_rendez_vous().addSecs(3600);
        tmprend.settime_rendez_vous( nv_time);
       if(nv_time.hour()>=16){
           nv_date=tmprend.get_date_rendez_vous();
           nv_date=nv_date.addDays(1);
           nv_time.setHMS(9,0,0);
           tmprend.setdate_rendez_vous(nv_date);
           tmprend.settime_rendez_vous(nv_time);
       }
    }
    if( tmprend.ajouter_rendez_vous()){ refresh();
        notifcation n("News","Un nouveau rendez-vous a été ajoutée !") ;
       n.afficher();
       player = new QMediaPlayer;
               connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
               player->setMedia(QUrl::fromLocalFile("C:/Users/ASUS/Downloads/ajout succe.mp3"));
               player->setVolume(1000);
               player->play();
}
    }

}
void gestion_des_patients::on_references_patient_activated(const QString &arg1)
{
tmprend.setreference(arg1);
}

void gestion_des_patients::on_dateEdit_4_userDateChanged(const QDate &date)
{
    tmprend.setdate_rendez_vous(date);

}


void gestion_des_patients::on_timeEdit_userTimeChanged(const QTime &time)
{
    tmprend.settime_rendez_vous(time);
}



void gestion_des_patients::on_radioButton_clicked(bool checked)
{
    if(checked){
        sexe="male";}
}

void gestion_des_patients::on_radioButton_2_clicked(bool checked)
{
    if(checked){
        sexe="female";
    }
}

void gestion_des_patients::on_pushButton_clicked()
{
    statistique *s = new statistique();
    s->show();
}

void gestion_des_patients::on_modifier_p_2_clicked()
{
    tmprend.setid_sec(ui->id_sec_4->text());
    tmprend.setid_med(ui->id_med->text());
    tmprend.setreference(ui->ref_4->text());

       bool test=tmprend.modifier_rendez_vous();

       if(test){refresh();
           player = new QMediaPlayer;
                   connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
                   player->setMedia(QUrl::fromLocalFile("C:/Users/ASUS/Downloads/modif succ.mp3"));
                   player->setVolume(1000);
                   player->play();}
}

void gestion_des_patients::on_comboBox_3_activated(const QString &arg1)
{
    tmprend.setnum_rendez_vous(arg1.toInt());
    tmprend.chercher();
    ui->id_sec_4->setText(tmprend.get_id_sec());
    ui->id_med->setText(tmprend.get_id_med());
    ui->dateEdit_5->setDate(tmprend.get_date_rendez_vous());
ui->ref_4->setText(tmprend.get_reference());
}

void gestion_des_patients::on_dateEdit_5_userDateChanged(const QDate &date)
{
    tmprend.setdate_rendez_vous(date);
}

void gestion_des_patients::on_comboBox_4_activated(const QString &arg1)
{
   ui->supprimer->setText(arg1);
}

void gestion_des_patients::on_archiver_2_clicked()
{
    if(tmprend.archiver_rendez_vous()){
        refresh();
        ui->supprimer->clear();
        player = new QMediaPlayer;
                connect(player, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
                player->setMedia(QUrl::fromLocalFile("C:/Users/ASUS/Downloads/supp succ.mp3"));
                player->setVolume(1000);
                player->play();
    }
}




void gestion_des_patients::on_champ_activated(const QString &arg1)
{
    ui->recherche_tri->setDisabled(false);
        champ=arg1;
        ui->checkBox->setDisabled(false);
}


void gestion_des_patients::on_comboBox_5_activated(const QString &arg1)
{

    ui->recherche_tri_2->setDisabled(false);
        champ=arg1;
        ui->checkBox_2->setDisabled(false);
}


void gestion_des_patients::on_checkBox_2_stateChanged(int arg1)
{
    etat=arg1;
    ui->tabrendez->setModel(tmprend.recherche(champ,valeur,etat));
}


void gestion_des_patients::on_recherche_tri_2_textChanged(const QString &arg1)
{
    ui->tabrendez->setModel(tmprend.recherche(champ,arg1,etat));
   valeur=arg1;
}

void gestion_des_patients::on_pushButton_2_clicked()
{
 QPrinter printer;
 printer.setPrinterName("printer name");
 QPrintDialog dialog(&printer,this);
  if(QDialog::Accepted == dialog.exec()){

      if(QPrinter::Landscape != printer.orientation())
             {
                 printer.setOrientation(QPrinter::Landscape);
             }
             QPoint startPoint = QPoint(20, 20);
             QRegion printRegion = QRegion( 20, 20, printer.paperRect().width(),printer.paperRect().height() );
                 for( int i = 0; i < 10; ++i ) // still need to fix this
                 {
                     ui->tabpatient->render( &printer, startPoint, printRegion, QWidget::DrawChildren );
                 }
  }

}

void gestion_des_patients::on_comboBox_6_activated(const QString &arg1)
{
    ui->id_medecin->setText(arg1);
}

void gestion_des_patients::on_comboBox_7_activated(const QString &arg1)
{
    ui->id_med->setText(arg1);
}
