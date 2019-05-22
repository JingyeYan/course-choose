#include "stumainwindow.h"
#include "ui_stumainwindow.h"

stuMainWindow::stuMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::stuMainWindow)
{
    ui->setupUi(this);

}

stuMainWindow::~stuMainWindow()
{
    delete ui;
}
