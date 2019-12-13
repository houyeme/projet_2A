#include "gestion_de_mediacament.h"
#include "ui_gestion_de_mediacament.h"
#include "medicament.h"
#include <src/SmtpMime>
#include "qcustomplot.h"
#include "notifcation.h"
#include <iostream>
using namespace std;
gestion_de_mediacament::gestion_de_mediacament(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_de_mediacament)
{
    ui->setupUi(this);
    refresh();
    ui->quantite_2->setValidator(new QRegExpValidator(QRegExp("[0-9]*"),this));
     ui->prix_2->setValidator(new QRegExpValidator(QRegExp("[0-9]*"),this));
     ui->type_3->setValidator(new QRegExpValidator(QRegExp("[a-z-A-Z]+"),this));
     music->setMedia(QUrl("C:/Users/USER/Desktop/True Detective - Intro Opening Song - Theme (The Handsome Family - Far From Any Road) + LYRICS.mp3"));
    //ARDUINO
    int ret=A.connect_arduino(); // lancer la connexion à arduino
     switch(ret){
     case(0):qDebug()<< "arduino is available and connected to : "<< A.getarduino_port_name();
         break;
     case(1):qDebug() << "arduino is available but not connected to :" <<A.getarduino_port_name();
        break;
     case(-1):qDebug() << "arduino is not available";
     }
 QObject::connect(A.getserial(),SIGNAL(A.read_from_arduino()),this,SLOT(update_label()));
 // permet de lancer
      //le slot update_label suite à la reception du signal readyRead (reception des données).
 }

gestion_de_mediacament::~gestion_de_mediacament()
{
    delete ui;
}

//ARDUINO
bool gestion_de_mediacament::verif_data(QByteArray data,char c){

    qDebug() << data;
    bool test=false;
    int i;
    for(i=0;i<data.length();i++){
    if(data.at(i)==c){
        test=true;
        return  test;
    }}


return test;

}
void gestion_de_mediacament::update_label()
{
    if(A.getserial()->waitForReadyRead(10))
    {    data = A.read_from_arduino();

    if(verif_data(data,'1')){
     notifcation n("stock","stock insuffisant");
     n.afficher();}
       }
    if(verif_data(data,'2')){
        notifcation n("movement","veuillez verifier la camera de surveillance svp");
        n.afficher();}

    if(verif_data(data,'4')){
        notifcation n("température","température >25");
        n.afficher();
       }
  }


void gestion_de_mediacament:: refresh()
{
    ui->tabmedicament->setModel(tmpmedicament.afficher_medicament());
    ui->tabequipement->setModel(tmpequipement_paramedicale.afficher_equipement_paramedicale());
    ui->comboBox->setModel(tmpmedicament.afficher_list());
    ui->comboBox_2->setModel(tmpmedicament.afficher_list());
    ui->comboBox_4->setModel(tmpequipement_paramedicale.afficher_list());
    ui->comboBox_3->setModel(tmpequipement_paramedicale.afficher_list());
}

void gestion_de_mediacament::on_ajouter_clicked()
{
    QString reference=ui->reference_2->text();
    QString etat=ui->type_2->text();
    int quantite=ui->quantite_2->text().toInt();
    int prix=ui->prix_2->text().toInt();
    medicament m(reference,etat,quantite,prix);
    if (ui->prix_2->hasAcceptableInput() && ui->quantite_2->hasAcceptableInput())
    {
    bool test=m.ajouter_medicament();
    if(test)
    {   refresh();
        if(A.getserial()->waitForReadyRead(50))
        data = A.read_from_arduino();
        qDebug() << "data : " << data;
        QMessageBox::information(this, "PAS D'ERREUR", " medicament ajouté");
    }
    else
    {
        if(A.getserial()->waitForReadyRead(50))

            data = A.read_from_arduino();
        qDebug() << "data : " << data;
        QMessageBox::critical(this, " ERREUR ", "medicament non ajouté ");
    }
}
}



void gestion_de_mediacament::on_supprimer_clicked()
{

  QString reference = ui->sup_line->text();
   medicament m;
   m.setrefrence(reference);
   bool test=m.supprimer_medicament();
   if(test)
   {   refresh();
       QMessageBox::information(this, "PAS D'ERREUR", " medicament supprimé");
   notifcation n("Attention ","Un medicament est supprimé de la base !");
   n.afficher();
   }
   else
   {
       QMessageBox::critical(this, " ERREUR ", "medicament non supprimé ");
   }
   ui->sup_line->clear();
}

void gestion_de_mediacament::on_modifier_clicked()
{
    tmpmedicament.setetat(ui->type_5->text());
    tmpmedicament.setquantitte(ui->quantite_5->text().toInt());
    tmpmedicament.setprix(ui->prix_6->text().toInt());

    bool test=tmpmedicament.modifier_medicament();
    if(test)
    {   refresh();
        QMessageBox::information(this, "PAS D'ERREUR", " medicament modifier");
    }
    else
    {
        QMessageBox::critical(this, " ERREUR ", "medicament non modifié ");
    }

}

void gestion_de_mediacament::on_comboBox_2_activated(const QString &arg1)
{
ui->sup_line->setText(arg1);
}

void gestion_de_mediacament::on_comboBox_activated(const QString &arg1)
{
  tmpmedicament.setrefrence(arg1);
  tmpmedicament.chercher();
  ui->type_5->setText(tmpmedicament.get_etat());
  ui->quantite_5->setText(QString::number(tmpmedicament.get_quantite()));
  ui->prix_6->setText(QString::number(tmpmedicament.get_prix()));
}

void gestion_de_mediacament::on_lineEdit_16_textChanged(const QString &arg1)
{
   ui->tabmedicament->setModel(tmpmedicament.recherche(champ,arg1,etat));
   valeur=arg1;

}

void gestion_de_mediacament::on_checkBox_stateChanged(int arg1)
{
    etat=arg1;
    ui->tabmedicament->setModel(tmpmedicament.recherche(champ,valeur,etat));

}

void gestion_de_mediacament::on_ajouter_2_clicked()
{    QString reference=ui->refpara_2->text();
     QString nom=ui->nom_2->text();
     QString type=ui->type_3->text();
     QString id_fournisseur=ui->idfour_2->text();
     equipement_paramedicale m(reference,nom,type,id_fournisseur);
      if (ui->type_3->hasAcceptableInput() )
      {
     bool test=m.ajouter_equipement_paramedicale();
      if(test)
      {   refresh();
          QMessageBox::information(this, "PAS D'ERREUR", " equipement ajouté");
      }
      else
      {
          QMessageBox::critical(this, " ERREUR ", "equipement non ajouté ");
      }
      }
 }

void gestion_de_mediacament::on_modifier_2_clicked()
{
    tmpequipement_paramedicale.setnom(ui->nomnom->text());
    tmpequipement_paramedicale.settype(ui->typetype->text());
    tmpequipement_paramedicale.setid_fournisseur(ui->fourfour->text());

    bool test=tmpequipement_paramedicale.modifier_equipement_paramedicale();
    if(test)
    {   refresh();
        QMessageBox::information(this, "PAS D'ERREUR", " equipement modifié");
    }
    else
    {
        QMessageBox::critical(this, " ERREUR ", " equipement non modifié ");
    }
}

void gestion_de_mediacament::on_supprimer_2_clicked()
{
    QString reference = ui->sup_line_2->text();
     equipement_paramedicale m;
     m.setrefrence(reference);
     bool test=m.supprimer_equipement_paramedicale();
     if(test)
     {   refresh();
         QMessageBox::information(this, "PAS D'ERREUR", " equipement supprimé");
     notifcation n("Attention ","Un equipement est supprimé de la base !");
     n.afficher();
     }
     else
     {
         QMessageBox::critical(this, " ERREUR ", " equipement non supprimé ");
     }
     ui->sup_line_2->clear();
}

void gestion_de_mediacament::on_comboBox_3_activated(const QString &arg1)
{
    tmpequipement_paramedicale.setrefrence(arg1);
    tmpequipement_paramedicale.chercher();
    ui->nomnom->setText(tmpequipement_paramedicale.get_nom());
    ui->typetype->setText(tmpequipement_paramedicale.get_type());
    ui->fourfour->setText(tmpequipement_paramedicale.get_id_fournisseur());
}

void gestion_de_mediacament::on_comboBox_4_activated(const QString &arg1)
{
ui->sup_line_2->setText(arg1);
}

void gestion_de_mediacament::on_lineEdit_17_textChanged(const QString &arg1)
{
    ui->tabequipement->setModel(tmpequipement_paramedicale.recherche(champ,arg1,etat));
    valeur=arg1;

}

void gestion_de_mediacament::on_checkBox_2_stateChanged(int arg1)
{
    etat=arg1;
    ui->tabequipement->setModel(tmpequipement_paramedicale.recherche(champ,valeur,etat));
}

void gestion_de_mediacament::on_envoyer_email_bott_clicked()
{

        SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);
        smtp.setUser("E.doctor.communication@gmail.com");
        smtp.setPassword("esprit19");
        MimeMessage message;
        message.setSender(new EmailAddress("E.doctor.communication@gmail.com", "Edoctor Communication"));
        QString emaiil =ui->khra->text();
        message.addRecipient(new EmailAddress(emaiil, ""));
        message.setSubject("Commande");
        MimeText text;
        QString emaill = ui->cp->toPlainText();
        text.setText(emaill);
        message.addPart(&text);
        smtp.connectToHost();
        smtp.login();
        if(smtp.sendMail(message))
        {
            QMessageBox::information(this, "PAS D'ERREUR", "Envoyé");
        }
        else
        {
            QMessageBox::critical(this, "ERREUR", "Non Envoyé (probleme de connexion)");
        }
        smtp.quit();

}



void gestion_de_mediacament::on_champ_activated(const QString &arg1)
{
    ui->lineEdit_17->setDisabled(false);
        champ=arg1;
        ui->checkBox_2->setDisabled(false);
}

void gestion_de_mediacament::on_champ_2_activated(const QString &arg1)
{
    ui->lineEdit_16->setDisabled(false);
    champ=arg1;
    ui->checkBox->setDisabled(false);

}




void gestion_de_mediacament::on_tabWidget_currentChanged(int index)
{

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
       amande->setName("Repartition des medicament selon leurs quantités ");
       amande->setPen(QPen(QColor(0, 168, 140).lighter(130)));
       amande->setBrush(QColor(0, 168, 140));
       // stack bars on top of each other:


       // prepare x axis with country labels:
       QVector<double> ticks;
       QVector<QString> labels;
       tmpmedicament.statistique(&ticks,&labels);

       /*QSqlQuery q;
       int i=0;
       q.exec("select reference from medicament");
       while (q.next()) {
           QString refer = q.value(0).toString();
           i++;
           ticks<<i;
           labels <<refer;
       }*/

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
       ui->customPlot->yAxis->setRange(0,10);
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
       QSqlQuery q1("select quantite from medicament");
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


       refresh();


}

void gestion_de_mediacament::on_pushButton_clicked()
{ close();
}

void gestion_de_mediacament::on_pushButton_2_clicked()
{
    close();
}

void gestion_de_mediacament::on_pushButton_3_clicked()
{
    close();
}

void gestion_de_mediacament::on_pushButton_4_clicked()
{
    close();
}

void gestion_de_mediacament::on_pushButton_5_clicked()
{
    close();
}

void gestion_de_mediacament::on_pushButton_6_clicked()
{
    close();
}

void gestion_de_mediacament::on_pushButton_7_clicked()
{
    close();
}

void gestion_de_mediacament::on_pushButton_8_clicked()
{
    close();
}

void gestion_de_mediacament::on_pushButton_11_clicked()
{
    close();
}

void gestion_de_mediacament::on_pushButton_12_clicked()
{
    close();
}

void gestion_de_mediacament::on_pushButton_9_clicked()
{
   music->play();
}

void gestion_de_mediacament::on_pushButton_10_clicked()
{
    music->pause();
}

void gestion_de_mediacament::on_verticalSlider_sliderMoved(int position)
{
    music->setVolume(position);
}

void gestion_de_mediacament::on_pushButton_13_clicked()
{
    update_label();
}
