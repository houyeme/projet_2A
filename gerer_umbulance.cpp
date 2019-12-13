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
#include "mailling.h"
#include <QtMultimedia/QSound>
#include <QtMultimedia/QMediaPlayer>


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
    aff2();

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
{  //ui->tabWidget_2->setCurrentIndex(1);
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
  tmpappel.setadresse(ui->adresse_2->text());
  tmpappel.setblessure(ui->blessure_2->text());
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





void gerer_umbulance::on_rechercher_clicked()
{ bool test;
   ok=1;
  QString mat= ui->valeur_rechercher->text();
ui->afficher_rechercher->setModel(tmpambulance.recherche(mat,&test));
if(test){
    ui->pushButton->setDisabled(false);
    ui->pushButton_3->setDisabled(false);
    ui->pushButton_4->setDisabled(false);
}
refresh();
}


void gerer_umbulance::on_send_clicked()
{
  //  QFile file1("C:\\Users\\User\\Desktop\\save.txt");
     QFile file1("./save.txt");
       if(! file1.open(QIODevice:: WriteOnly| QIODevice ::Text))
       { QMessageBox::warning(this,"title","file not open");}
       QTextStream out(&file1);
       QString text=ui->plainTextEdit->toPlainText();
       out << text;

       file1.flush();
       file1.close();
       aff("C:\\Users\\ASUS\\Desktop\\qt\\build-interface_application-Desktop_Qt_5_13_1_MinGW_32_bit-Debug\\save.txt");

}
void gerer_umbulance::aff(QString filename)
{    QFile file(filename);
    //QFile file("C:\\Users\\ASUS\\Desktop\\qt\\build-interface_application-Desktop_Qt_5_13_1_MinGW_32_bit-Debug\\save.txt");
      if (!file.open(QIODevice::ReadOnly))
          QMessageBox::information(0,"info",file.errorString());
      QTextStream in(&file);
      ui->textBrowser->setText(in.readAll());


}
void gerer_umbulance::aff2()
{
    QFile file("C:\\Users\\ASUS\\Desktop\\qt\\build-interface_application-Desktop_Qt_5_13_1_MinGW_32_bit-Debug\\save2.txt");
     // QFile file("C:\\Users\\User\\Desktop\\back-to-her-man.txt");
      if (!file.open(QIODevice::ReadOnly))
          QMessageBox::information(0,"info",file.errorString());
      QTextStream in(&file);
      ui->textBrowser_2->setText(in.readAll());


}
void gerer_umbulance::aff3()
{
    QFile file("C:\\Users\\ASUS\\Desktop\\qt\\build-interface_application-Desktop_Qt_5_13_1_MinGW_32_bit-Debug\\sa.txt");
     // QFile file("C:\\Users\\User\\Desktop\\back-to-her-man.txt");
      if (!file.open(QIODevice::ReadOnly))
          QMessageBox::information(0,"info",file.errorString());
      QTextStream in(&file);
      ui->textBrowser_3->setText(in.readAll());
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


void gerer_umbulance::fekra(QString a)
{
    QFile file1("./s.txt");
      if(! file1.open(QIODevice:: WriteOnly| QIODevice ::Text))
      { QMessageBox::warning(this,"title","file not open");}
      QTextStream out(&file1);
      tmpambulance.setmatricule(a);
       tmpambulance.chercher();
      /* ui->etat_mod->setText(tmpambulance.getetat());
  ui->date_mod2->setText(tmpambulance.getdateentretient()) ;*/
       out<<"************************************************"<<endl;
       out<<"***VOITURE DE MATRICULE:"<<endl;
       out<<tmpambulance.getmatricule()<<endl;
         out<<"***Etat:"<<endl;
       out <<tmpambulance.getetat()<<endl;
         out<<"***Date de derniere entretient ::"<<endl;
         out<<tmpambulance.getdateentretient()<<endl;
          out<<"************************************************"<<endl;
          out<<"****Historique:"<<endl;


      //out << text;

      file1.flush();
      file1.close();

}
void gerer_umbulance:: fekra3(QString a)
{
    QFile file1("./s2.txt");
      if(! file1.open(QIODevice:: WriteOnly| QIODevice ::Text))
      { QMessageBox::warning(this,"title","file not open");}
      QTextStream out(&file1);
     // tmpambulance.setmatricule(a);

      // tmpambulance.chercher();
      tmpappel.setfichier(a);
      tmpappel.chercher2();


       out<< endl;
       out<<"******* fichier Num ";
       out<<tmpappel.getfichier();
       out<<" *******"<<endl;
         out<<"Nom et Prenom :"<<endl;
         out<<endl;
       out <<tmpappel.getNom()<<endl;
       out<<endl;
         out<<"Adresse :"<<endl;
         out<<endl;
         out<<tmpappel.getAdresse()<<endl;
         out<<endl;
          out<<"Type de Blessure:"<<endl;
          out<<endl;
          out<<tmpappel.getblessure()<<endl;
          out<<endl;
          out<<"Detail:"<<endl;
          out<<endl;




      file1.flush();
      file1.close();


}
void gerer_umbulance::fekra2(QString a)
{
    QFile file1("./discussion.txt");
      if(! file1.open(QIODevice:: WriteOnly| QIODevice ::Text))
      { QMessageBox::warning(this,"title","file not open");}
      QTextStream out(&file1);
      tmpambulance.setmatricule(a);
       tmpambulance.chercher();

       out<<"discussion a tritre voiture de matricule :"<<endl;
       out<<tmpambulance.getmatricule()<<endl;
      //out << text;

      file1.flush();
      file1.close();
}

void gerer_umbulance::on_pushButton_clicked()//mailing
{  QString a;
    a=ui->valeur_rechercher->text();
    fekra(a);
    QFile file("C:\\Users\\ASUS\\Desktop\\fournisseur.txt")
     ,file2("C:\\Users\\ASUS\\Desktop\\qt\\build-interface_application-Desktop_Qt_5_13_1_MinGW_32_bit-Debug\\s.txt");

         if (!file.open(QIODevice::ReadOnly))
             QMessageBox::information(0,"info",file.errorString());
         if (!file2.open(QIODevice::ReadOnly))
             QMessageBox::information(0,"info",file2.errorString());
         QTextStream in(&file);
         QTextStream in2(&file2);
         QString text=in.readAll();
         QString text2=in2.readAll();
         ui->rcpt->setText(text);
         ui->msg->setPlainText(text2);
         file.flush();
         file.close();
         file2.flush();
         file2.close();

    if(ok==1)
    {  /*mailling g;
        g.exec();*/
        ui->tabWidget_2->setCurrentIndex(3);

    }
    else

      {QMessageBox::information(this,"title","clickez recherche");}
}

void gerer_umbulance::on_pushButton_3_clicked()//facture
{

    QString a;
       a=ui->valeur_rechercher->text();
       fekra(a);
       QFile file("C:\\Users\\ASUS\\Desktop\\qt\\build-interface_application-Desktop_Qt_5_13_1_MinGW_32_bit-Debug\\s.txt");
           // QFile file("C:\\Users\\User\\Desktop\\back-to-her-man.txt");
            if (!file.open(QIODevice::ReadOnly))
                QMessageBox::information(0,"info",file.errorString());
            QTextStream in2(&file);
            QString text=in2.readAll();
            ui->plainTextEdit_4->setPlainText(text);
            file.flush();
            file.close();
       if(ok==1)
       {   /*facture g;
           g.exec();*/

          ui->tabWidget_3->setCurrentIndex(2);
       }
       else

         {QMessageBox::information(this,"title","clickez recherche");}



}



void gerer_umbulance::on_pushButton_4_clicked() //chitchat
{   QString a;
    QSound::play("C:\\Users\\User\\Desktop\\urgence\\img\\msg.wav");

    a=ui->valeur_rechercher->text();
    fekra2(a);
    QFile file("C:\\Users\\ASUS\\Desktop\\qt\\build-interface_application-Desktop_Qt_5_13_1_MinGW_32_bit-Debug\\discussion.txt");
     // QFile file("C:\\Users\\User\\Desktop\\back-to-her-man.txt");
      if (!file.open(QIODevice::ReadOnly))
          QMessageBox::information(0,"info",file.errorString());
      QTextStream in(&file);
      ui->textBrowser_5->setText(in.readAll());


        if(ok==1)
        {   /*choix1 g;
            g.exec();*/
            ui->tabWidget_2->setCurrentIndex(2);
        }
        else

          {QMessageBox::information(this,"title","clickez recherche");}


}

/*void gerer_umbulance::on_pushButton_5_clicked()   ps //click ou cas des multi ui (mailing)
{   // ui->tabWidget_4->setCurrentIndex(0);
    QFile file("C:\\Users\\User\\Desktop\\fournisseur.txt")
     ,file2("C:\\Users\\User\\Desktop\\build-urgence-Desktop_Qt_5_13_1_MinGW_32_bit-Debug\\s.txt");

         if (!file.open(QIODevice::ReadOnly))
             QMessageBox::information(0,"info",file.errorString());
         if (!file2.open(QIODevice::ReadOnly))
             QMessageBox::information(0,"info",file2.errorString());
         QTextStream in(&file);
         QTextStream in2(&file2);
         QString text=in.readAll();
         QString text2=in2.readAll();
         ui->rcpt->setText(text);
         ui->msg->setPlainText(text2);
         file.flush();
         file.close();
         file2.flush();
         file2.close();
}*/
void gerer_umbulance::set_table_id(int i){
    ui->tabWidget_4->setCurrentIndex(i);
}





void gerer_umbulance::on_send_3_clicked()//chitchatboxtab1
{

    QSound::play("C:\\Users\\User\\Desktop\\urgence\\img\\msg.wav");
        QFile file1("./sa.txt");

          if(! file1.open(QIODevice:: WriteOnly| QIODevice ::Text))
          { QMessageBox::warning(this,"title","file not open");}
          QTextStream out(&file1);
          QString text=ui->plainTextEdit_3->toPlainText();
          out << text;

          file1.flush();
          file1.close();
          aff3();
}



void gerer_umbulance::on_pushButton_2_clicked()
{

    QPrinter printer;
    printer.setPrinterName("houyeme");
    QPrintDialog dialog(&printer,this);
    if(dialog.exec()==QDialog::Rejected)
        return;
    ui->plainTextEdit_4->print(&printer);
}

void gerer_umbulance::on_add_clicked()
{
    QFile file("C:\\Users\\ASUS\\Desktop\\qt\\build-interface_application-Desktop_Qt_5_13_1_MinGW_32_bit-Debug\\s.txt");
        if (!file.open(QIODevice::WriteOnly))
            QMessageBox::information(0,"info",file.errorString());
        QTextStream out(&file);
        QString text=ui->plainTextEdit_4->toPlainText();
        out<<text;
        file.flush();
        file.close();
}

void gerer_umbulance::on_rechercher_2_clicked()
{
    bool test;
       ok=1;
      QString mat= ui->valeur_rechercher_2->text();
    ui->afficher_rechercher_2->setModel(tmpappel.recherche2(mat,&test));
    if(test){
        ui->pushButton_6->setDisabled(false);
        ui->pushButton_7->setDisabled(false);
        ui->pushButton_8->setDisabled(false);}
}

void gerer_umbulance::on_pushButton_6_clicked()//mailling tab2
{
     ui->tabWidget_4->setCurrentIndex(3);
     QString a;
         a=ui->valeur_rechercher_2->text();
         fekra3(a);
        QFile file("C:\\Users\\ASUS\\Desktop\\fournisseur.txt")
         ,file2("C:\\Users\\ASUS\\Desktop\\qt\\build-interface_application-Desktop_Qt_5_13_1_MinGW_32_bit-Debug\\s2.txt");

             if (!file.open(QIODevice::ReadOnly))
                 QMessageBox::information(0,"info",file.errorString());
             if (!file2.open(QIODevice::ReadOnly))
                 QMessageBox::information(0,"info",file2.errorString());
             QTextStream in(&file);
             QTextStream in2(&file2);
             QString text=in.readAll();
             QString text2=in2.readAll();
             ui->rcpt->setText(text);
             ui->msg->setPlainText(text2);
             file.flush();
             file.close();
             file2.flush();
             file2.close();
}

void gerer_umbulance::on_pushButton_9_clicked()
{
    if(ui->checkBox->isChecked())
    {
        ui->checkBox->animateClick(100);
        /* gerer_umbulance g;


                    g.exec();
                    g.set_table_id(6);*/
                     QFile file("C:\\Users\\ASUS\\Desktop\\fournisseur.txt");
                        if (!file.open(QIODevice::WriteOnly))
                            QMessageBox::information(0,"info",file.errorString());
                        QTextStream out(&file);

                        out<<"info@toppiecesvoiture.fr";
                        file.flush();
                        file.close();

         ui->tabWidget_3->setCurrentIndex(3);

    }
    else if(ui->checkBox_2->isChecked())
    { /*gerer_umbulance g;
        g.exec();*/

        QFile file("C:\\Users\\ASUS\\Desktop\\fournisseur.txt");
           if (!file.open(QIODevice::WriteOnly))
               QMessageBox::information(0,"info",file.errorString());
           QTextStream out(&file);

           out<<"info@padanadiesel.net";
           file.flush();
           file.close();
           ui->tabWidget_3->setCurrentIndex(3);
    }
    else if(ui->checkBox_3->isChecked())
    { /*gerer_umbulance g;
        g.exec();*/
        QFile file("C:\\Users\\ASUS\\Desktop\\fournisseur.txt");
           if (!file.open(QIODevice::WriteOnly))
               QMessageBox::information(0,"info",file.errorString());
           QTextStream out(&file);

           out<<"mkhinini.houyeme@gmail.com";
           file.flush();
           file.close();
           ui->tabWidget_3->setCurrentIndex(3);
    }
    else
    {
        QMessageBox::information(this,"title","check first");
    }

}

void gerer_umbulance::on_pushButton_8_clicked()//facture
{
    QString a;
       a=ui->valeur_rechercher_2->text();
       fekra3(a);
       QFile file("C:\\Users\\ASUS\\Desktop\\qt\\build-interface_application-Desktop_Qt_5_13_1_MinGW_32_bit-Debug\\s2.txt");
           // QFile file("C:\\Users\\User\\Desktop\\back-to-her-man.txt");
            if (!file.open(QIODevice::ReadOnly))
                QMessageBox::information(0,"info",file.errorString());
            QTextStream in2(&file);
            QString text=in2.readAll();
            ui->plainTextEdit_4->setPlainText(text);
            file.flush();
            file.close();
       if(ok==1)
       {   /*facture g;
           g.exec();*/

          ui->tabWidget_3->setCurrentIndex(2);
       }
       else

         {QMessageBox::information(this,"title","clickez recherche");}


}

void gerer_umbulance::on_pushButton_7_clicked()
{
    ui->tabWidget_4->setCurrentIndex(2);
}

void gerer_umbulance::on_pushButton_10_clicked()
{
     ui->tabWidget_3->setCurrentIndex(3);
}

