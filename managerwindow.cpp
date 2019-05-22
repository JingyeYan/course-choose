#include "mainwindow.h"
#include "ui_mainwindow.h"



void MainWindow::on_commandLinkButton_clicked()        //三种登录界面的退回按钮
{
    ui->commandLinkButton->hide();
    ui->label->show();
    ui->pushButton->show();
    ui->pushButton_2->show();
    ui->pushButton_3->show();

    ui->label_2->hide();
    ui->label_3->hide();
    ui->lineEdit->hide();
    ui->pushButton_4->hide();
    ui->lineEdit->clear();
}


void MainWindow::on_pushButton_4_clicked()          //管理员入口的ID确认按钮
{
    QString qstr;
    qstr=ui->lineEdit->text();
    if(qstr=="12345"){
        ui->commandLinkButton->hide();
        ui->commandLinkButton_4->show();
        ui->label_2->hide();
        ui->lineEdit->hide();
        ui->pushButton_4->hide();
        ui->pushButton_5->show();
        ui->pushButton_6->show();
        ui->pushButton_7->show();
        ui->pushButton_8->show();
        ui->pushButton_9->show();
        ui->pushButton_10->show();
        ui->pushButton_11->show();
        ui->pushButton_12->show();
        ui->pushButton_13->show();
    }
    else{
        QString t;
        t=t.fromLocal8Bit("管理员ID输入错误！！！");
        ui->lineEdit->setText(t);
    }
}


void MainWindow::on_pushButton_5_clicked()                    //录入学生信息
{
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
    ui->pushButton_8->hide();
    ui->pushButton_9->hide();
    ui->pushButton_10->hide();
    ui->pushButton_11->hide();
    ui->pushButton_12->hide();
    ui->pushButton_13->hide();
    ui->pushButton_15->show();
    ui->commandLinkButton_2->show();
    ui->commandLinkButton_4->hide();
    ui->lineEdit->show();
    QString t;
    t=t.fromLocal8Bit("请输入增加的学生的ID，姓名，班级ID，专业: ");
    ui->lineEdit->setText(t);
}



void MainWindow::on_pushButton_15_clicked()                 //录入学生信息确认
{
    QString qstr;
    qstr=ui->lineEdit->text();
    QStringList list;
    list=qstr.split(" ");
    if(m_A.stuadd(list[1],list[2],list[3],list[4])==0){
        QString y;
        y=y.fromLocal8Bit("该学生ID已存在");
        ui->lineEdit->setText(y);
    }
    else{
        m_A.stushow(); //用于改变m_qstr的值
        m_A.store(1);  //存储
        m_A.m_qstr.clear(); //清除m_qstr的值
    QString t;
    t=t.fromLocal8Bit("添加完成");
    ui->lineEdit->setText(t);
    }

}

void MainWindow::on_pushButton_6_clicked()                //删除学生信息
{
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
    ui->pushButton_8->hide();
    ui->pushButton_9->hide();
    ui->pushButton_10->hide();
    ui->pushButton_11->hide();
    ui->pushButton_12->hide();
    ui->pushButton_13->hide();
    ui->pushButton_16->show();
    ui->commandLinkButton_4->hide();
    ui->commandLinkButton_2->show();
    ui->lineEdit->show();
    QString t;
    t=t.fromLocal8Bit("请输入删除的学生的ID或者姓名: ");
    ui->lineEdit->setText(t);
}

void MainWindow::on_pushButton_16_clicked()                      //删除学生信息确认
{
    QString qstr;
    qstr=ui->lineEdit->text();
    QStringList list;
    list=qstr.split(" ");
    if(m_A.sturemove(list[1])==0){
        QString y;
        y=y.fromLocal8Bit("未找到该学生信息");
        ui->lineEdit->setText(y);
    }
    else{
        m_A.stushow(); //用于改变m_qstr的值
        m_A.store(1);  //存储
        m_A.m_qstr.clear(); //清除m_qstr的值
    QString t;
    t=t.fromLocal8Bit("删除完成");
    ui->lineEdit->setText(t);
    }
}


void MainWindow::on_pushButton_7_clicked()                    //学生信息展示
{
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
    ui->pushButton_8->hide();
    ui->pushButton_9->hide();
    ui->pushButton_10->hide();
    ui->pushButton_11->hide();
    ui->pushButton_12->hide();
    ui->pushButton_13->hide();
    ui->commandLinkButton_4->hide();
    ui->commandLinkButton_2->show();
    ui->textEdit->show();
    m_A.stushow();
    ui->textEdit->setText(m_A.m_qstr);
    m_A.m_qstr.clear();

}

void MainWindow::on_pushButton_8_clicked()                      //录入教师信息
{
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
    ui->pushButton_8->hide();
    ui->pushButton_9->hide();
    ui->pushButton_10->hide();
    ui->pushButton_11->hide();
    ui->pushButton_12->hide();
    ui->pushButton_13->hide();
    ui->pushButton_17->show();
    ui->commandLinkButton_4->hide();
    ui->commandLinkButton_2->show();
    ui->lineEdit->show();
    QString t;
    t=t.fromLocal8Bit("请输入增加的老师的ID，姓名，所教授的课程（若多于一门则用/隔开）: ");
    ui->lineEdit->setText(t);
}

void MainWindow::on_pushButton_17_clicked()                    //录入教师信息确认
{
    QString qstr;
    qstr=ui->lineEdit->text();
    QStringList list;
    list=qstr.split(" ");
    if(m_A.teaadd(list[1],list[2],list[3])==0){
        QString y;
        y=y.fromLocal8Bit("该教师ID已存在");
        ui->lineEdit->setText(y);
    }
    else{
        m_A.stushow(); //用于改变m_qstr的值
        m_A.store(1);  //存储
        m_A.m_qstr.clear(); //清除m_qstr的值
    QString t;
    t=t.fromLocal8Bit("添加完成");
    ui->lineEdit->setText(t);
    }
}

void MainWindow::on_pushButton_9_clicked()                     //删除教师信息
{
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
    ui->pushButton_8->hide();
    ui->pushButton_9->hide();
    ui->pushButton_10->hide();
    ui->pushButton_11->hide();
    ui->pushButton_12->hide();
    ui->pushButton_13->hide();
    ui->pushButton_18->show();
    ui->commandLinkButton_4->hide();
    ui->commandLinkButton_2->show();
    ui->lineEdit->show();
    QString t;
    t=t.fromLocal8Bit("请输入删除的老师的ID或者姓名: ");
    ui->lineEdit->setText(t);
}


void MainWindow::on_pushButton_18_clicked()                 //删除教师信息确认
{
    QString qstr;
    qstr=ui->lineEdit->text();
    QStringList list;
    list=qstr.split(" ");
    if(m_A.tearemove(list[1])==0){
        QString y;
        y=y.fromLocal8Bit("未找到该老师信息");
        ui->lineEdit->setText(y);
    }
    else{
        m_A.teashow(); //用于改变m_qstr的值
        m_A.store(2);  //存储
        m_A.m_qstr.clear(); //清除m_qstr的值
    QString t;
    t=t.fromLocal8Bit("删除完成");
    ui->lineEdit->setText(t);
    }
}

void MainWindow::on_pushButton_10_clicked()           //教师信息显示
{
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
    ui->pushButton_8->hide();
    ui->pushButton_9->hide();
    ui->pushButton_10->hide();
    ui->pushButton_11->hide();
    ui->pushButton_12->hide();
    ui->pushButton_13->hide();
    ui->commandLinkButton_4->hide();
    ui->commandLinkButton_2->show();
    ui->textEdit->show();
    m_A.teashow();
    ui->textEdit->setText(m_A.m_qstr);
    m_A.m_qstr.clear();
}

void MainWindow::on_pushButton_11_clicked()            //录入课程信息
{
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
    ui->pushButton_8->hide();
    ui->pushButton_9->hide();
    ui->pushButton_10->hide();
    ui->pushButton_11->hide();
    ui->pushButton_12->hide();
    ui->pushButton_13->hide();
    ui->pushButton_19->show();
    ui->commandLinkButton_4->hide();
    ui->commandLinkButton_2->show();
    ui->lineEdit->show();
    QString t;
    t=t.fromLocal8Bit("请输入增加的课程的ID，名称，学分，学时，类别: ");
    ui->lineEdit->setText(t);
}
void MainWindow::on_pushButton_19_clicked()                        //录入课程信息确认
{
    QString qstr;
    qstr=ui->lineEdit->text();
    QStringList list;
    list=qstr.split(" ");
    if(m_A.modadd(list[1],list[2],list[3],list[4],list[5])==0){
        QString y;
        y=y.fromLocal8Bit("该课程ID已存在");
        ui->lineEdit->setText(y);
    }
    else{
        m_A.stushow(); //用于改变m_qstr的值
        m_A.store(1);  //存储
        m_A.m_qstr.clear(); //清除m_qstr的值
    QString t;
    t=t.fromLocal8Bit("添加完成");
    ui->lineEdit->setText(t);
    }
}

void MainWindow::on_pushButton_12_clicked()                     //删除课程信息
{
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
    ui->pushButton_8->hide();
    ui->pushButton_9->hide();
    ui->pushButton_10->hide();
    ui->pushButton_11->hide();
    ui->pushButton_12->hide();
    ui->pushButton_13->hide();
    ui->pushButton_20->show();
    ui->commandLinkButton_4->hide();
    ui->commandLinkButton_2->show();
    ui->lineEdit->show();
    QString t;
    t=t.fromLocal8Bit("请输入删除的课程的ID或者名称: ");
    ui->lineEdit->setText(t);
}
void MainWindow::on_pushButton_20_clicked()                       //删除课程信息确认
{
    QString qstr;
    qstr=ui->lineEdit->text();
    QStringList list;
    list=qstr.split(" ");
    if(m_A.modremove(list[1])==0){
        QString y;
        y=y.fromLocal8Bit("未找到该课程信息");
        ui->lineEdit->setText(y);
    }
    else{
        m_A.modshow(); //用于改变m_qstr的值
        m_A.store(3);  //存储
        m_A.m_qstr.clear(); //清除m_qstr的值
    QString t;
    t=t.fromLocal8Bit("删除完成");
    ui->lineEdit->setText(t);
    }
}

void MainWindow::on_pushButton_13_clicked()                   //课程信息展示
{
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
    ui->pushButton_8->hide();
    ui->pushButton_9->hide();
    ui->pushButton_10->hide();
    ui->pushButton_11->hide();
    ui->pushButton_12->hide();
    ui->pushButton_13->hide();
    ui->commandLinkButton_4->hide();
    ui->commandLinkButton_2->show();
    ui->textEdit->show();
    m_A.modshow();
    ui->textEdit->setText(m_A.m_qstr);
    m_A.m_qstr.clear();
}


void MainWindow::on_commandLinkButton_4_clicked()        //选择功能界面下的退回按钮
{
    ui->label_2->show();
    ui->lineEdit->show();
    ui->pushButton_4->show();
    ui->commandLinkButton->show();


    ui->commandLinkButton_4->hide();
    ui->pushButton_5->hide();
    ui->pushButton_6->hide();
    ui->pushButton_7->hide();
    ui->pushButton_8->hide();
    ui->pushButton_9->hide();
    ui->pushButton_10->hide();
    ui->pushButton_11->hide();
    ui->pushButton_12->hide();
    ui->pushButton_13->hide();


}



void MainWindow::on_commandLinkButton_2_clicked()           //管理功能下的退回按钮
{
    ui->pushButton_5->show();
    ui->pushButton_6->show();
    ui->pushButton_7->show();
    ui->pushButton_8->show();
    ui->pushButton_9->show();
    ui->pushButton_10->show();
    ui->pushButton_11->show();
    ui->pushButton_12->show();
    ui->pushButton_13->show();
    ui->pushButton_15->hide();
    ui->pushButton_16->hide();
    ui->pushButton_17->hide();
    ui->pushButton_18->hide();
    ui->pushButton_19->hide();
    ui->pushButton_20->hide();
    ui->textEdit->hide();

    ui->commandLinkButton_2->hide();
    ui->lineEdit->hide();
}
