#ifndef STUMAINWINDOW_H
#define STUMAINWINDOW_H

#include <QMainWindow>
#include"stumanagement.h"

namespace Ui {
class stuMainWindow;
}

class stuMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit stuMainWindow(QWidget *parent = 0);
    ~stuMainWindow();

private:
    Ui::stuMainWindow *ui;
};

#endif // STUMAINWINDOW_H
