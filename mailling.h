#ifndef MAILLING_H
#define MAILLING_H

#include <QDialog>
#include"gerer_umbulance.h"

namespace Ui {
class mailling;
}

class mailling : public QDialog
{
    Q_OBJECT

public:
    explicit mailling(QWidget *parent = nullptr);
    ~mailling();

private slots:
    void on_pushButton_clicked();

private:
    Ui::mailling *ui;
};

#endif // MAILLING_H
