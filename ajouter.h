#ifndef AJOUTER_H
#define AJOUTER_H

#include <QDialog>

namespace Ui {
class ajouter;
}

class ajouter : public QDialog
{
    Q_OBJECT

public:
    explicit ajouter(QWidget *parent = nullptr);
    ~ajouter();
    QString Getmat(){return mat;}
    QString Getnom(){return nom;}
private slots:
    void on_pushButton_clicked();

private:
    Ui::ajouter *ui;
    QString mat,nom;

};

#endif // AJOUTER_H
