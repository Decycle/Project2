#include "mainwindow.h"

#include <QApplication>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    QFile stylesheet(":/ui/ui.qss");
    stylesheet.open(QIODevice::ReadOnly);
    QString stylesheetString = QLatin1String(stylesheet.readAll());

    a.setStyleSheet(stylesheetString);

    w.show();
    return a.exec();
}
