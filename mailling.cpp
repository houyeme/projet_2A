#include "mailling.h"
#include "ui_mailling.h"
#include <QFile>
#include<QTextStream>
#include<QMessageBox>
#include <QString>
#include<QtPrintSupport/QPrinter>
#include<QtPrintSupport/QPrintDialog>
#include <QDateTime>
#include"smtp.h"
#include <QtMultimedia/QSound>
#include <QtMultimedia/QMediaPlayer>
mailling::mailling(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mailling)
{
    ui->setupUi(this);
}

mailling::~mailling()
{
    delete ui;
}

void mailling::on_pushButton_clicked()
{
    if(ui->checkBox->isChecked())
    {
        ui->checkBox->animateClick(100);
         gerer_umbulance g;


                    g.exec();
                    g.set_table_id(6);
                     QFile file("C:\\Users\\User\\Desktop\\fournisseur.txt");
                        if (!file.open(QIODevice::WriteOnly))
                            QMessageBox::information(0,"info",file.errorString());
                        QTextStream out(&file);

                        out<<"info@toppiecesvoiture.fr";
                        file.flush();
                        file.close();



    }
    else if(ui->checkBox_2->isChecked())
    { gerer_umbulance g;
        g.exec();
        QFile file("C:\\Users\\User\\Desktop\\fournisseur.txt");
           if (!file.open(QIODevice::WriteOnly))
               QMessageBox::information(0,"info",file.errorString());
           QTextStream out(&file);

           out<<"info@padanadiesel.net";
           file.flush();
           file.close();
    }
    else if(ui->checkBox_3->isChecked())
    { gerer_umbulance g;
        g.exec();
        QFile file("C:\\Users\\User\\Desktop\\fournisseur.txt");
           if (!file.open(QIODevice::WriteOnly))
               QMessageBox::information(0,"info",file.errorString());
           QTextStream out(&file);

           out<<"mkhinini.houyeme@gmail.com";
           file.flush();
           file.close();
    }
    else
    {
        QMessageBox::information(this,"title","check first");
    }
}
