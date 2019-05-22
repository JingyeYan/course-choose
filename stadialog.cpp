#include "stadialog.h"
#include "ui_stadialog.h"

staDialog::staDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::staDialog)
{
    ui->setupUi(this);
    m_T.input();
    m_T.moduleinput();
    m_T.stuinput();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->label_6->hide();
    ui->textEdit->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->lineEdit_2->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();
    ui->lineEdit_5->hide();
    ui->commandLinkButton->hide();
}

staDialog::~staDialog()
{
    delete ui;
}

void staDialog::on_pushButton_clicked()
{
    m_tqstr=ui->lineEdit->text();
    int m(0),n(0);
    for(int i=0;i<m_T.m_staff.size();i++){
        if(m_tqstr==m_T.m_staff[i].getstaffID()){n=i; m++;}
    }
    if(m!=0){
        ui->lineEdit->clear();
        ui->label->hide();
        ui->label_2->show();
        ui->label_3->show();
        ui->label_4->show();
        ui->label_5->show();
        ui->label_6->show();
        ui->lineEdit->hide();
        ui->lineEdit_2->show();
        ui->lineEdit_3->show();
        ui->lineEdit_4->show();
        ui->lineEdit_5->show();
        ui->pushButton->hide();
        ui->pushButton_2->show();
        ui->pushButton_3->show();
        ui->textEdit->show();
        ui->commandLinkButton->show();

        QString X,t;
        t=t.fromLocal8Bit("课程名称\t学生ID\t学生名字\t课程成绩");
        X=t+'\n';
        QStringList list;
        for(int x=0;x<m_T.m_staff[n].m_stu.size();x++){
            for(int y=0;y<m_T.m_score.size();y++){
            if(m_T.m_staff[n].m_stu[x].getID()==m_T.m_score[y].getstuID()){
                list=m_T.m_staff[n].getteachles().split("/");
                for(int z=0;z<list.size();z++){
                    if(m_T.m_score[y].getlesname()==list[z]){
                        X+=m_T.m_score[y].getlesname()+'\t'+m_T.m_score[y].getstuID()+'\t'
                                +m_T.m_score[y].getstuname()+'\t'+m_T.m_score[y].getscore()+'\n';
                    }
                }
            }
            }
        }
        ui->textEdit->setText(X);



    }
    else{
        QString t;
        t=t.fromLocal8Bit("您输入的教师ID不存在！！！");
        ui->lineEdit->setText(t);
    }

}

void staDialog::on_pushButton_2_clicked()
{
    int n(0);
    for(int i=0;i<m_T.m_staff.size();i++){
        if(m_tqstr==m_T.m_staff[i].getstaffID()){n=i;}
    }
    QString s,Y,t;
    s=ui->lineEdit_2->text();
    for(int d=0;d<m_T.m_score.size();d++){
            if(m_T.m_score[d].getlesname()==s){
                Y+=m_T.m_score[d].getlesname()+'\t'+m_T.m_score[d].getstuID()+'\t'
                        +m_T.m_score[d].getstuname()+'\t'+m_T.m_score[d].getscore()+'\n';
            }
        }


    t=t.fromLocal8Bit("课程名称\t学生ID\t学生名字\t课程成绩");
    Y=t+'\n';
    ui->textEdit->setText(Y);
}

void staDialog::on_commandLinkButton_clicked()
{
    ui->commandLinkButton->hide();
    ui->label->show();
    ui->label_2->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->label_6->hide();
    ui->textEdit->hide();
    ui->pushButton->show();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->lineEdit_2->hide();
    ui->lineEdit_3->hide();
    ui->lineEdit_4->hide();
    ui->lineEdit_5->hide();
    ui->lineEdit->show();
    ui->commandLinkButton->hide();


}
