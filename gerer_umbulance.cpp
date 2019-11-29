#include "gerer_umbulance.h"
#include "ui_gerer_umbulance.h"
#include <QFile>
#include<QTextStream>
#include<QMessageBox>
#include <QString>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include <QDateTime>
#include"smtp.h"


gerer_umbulance::gerer_umbulance(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::gerer_umbulance)
{
    ui->setupUi(this);
    QPixmap picture("C:/Users/User/Desktop/496.png");
    //ui->pic->setPixmap(picture);
    connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
      connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
    refresh();
//refresh2();
}

gerer_umbulance::~gerer_umbulance()
{
    delete ui;
}


void gerer_umbulance::on_date_dernier_ent_userDateChanged(const QDate &date)
{
    tmpambulance.setdateentretient(date.toString());

}

void gerer_umbulance::on_ajouter_clicked()
{
    tmpambulance.setmatricule(ui->matricule_2->text());
    tmpambulance.setetat(ui->etat_2->text());
    if(tmpambulance.ajouter()){
        refresh();

    }

}

void gerer_umbulance::on_supprimer_clicked()
{
    if(tmpambulance.supprimer(ui->supp->text())){
        refresh();
       ui->supp->clear();

    }
}
void gerer_umbulance::on_supprimer_2_clicked()
{

    if(tmpappel.supprimer2(ui->supp_2->text())){
        refresh();
       ui->supp_2->clear();

    }
}



void gerer_umbulance::on_modifier_clicked()
{
    tmpambulance.setetat(ui->etat_mod->text());
    if(tmpambulance.modifier()){
        refresh();

    }
}
void gerer_umbulance::on_modifier_2_clicked()
{
    tmpappel.setNom(ui->prenom->text());

    if(tmpappel.modifier2())
    {
        refresh();

    }
}

void gerer_umbulance::on_ajouter_2_clicked()
{

    tmpappel.setfichier(ui->fichier->text());
    tmpappel.setNom(ui->nom->text());
    tmpappel.setadresse(ui->adresse->text());
    tmpappel.setblessure(ui->blessure->text());
    if(tmpappel.ajouter2()){
        refresh();

    }
}

void gerer_umbulance::on_dateEdit_userDateChanged(const QDate &date)
{
    tmpambulance.setdateentretient(date.toString());
}
void  gerer_umbulance::refresh()
{
   ui->tab_ambulance->setModel(tmpambulance.afficher());
    ui->comboBox->setModel(tmpambulance.afficher_list());
    ui->comboBox_2->setModel(tmpambulance.afficher_list());
    ui->tab_urgence->setModel(tmpappel.afficher2());
    ui->comboBox_3->setModel(tmpappel.afficher_list2());
    ui->comboBox_4->setModel(tmpappel.afficher_list2());

}

void gerer_umbulance::on_comboBox_activated(const QString &arg1)
{
    tmpambulance.setmatricule(arg1);
     tmpambulance.chercher();
     ui->etat_mod->setText(tmpambulance.getetat());
ui->date_mod2->setText(tmpambulance.getdateentretient()) ;
}
void gerer_umbulance::on_comboBox_3_activated(const QString &arg1)
{
     tmpappel.setfichier(arg1);
     tmpappel.chercher2();
     ui->prenom->setText(tmpappel.getNom());
     ui->adresse_2->setText(tmpappel.getAdresse());
     ui->blessure_2->setText(tmpappel.getblessure());
}

void gerer_umbulance::on_comboBox_2_activated(const QString &arg1)
{
ui->supp->setText(arg1);
}






void gerer_umbulance::on_comboBox_4_activated(const QString &arg1)
{
    ui->supp_2->setText(arg1);
}




/*void gerer_umbulance::on_pushButton_clicked()
{    QFile file("C:\\Users\\User\\Desktop\\build-urgence-Desktop_Qt_5_13_1_MinGW_32_bit-Debug\\save.txt");
   // QFile file("C:\\Users\\User\\Desktop\\back-to-her-man.txt");
    if (!file.open(QIODevice::ReadOnly))
        QMessageBox::information(0,"info",file.errorString());
    QTextStream in(&file);
    ui->textBrowser->setText(in.readAll());
} */


/*void gerer_umbulance::on_mess_editingFinished()
{
    QFile file1("./save.txt");
    file1.open(QIODevice:: WriteOnly| QIODevice ::Text);
    QApplication::processEvents();
    QString b;
    b=ui->mess->text();
    QTextStream out(&file1);
    out << b;
}

void gerer_umbulance::on_mess_returnPressed()
{
    QString  input =ui->mess->text();
    QMessageBox msgbx;
    msgbx.setText(input);
    msgbx.exec();

}*/



void gerer_umbulance::on_pushButton_2_clicked()
{
    QPrinter printer;
    printer.setPrinterName("houyeme");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec()==QDialog::Rejected)
        return;
    ui->textEdit->print(&printer);

}

void gerer_umbulance::on_rechercher_clicked()
{
  QString mat= ui->valeur_rechercher->text();
ui->afficher_rechercher->setModel(tmpambulance.recherche(mat));
refresh();
}


void gerer_umbulance::on_send_clicked()
{
    QFile file1("./save.txt");
     // QFile file2("./save.txt");
       if(! file1.open(QIODevice:: WriteOnly| QIODevice ::Text))
       { QMessageBox::warning(this,"title","file not open");}
       QTextStream out(&file1);
       QString text=ui->plainTextEdit->toPlainText();
       out << text;

       file1.flush();
       file1.close();
       aff();
}
void gerer_umbulance::aff()
{
    QFile file("C:\\Users\\User\\Desktop\\build-urgence-Desktop_Qt_5_13_1_MinGW_32_bit-Debug\\save.txt");
     // QFile file("C:\\Users\\User\\Desktop\\back-to-her-man.txt");
      if (!file.open(QIODevice::ReadOnly))
          QMessageBox::information(0,"info",file.errorString());
      QTextStream in(&file);
      ui->textBrowser->setText(in.readAll());


}
void gerer_umbulance::aff2()
{
    QFile file("C:\\Users\\User\\Desktop\\build-urgence-Desktop_Qt_5_13_1_MinGW_32_bit-Debug\\save2.txt");
     // QFile file("C:\\Users\\User\\Desktop\\back-to-her-man.txt");
      if (!file.open(QIODevice::ReadOnly))
          QMessageBox::information(0,"info",file.errorString());
      QTextStream in(&file);
      ui->textBrowser_2->setText(in.readAll());


}

void gerer_umbulance::on_send_2_clicked()
{
    //QFile file1("./save.txt");
     QFile file1("./save2.txt");
       if(! file1.open(QIODevice:: WriteOnly| QIODevice ::Text))
       { QMessageBox::warning(this,"title","file not open");}
       QTextStream out(&file1);
       QString text=ui->plainTextEdit_2->toPlainText();
       out << text;

       file1.flush();
       file1.close();
       aff2();
}
/*void gerer_umbulance::reclamation()
{
    QDate d;

}*/
void gerer_umbulance::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toUShort());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));


    smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void gerer_umbulance:: mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}
