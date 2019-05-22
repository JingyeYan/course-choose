#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_A.input();
    ui->commandLinkButton->hide();
    ui->commandLinkButton_2->hide();

    ui->commandLinkButton_4->hide();
    ui->lineEdit->hide();
    ui->pushButton_4->hide();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
    ui->pushButton_8->hide();
    ui->pushButton_9->hide();
    ui->pushButton_10->hide();
    ui->pushButton_11->hide();
    ui->pushButton_12->hide();
    ui->pushButton_13->hide();

    ui->pushButton_15->hide();
    ui->pushButton_16->hide();
    ui->pushButton_17->hide();
    ui->pushButton_18->hide();
    ui->pushButton_19->hide();
    ui->pushButton_20->hide();

    ui->textEdit->hide();

}

MainWindow::~MainWindow()
{

    delete ui;
}

void MainWindow::on_pushButton_clicked()            //教师入口
{
   sta.exec();
}

void MainWindow::on_pushButton_2_clicked()           //学生入口
{

   stu.exec();
}

void MainWindow::on_pushButton_3_clicked()      //管理员入口
{
    ui->commandLinkButton->show();
    ui->label_2->show();
    ui->lineEdit->show();
    ui->pushButton_4->show();

    ui->label->hide();
    ui->pushButton->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();

}





























