#include "ajouter.h"
#include "ui_ajouter.h"
ajouter::ajouter(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ajouter)
{
    ui->setupUi(this);
}

ajouter::~ajouter()
{
    delete ui;
}

void ajouter::on_pushButton_clicked()
{
 mat=ui->lineEdit->text();
 nom=ui->lineEdit->text();

    close();

}
