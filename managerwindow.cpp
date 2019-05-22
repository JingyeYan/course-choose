#include "mainwindow.h"
#include "ui_mainwindow.h"



void MainWindow::on_commandLinkButton_clicked()        //���ֵ�¼������˻ذ�ť
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


void MainWindow::on_pushButton_4_clicked()          //����Ա��ڵ�IDȷ�ϰ�ť
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
        t=t.fromLocal8Bit("����ԱID������󣡣���");
        ui->lineEdit->setText(t);
    }
}


void MainWindow::on_pushButton_5_clicked()                    //¼��ѧ����Ϣ
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
    t=t.fromLocal8Bit("���������ӵ�ѧ����ID���������༶ID��רҵ: ");
    ui->lineEdit->setText(t);
}



void MainWindow::on_pushButton_15_clicked()                 //¼��ѧ����Ϣȷ��
{
    QString qstr;
    qstr=ui->lineEdit->text();
    QStringList list;
    list=qstr.split(" ");
    if(m_A.stuadd(list[1],list[2],list[3],list[4])==0){
        QString y;
        y=y.fromLocal8Bit("��ѧ��ID�Ѵ���");
        ui->lineEdit->setText(y);
    }
    else{
        m_A.stushow(); //���ڸı�m_qstr��ֵ
        m_A.store(1);  //�洢
        m_A.m_qstr.clear(); //���m_qstr��ֵ
    QString t;
    t=t.fromLocal8Bit("������");
    ui->lineEdit->setText(t);
    }

}

void MainWindow::on_pushButton_6_clicked()                //ɾ��ѧ����Ϣ
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
    t=t.fromLocal8Bit("������ɾ����ѧ����ID��������: ");
    ui->lineEdit->setText(t);
}

void MainWindow::on_pushButton_16_clicked()                      //ɾ��ѧ����Ϣȷ��
{
    QString qstr;
    qstr=ui->lineEdit->text();
    QStringList list;
    list=qstr.split(" ");
    if(m_A.sturemove(list[1])==0){
        QString y;
        y=y.fromLocal8Bit("δ�ҵ���ѧ����Ϣ");
        ui->lineEdit->setText(y);
    }
    else{
        m_A.stushow(); //���ڸı�m_qstr��ֵ
        m_A.store(1);  //�洢
        m_A.m_qstr.clear(); //���m_qstr��ֵ
    QString t;
    t=t.fromLocal8Bit("ɾ�����");
    ui->lineEdit->setText(t);
    }
}


void MainWindow::on_pushButton_7_clicked()                    //ѧ����Ϣչʾ
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

void MainWindow::on_pushButton_8_clicked()                      //¼���ʦ��Ϣ
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
    t=t.fromLocal8Bit("���������ӵ���ʦ��ID�������������ڵĿγ̣�������һ������/������: ");
    ui->lineEdit->setText(t);
}

void MainWindow::on_pushButton_17_clicked()                    //¼���ʦ��Ϣȷ��
{
    QString qstr;
    qstr=ui->lineEdit->text();
    QStringList list;
    list=qstr.split(" ");
    if(m_A.teaadd(list[1],list[2],list[3])==0){
        QString y;
        y=y.fromLocal8Bit("�ý�ʦID�Ѵ���");
        ui->lineEdit->setText(y);
    }
    else{
        m_A.stushow(); //���ڸı�m_qstr��ֵ
        m_A.store(1);  //�洢
        m_A.m_qstr.clear(); //���m_qstr��ֵ
    QString t;
    t=t.fromLocal8Bit("������");
    ui->lineEdit->setText(t);
    }
}

void MainWindow::on_pushButton_9_clicked()                     //ɾ����ʦ��Ϣ
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
    t=t.fromLocal8Bit("������ɾ������ʦ��ID��������: ");
    ui->lineEdit->setText(t);
}


void MainWindow::on_pushButton_18_clicked()                 //ɾ����ʦ��Ϣȷ��
{
    QString qstr;
    qstr=ui->lineEdit->text();
    QStringList list;
    list=qstr.split(" ");
    if(m_A.tearemove(list[1])==0){
        QString y;
        y=y.fromLocal8Bit("δ�ҵ�����ʦ��Ϣ");
        ui->lineEdit->setText(y);
    }
    else{
        m_A.teashow(); //���ڸı�m_qstr��ֵ
        m_A.store(2);  //�洢
        m_A.m_qstr.clear(); //���m_qstr��ֵ
    QString t;
    t=t.fromLocal8Bit("ɾ�����");
    ui->lineEdit->setText(t);
    }
}

void MainWindow::on_pushButton_10_clicked()           //��ʦ��Ϣ��ʾ
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

void MainWindow::on_pushButton_11_clicked()            //¼��γ���Ϣ
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
    t=t.fromLocal8Bit("���������ӵĿγ̵�ID�����ƣ�ѧ�֣�ѧʱ�����: ");
    ui->lineEdit->setText(t);
}
void MainWindow::on_pushButton_19_clicked()                        //¼��γ���Ϣȷ��
{
    QString qstr;
    qstr=ui->lineEdit->text();
    QStringList list;
    list=qstr.split(" ");
    if(m_A.modadd(list[1],list[2],list[3],list[4],list[5])==0){
        QString y;
        y=y.fromLocal8Bit("�ÿγ�ID�Ѵ���");
        ui->lineEdit->setText(y);
    }
    else{
        m_A.stushow(); //���ڸı�m_qstr��ֵ
        m_A.store(1);  //�洢
        m_A.m_qstr.clear(); //���m_qstr��ֵ
    QString t;
    t=t.fromLocal8Bit("������");
    ui->lineEdit->setText(t);
    }
}

void MainWindow::on_pushButton_12_clicked()                     //ɾ���γ���Ϣ
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
    t=t.fromLocal8Bit("������ɾ���Ŀγ̵�ID��������: ");
    ui->lineEdit->setText(t);
}
void MainWindow::on_pushButton_20_clicked()                       //ɾ���γ���Ϣȷ��
{
    QString qstr;
    qstr=ui->lineEdit->text();
    QStringList list;
    list=qstr.split(" ");
    if(m_A.modremove(list[1])==0){
        QString y;
        y=y.fromLocal8Bit("δ�ҵ��ÿγ���Ϣ");
        ui->lineEdit->setText(y);
    }
    else{
        m_A.modshow(); //���ڸı�m_qstr��ֵ
        m_A.store(3);  //�洢
        m_A.m_qstr.clear(); //���m_qstr��ֵ
    QString t;
    t=t.fromLocal8Bit("ɾ�����");
    ui->lineEdit->setText(t);
    }
}

void MainWindow::on_pushButton_13_clicked()                   //�γ���Ϣչʾ
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


void MainWindow::on_commandLinkButton_4_clicked()        //ѡ���ܽ����µ��˻ذ�ť
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



void MainWindow::on_commandLinkButton_2_clicked()           //�������µ��˻ذ�ť
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
