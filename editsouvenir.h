#ifndef EDITSOUVENIR_H
#define EDITSOUVENIR_H

#include <QDialog>

namespace Ui {
class EditSouvenir;
}

class EditSouvenir : public QDialog
{
    Q_OBJECT

public:
    /******************************
     ** CONSTRUCTOR & DESTRUCTOR **
     ******************************/
    explicit EditSouvenir(QWidget *parent = nullptr, int index=0);
    ~EditSouvenir();

private slots:
    void on_cancelBtn_clicked();
    void on_saveBtn_clicked();

private:
    Ui::EditSouvenir *ui;
    int index;
};

#endif // EDITSOUVENIR_H
