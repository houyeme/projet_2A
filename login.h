#ifndef LOGIN_H
#define LOGIN_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class login; }
QT_END_NAMESPACE

class login : public QMainWindow
{
    Q_OBJECT

public:
    login(QWidget *parent = nullptr);
    ~login();

private slots:
    void on_connecter_clicked();

    void on_comboBox_activated(int index);

    void on_pushButton_clicked();

private:
    Ui::login *ui;
    int espace=-1 ;//espace login
};
#endif // LOGIN_H
