#ifndef STADIUMEDITPAGE_H
#define STADIUMEDITPAGE_H

#include <QDialog>

namespace Ui {
class StadiumEditPage;
}

class StadiumEditPage : public QDialog
{
    Q_OBJECT

public:
    explicit StadiumEditPage(QWidget *parent = nullptr);
    ~StadiumEditPage();

private:
    Ui::StadiumEditPage *ui;
};

#endif // STADIUMEDITPAGE_H
