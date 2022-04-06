#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "line.h"
#include "stadium.h"

#include <QMainWindow>
#include <QGraphicsScene>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void login();

private slots:
    void advance();

    void on_startPathBtn_clicked();

    void on_randomStadiumBtn_clicked();

    void on_loginBtn_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QTimer *timer;
    Line **lines;
    Stadium **stadiums;
    int step;
    bool loggedIn;

};
#endif // MAINWINDOW_H
