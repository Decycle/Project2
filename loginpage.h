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
    explicit LoginPage(QWidget *parent = nullptr, MainWindow *mainWindow = nullptr);
    ~LoginPage();

private slots:
    void on_loginBtn_clicked();

    void on_cancelBtn_clicked();

private:
    Ui::LoginPage *ui;
    MainWindow *mainWindow;
};

#endif // LOGINPAGE_H
