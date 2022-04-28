#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class LoginPage;
}

class LoginPage : public QDialog
{
    Q_OBJECT

public:
    /******************************
     ** CONSTRUCTOR & DESTRUCTOR **
     ******************************/
    explicit LoginPage(QWidget *parent = nullptr, MainWindow *mainWindow = nullptr);
    ~LoginPage();

private slots:

    /**************
     ** MUTATORS **
     **************/
    void on_loginBtn_clicked();

    void on_cancelBtn_clicked();

private:
    Ui::LoginPage *ui;          // IN/OUT - ui
    MainWindow *mainWindow;     // IN/OUT - mainwindow
};

#endif // LOGINPAGE_H
