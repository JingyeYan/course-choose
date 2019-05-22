#ifndef STADIALOG_H
#define STADIALOG_H

#include <QDialog>
#include<stamanagement.h>

namespace Ui {
class staDialog;
}

class staDialog : public QDialog
{
    Q_OBJECT

public:
    stamanagement m_T;
    QString m_tqstr;
    explicit staDialog(QWidget *parent = 0);
    ~staDialog();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_commandLinkButton_clicked();

private:
    Ui::staDialog *ui;
};

#endif // STADIALOG_H
