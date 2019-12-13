#include "gestion_equipement.h"
#include "ui_gestion_equipement.h"
#include "smtp.h"
#include <QFile>
#include<QTextStream>
#include<QMessageBox>
#include <QString>

gestion_equipement::gestion_equipement(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gestion_equipement)
{
    ui->setupUi(this);

connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
ui->lineEdit_2->setValidator(new QRegExpValidator (QRegExp("[a-z-A-Z]+"),this));
ui->lineEdit_3->setValidator(new QRegExpValidator (QRegExp("[a-z-A-Z]+"),this));
ui->lineEdit_5->setValidator(new QRegExpValidator (QRegExp("[a-z-A-Z]+"),this));
ui->lineEdit_6->setValidator(new QRegExpValidator (QRegExp("[a-z-A-Z]+"),this));
ui->lineEdit_7->setValidator(new QRegExpValidator (QRegExp("[0-9]+"),this));

refresh();
diss();
aff();

music->setMedia(QUrl("C:/Users/ASUS/Desktop/Nouveau dossier (2)/Ash - Mosaïque.mp3"));
}


gestion_equipement::~gestion_equipement()
{
    delete ui;
}

void gestion_equipement::on_pb_ajouter_clicked()
{
   QString reference = ui->lineEdit_1->text();
     QString nom = ui->lineEdit_2->text();
     QString type = ui->lineEdit_3->text();
    QString id  = ui->id_combobox->currentText();
     equipement e(id,type,nom,reference,pays );
    if(ui->lineEdit_2->hasAcceptableInput() && ui->lineEdit_3->hasAcceptableInput())
      {

  bool test=e.ajouter();
  if(test)
{refresh();//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un equipement"),
                  QObject::tr("equipement ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un equipement"),
                  QObject::tr("Déja saisie !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
}

void gestion_equipement::on_pb_supprimer_clicked()
{
bool test=tmprdv.supprimer(ui->sup_ref->text());
if(test)
{refresh();//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un equipement"),
                QObject::tr("equipement supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
ui->sup_ref->clear();
}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un equipement"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}

void gestion_equipement::on_pb_ajouter_2_clicked()
{
    QString id = ui->lineEdit_4->text();
    QString nom = ui->lineEdit_5->text();
    QString prenom = ui->lineEdit_6->text();
    QString telephone = ui->lineEdit_7->text();
    QString adresse = ui->lineEdit_8->text();
    QString domaine = ui->lineEdit_15->text();
 fournisseur e(id,nom,prenom,telephone,adresse,domaine );
 bool test=e.ajouter();
 if(test)
 {refresh();//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un fournisseur"),
                 QObject::tr("fournisseur ajouté.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);
}
 else
     QMessageBox::critical(nullptr, QObject::tr("Ajouter un fournisseur"),
                 QObject::tr("Erreur !.\n"
                             "Click Cancel to exit."), QMessageBox::Cancel);


}

void gestion_equipement::on_pb_supprimer_2_clicked()
{
    bool test=tmprdv1.supprimer(ui->lineEdit_12->text());
    if(test)
    {refresh();//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer un fournisseur"),
                    QObject::tr("fournisseur supprimé.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
ui->lineEdit_12->clear();
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer un fournisseur"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}
void gestion_equipement::refresh(){
ui->tabetudiant->setModel(tmprdv.afficher());
ui->comboBox_2->setModel(tmprdv.afficherlist());
ui->comboBox_3->setModel(tmprdv.afficherlist());
ui->tabetudiant_2->setModel(tmprdv1.afficher());
ui->comboBox->setModel(tmprdv1.afficherlist());
ui->comboBox_4->setModel(tmprdv1.afficherlist());
ui->id_combobox->setModel(tmprdv1.GetIdModelFournisseur());
ui->combo_id->setModel(tmprdv1.GetIdModelFournisseur());
}

void gestion_equipement::on_comboBox_3_activated(const QString &arg1)
{
ui->sup_ref->setText(arg1);
}

void gestion_equipement::on_comboBox_2_activated(const QString &arg1)
{
tmprdv.set_reference(arg1);
tmprdv.chercher();
ui->lineEdit_10->setText(tmprdv.get_nom());
ui->lineEdit_9->setText(tmprdv.get_type());

//ui->combo_id->setText(tmprdv.get_id());
}

void gestion_equipement::on_comboBox_4_activated(const QString &arg1)
{
 ui->lineEdit_12->setText(arg1);
}

void gestion_equipement::on_comboBox_activated(const QString &arg1)
{
    tmprdv1.set_id(arg1);
    tmprdv1.chercher();
    ui->lineEdit_14->setText(tmprdv1.get_nom());
    ui->lineEdit_13->setText(tmprdv1.get_prenom());
    ui->lineEdit_17->setText(tmprdv1.get_telephone());
     ui->lineEdit_18->setText(tmprdv1.get_adresse());
      ui->lineEdit_19->setText(tmprdv1.get_domaine());
}



void gestion_equipement::on_pushButton_clicked()
{
tmprdv.set_nom(ui->lineEdit_10->text());
tmprdv.set_type(ui->lineEdit_9->text());
tmprdv.set_id(ui->combo_id->currentText());
tmprdv.set_pays(pays1);
if(tmprdv.modifier()){
    QMessageBox::information(nullptr, QObject::tr("modifier un equipement"),
                QObject::tr("equipement modifié !!.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
    refresh();

}
}

void gestion_equipement::on_pushButton_2_clicked()
{
    tmprdv1.set_nom(ui->lineEdit_14->text());
    tmprdv1.set_prenom(ui->lineEdit_13->text());
    tmprdv1.set_telephone(ui->lineEdit_17->text());
    tmprdv1.set_adresse(ui->lineEdit_18->text());
    tmprdv1.set_domaine(ui->lineEdit_19->text());
    if(tmprdv1.modifier()){
        QMessageBox::information(nullptr, QObject::tr("modifier un fournisseur"),
                    QObject::tr("fournisseur modifié !!.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        refresh();
    }
}


void gestion_equipement::on_lineEdit_16_textChanged(const QString &arg1)
{
valeur=arg1;
    ui->tabetudiant->setModel(tmprdv.recherche(arg1,etat,champ));

}

void gestion_equipement::on_lineEdit_20_textChanged(const QString &arg1)
{
    ui->tabetudiant_2->setModel(tmprdv1.recherche(arg1));

}

void gestion_equipement::on_checkBox_stateChanged(int arg1)
{
    etat=arg1;
    ui->tabetudiant->setModel(tmprdv.recherche(valeur,etat,champ));

}
void gestion_equipement::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toUShort());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void gestion_equipement::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}






void gestion_equipement::on_radioButton_toggled(bool checked)
{
    if(checked)
        pays="Tunis";
}

void gestion_equipement::on_radioButton_2_clicked(bool checked)
{
    if(checked)
        pays="Importe";
}

void gestion_equipement::on_pushButton_3_clicked()
{
    statistiques* p = new statistiques();
    p->setWindowModality(Qt::ApplicationModal);
   p->show();
}

void gestion_equipement::on_radioButton_3_clicked(bool checked)
{ if(checked)
    pays1="Tunis";

}

void gestion_equipement::on_radioButton_4_clicked(bool checked)
{  if (checked)
    pays1="Importe";
}

void gestion_equipement::on_pushButton_4_clicked()
{
    music->play();
}

void gestion_equipement::on_pushButton_5_clicked()
{
    music->pause();
}

void gestion_equipement::on_verticalSlider_sliderMoved(int position)
{
     music->setVolume(position);
}

void gestion_equipement::on_envoyer_email_bott_clicked()
{
    SmtpClient smtp("smtp.gmail.com", 465, SmtpClient::SslConnection);
            smtp.setUser("mohammedamine.kridiss@esprit.tn");
            smtp.setPassword("181JMT1025");
            MimeMessage message;
            message.setSender(new EmailAddress("mohammedamine.kridiss@esprit.tn", "Kridis Med Amine"));
            QString emaiil =ui->khra->text();
            message.addRecipient(new EmailAddress(emaiil, "Kridis Med Amine"));
            message.setSubject("equipement");
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
void gestion_equipement::aff()
{
    QFile file("C:\\Users\\ASUS\\Desktop\\qt\\build-interface_application-Desktop_Qt_5_13_1_MinGW_32_bit-Debug\\save.txt");
         // QFile file("C:\\Users\\User\\Desktop\\back-to-her-man.txt");
          if (!file.open(QIODevice::ReadOnly))
              QMessageBox::information(0,"info",file.errorString());
          QTextStream in(&file);
          ui->text1->setText(in.readAll());
}
void gestion_equipement::aff2()
{
    QFile file("C:\\Users\\ASUS\\Desktop\\qt\\build-interface_application-Desktop_Qt_5_13_1_MinGW_32_bit-Debug\\save2.txt");
         // QFile file("C:\\Users\\User\\Desktop\\back-to-her-man.txt");
          if (!file.open(QIODevice::ReadOnly))
              QMessageBox::information(0,"info",file.errorString());
          QTextStream in(&file);
          ui->textBrowser_2->setText(in.readAll());
}
void gestion_equipement::diss()
{
    QFile file("C:\\Users\\ASUS\\Desktop\\qt\\build-interface_application-Desktop_Qt_5_13_1_MinGW_32_bit-Debug\\discussion.txt");
         // QFile file("C:\\Users\\User\\Desktop\\back-to-her-man.txt");
          if (!file.open(QIODevice::ReadOnly))
              QMessageBox::information(0,"info",file.errorString());
          QTextStream in(&file);
          ui->textBrowser_3->setText(in.readAll());
}




void gestion_equipement::on_send_clicked()
{
    QFile file1("./save2.txt");

          if(! file1.open(QIODevice:: WriteOnly| QIODevice ::Text))
          { QMessageBox::warning(this,"title","file not open");}
          QTextStream out(&file1);
          QString text=ui->plainTextEdit->toPlainText();
          out << text;

          file1.flush();
          file1.close();
          aff2();
          ui->plainTextEdit->clear();

}

void gestion_equipement::on_comboBox_5_activated(const QString &arg1)
{
if(!(arg1=="Champ")){
    ui->lineEdit_16->setEnabled(true);
    champ=arg1;
}else{
    ui->lineEdit_16->setEnabled(false);

}
}
void gestion_equipement::par_defaut(){
   {
    ui->centralwidget->setStyleSheet("");
    ui->centralwidget->setStyleSheet("#centralwidget{background-image: url(:/bakground/bg.png);}"
    "#icon{"
    "background-image: url(:/bakground/icon-authentification.png);"
    "}"
    "Qlabel{"
    "font: 15pt Arial;"
    "color:white;"
    "background-color :#2da5d5;"
    "border-top-right-radius: 5px 5px;"
    "border-bottom-right-radius: 5px 5px;"
    "}"
    "QLineEdit {"
    "background:transparent;"
    "border:none;"
    "border-bottom:1px solid #2da5d5;"
    "font: 12pt Arial;"
    "color: #2da5d5;"
    "}"
    "QPushButton{"
    "font: 15pt Arial ;"
    "color:white;"
    "background-color :#2da5d5;"
    "border-bottom-left-radius: 10px 10px;"
    "border-bottom-right-radius: 10px 10px;"
    "}"
    "QPushButton:hover{"
    "background-color:rgba(126,214,216,0.8);}"
    "QComboBox{"
    "font: 15pt Arial;"
    "color:white;"
    "background-color :#2da5d5;"
    "border-top-right-radius: 5px 5px;"
    "border-bottom-right-radius: 5px 5px;"
    "}"

    "QComboBox:drop-down {"

    "  border:none;} "
    "QComboBox QAbstractItemView {"
    " font: 15pt Arial;"
    "color:white;"
    "background-color :#2da5d5;"
    "selection-background-color: rgb(254, 120, 126);}" );
    }

}
