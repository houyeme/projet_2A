#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "equipement.h"
#include "fournisseur.h"
#include <QMessageBox>
#include "statistiques.h"
#include "src/SmtpMime"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
ui->lineEdit_2->setValidator(new QRegExpValidator (QRegExp("[a-z-A-Z]+"),this));
ui->lineEdit_3->setValidator(new QRegExpValidator (QRegExp("[a-z-A-Z]+"),this));
refresh();
QPixmap pix("C:/Users/amine/Desktop/pic.jpg");
ui->label_24->setPixmap(pix);
QPixmap pix1("C:/Users/amine/Desktop/pic.jpg");
ui->label_25->setPixmap(pix1);
QPixmap pix2("C:/Users/amine/Desktop/pic.jpg");
ui->label_27->setPixmap(pix2);
QPixmap pix3("C:/Users/amine/Desktop/pic.jpg");
ui->label_28->setPixmap(pix3);
QPixmap pix4("C:/Users/amine/Desktop/pic.jpg");
ui->label_29->setPixmap(pix4);
QPixmap pix5("C:/Users/amine/Desktop/pic.jpg");
ui->label_30->setPixmap(pix5);
QPixmap pix6("C:/Users/amine/Desktop/pic.jpg");
ui->label_31->setPixmap(pix6);
QPixmap pix7("C:/Users/amine/Desktop/pic.jpg");
ui->label_32->setPixmap(pix7);
QPixmap pix8("C:/Users/amine/Desktop/pic.jpg");
ui->label_33->setPixmap(pix8);
music->setMedia(QUrl("C:/Users/amine/Desktop/nouveau dossier/beethoveen.mp3"));
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
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

void MainWindow::on_pb_supprimer_clicked()
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

void MainWindow::on_pb_ajouter_2_clicked()
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

void MainWindow::on_pb_supprimer_2_clicked()
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
void MainWindow::refresh(){
ui->tabetudiant->setModel(tmprdv.afficher());
ui->comboBox_2->setModel(tmprdv.afficherlist());
ui->comboBox_3->setModel(tmprdv.afficherlist());
ui->tabetudiant_2->setModel(tmprdv1.afficher());
ui->comboBox->setModel(tmprdv1.afficherlist());
ui->comboBox_4->setModel(tmprdv1.afficherlist());
ui->id_combobox->setModel(tmprdv1.GetIdModelFournisseur());
ui->combo_id->setModel(tmprdv1.GetIdModelFournisseur());
}

void MainWindow::on_comboBox_3_activated(const QString &arg1)
{
ui->sup_ref->setText(arg1);
}

void MainWindow::on_comboBox_2_activated(const QString &arg1)
{
tmprdv.set_reference(arg1);
tmprdv.chercher();
ui->lineEdit_10->setText(tmprdv.get_nom());
ui->lineEdit_9->setText(tmprdv.get_type());

//ui->combo_id->setText(tmprdv.get_id());
}

void MainWindow::on_comboBox_4_activated(const QString &arg1)
{
 ui->lineEdit_12->setText(arg1);
}

void MainWindow::on_comboBox_activated(const QString &arg1)
{
    tmprdv1.set_id(arg1);
    tmprdv1.chercher();
    ui->lineEdit_14->setText(tmprdv1.get_nom());
    ui->lineEdit_13->setText(tmprdv1.get_prenom());
    ui->lineEdit_17->setText(tmprdv1.get_telephone());
     ui->lineEdit_18->setText(tmprdv1.get_adresse());
      ui->lineEdit_19->setText(tmprdv1.get_domaine());
}



void MainWindow::on_pushButton_clicked()
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

void MainWindow::on_pushButton_2_clicked()
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


void MainWindow::on_lineEdit_16_textChanged(const QString &arg1)
{
valeur=arg1;
    ui->tabetudiant->setModel(tmprdv.recherche(arg1,etat));

}

void MainWindow::on_lineEdit_20_textChanged(const QString &arg1)
{
    ui->tabetudiant_2->setModel(tmprdv1.recherche(arg1));

}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    etat=arg1;
    ui->tabetudiant->setModel(tmprdv.recherche(valeur,etat));

}
void MainWindow::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toUShort());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}






void MainWindow::on_radioButton_toggled(bool checked)
{
    if(checked)
        pays="Tunis";
}

void MainWindow::on_radioButton_2_clicked(bool checked)
{
    if(checked)
        pays="Importe";
}

void MainWindow::on_pushButton_3_clicked()
{
    statistiques *p = new statistiques();
    p->setWindowModality(Qt::ApplicationModal);
    p->show();
}

void MainWindow::on_radioButton_3_clicked(bool checked)
{ if(checked)
    pays1="Tunis";

}

void MainWindow::on_radioButton_4_clicked(bool checked)
{  if (checked)
    pays1="Importe";
}

void MainWindow::on_pushButton_4_clicked()
{
    music->play();
}

void MainWindow::on_pushButton_5_clicked()
{
    music->pause();
}

void MainWindow::on_verticalSlider_sliderMoved(int position)
{
     music->setVolume(position);
}

void MainWindow::on_envoyer_email_bott_clicked()
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
