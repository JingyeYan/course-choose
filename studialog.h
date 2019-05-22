#ifndef STUDIALOG_H
#define STUDIALOG_H

#include <QDialog>
#include<QString>
#include"stumanagement.h"

namespace Ui {
class stuDialog;
}

class stuDialog : public QDialog
{
    Q_OBJECT

public:
    stumanagement m_S;
    QString m_qstr;
    explicit stuDialog(QWidget *parent = 0);
    ~stuDialog();

private slots:
    void on_pushButton_clicked();



    void on_commandLinkButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::stuDialog *ui;
};

#endif // STUDIALOG_H
