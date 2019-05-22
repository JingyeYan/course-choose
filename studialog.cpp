#include "studialog.h"
#include "ui_studialog.h"


stuDialog::stuDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stuDialog)
{
    m_S.input();
    m_S.moduleinput();
    ui->setupUi(this);
    ui->label->hide();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->textEdit->hide();
    ui->textEdit_2->hide();
    ui->textEdit_3->hide();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
    ui->lineEdit_2->hide();
    ui->lineEdit_3->hide();
    ui->commandLinkButton->hide();
}

stuDialog::~stuDialog()
{
    delete ui;
}

void stuDialog::on_pushButton_clicked()          //登录确认按钮
{
    m_qstr=ui->lineEdit->text();
    int m(0),n(0);
    for(int i=0;i<m_S.m_student.size();i++){
        if(m_qstr==m_S.m_student[i].getID()){n=i; m++;}
    }
    if(m!=0){
        ui->lineEdit->clear();
        ui->label_2->hide();
        ui->label->show();
        ui->lineEdit->hide();
        ui->pushButton->hide();
        ui->pushButton_2->show();
        ui->pushButton_3->show();
        ui->lineEdit_2->show();
        ui->lineEdit_3->show();
        ui->label_5->show();
        ui->textEdit_3->show();
        ui->commandLinkButton->show();
        ui->label->setText("ID:"+m_S.m_student[n].getID()+'\n'
                           +"Name:"+m_S.m_student[n].getname()+'\n'
                           +"classID:"+m_S.m_student[n].getclassID()+'\n'
                           +"Major:"+m_S.m_student[n].getmajor());
        ui->label_3->show();
        ui->label_4->show();
        ui->textEdit->show();
        ui->textEdit_2->show();


        QString X,t;
        t=t.fromLocal8Bit("课程名称\t课程成绩\t课程类别\t课程学分");
        X=t+'\n';
        for(int i=0;i<m_S.m_score.size();i++){
            if(m_qstr==m_S.m_score[i].getstuID()){
                X+=m_S.m_score[i].getlesname()+'   '+m_S.m_score[i].getscore()+'   ';
                for(int s=0;s<m_S.m_module.size();s++){
                    if(m_S.m_score[i].getlesname()==m_S.m_module[s].getmodname())
                    {
                        X+=m_S.m_module[s].getkind()+'   '+m_S.m_module[s].getcredits()+'\n';
                    }
                }
            }
        }
        ui->textEdit->setText(X);



        QString Z,r;
        r=r.fromLocal8Bit("#课程编号   课程名称  学分   学时   课程类别 ");
        Z=r+'\n';
        for(int z=0;z<m_S.m_student[n].m_les.size();z++){
            Z+=m_S.m_student[n].m_les[z].getmodID()+'\t'+m_S.m_student[n].m_les[z].getmodname()+'\t'
                    +m_S.m_student[n].m_les[z].getcredits()+'\t'+m_S.m_student[n].m_les[z].gettime()+'\t'
                    +m_S.m_student[n].m_les[z].getkind()+'\n';
        }
        ui->textEdit_2->setText(Z);




        QString Y;
        for(int z=0;z<m_S.m_student[n].m_nles.size();z++){
            Y+=m_S.m_student[n].m_nles[z].getmodID()+'\t'+m_S.m_student[n].m_nles[z].getmodname()+'\t'
                    +m_S.m_student[n].m_nles[z].getcredits()+'\t'+m_S.m_student[n].m_nles[z].gettime()+'\t'
                    +m_S.m_student[n].m_nles[z].getkind()+'\n';
        }
        ui->textEdit_3->setText(Y);





    }
    else{
        QString t;
        t=t.fromLocal8Bit("您输入的学生ID不存在！！！");
        ui->lineEdit->setText(t);
    }
}



void stuDialog::on_commandLinkButton_clicked()
{

    ui->label->hide();
    ui->label_2->show();
    ui->label_3->hide();
    ui->label_4->hide();
    ui->label_5->hide();
    ui->lineEdit->show();
    ui->lineEdit_2->hide();
    ui->lineEdit_3->hide();
    ui->textEdit_2->hide();
    ui->textEdit->hide();
    ui->textEdit_3->hide();
    ui->commandLinkButton->hide();
    ui->pushButton->show();
    ui->pushButton_2->hide();
    ui->pushButton_3->hide();
}


void stuDialog::on_pushButton_3_clicked()
{
    QString a;
    a=ui->lineEdit_3->text();
    int n(0),m(0),l(0);
    for(int i=0;i<m_S.m_student.size();i++){
        if(m_qstr==m_S.m_student[i].getID()){n=i;}
    }
    for(int j=0;j<m_S.m_student[n].m_nles.size();j++){
        if(a==m_S.m_student[n].m_nles[j].getmodID()){
           l++;
           m=j;
        }
    }

    if(l!=0){
        m_S.m_student[n].m_les.push_back(m_S.m_student[n].m_nles[m]);
        m_S.m_student[n].m_nles.erase(m);
    QString Y;
    for(int z=0;z<m_S.m_student[n].m_nles.size();z++){
        Y+=m_S.m_student[n].m_nles[z].getmodID()+'\t'+m_S.m_student[n].m_nles[z].getmodname()+'\t'
                +m_S.m_student[n].m_nles[z].getcredits()+'\t'+m_S.m_student[n].m_nles[z].gettime()+'\t'
                +m_S.m_student[n].m_nles[z].getkind()+'\n';
    }
    ui->textEdit_3->setText(Y);
    QString Z,r;
    r=r.fromLocal8Bit("#课程编号   课程名称  学分   学时   课程类别 ");
    Z=r+'\n';
    for(int z=0;z<m_S.m_student[n].m_les.size();z++){
        Z+=m_S.m_student[n].m_les[z].getmodID()+'\t'+m_S.m_student[n].m_les[z].getmodname()+'\t'
                +m_S.m_student[n].m_les[z].getcredits()+'\t'+m_S.m_student[n].m_les[z].gettime()+'\t'
                +m_S.m_student[n].m_les[z].getkind()+'\n';
    }
    ui->textEdit_2->setText(Z);

    ui->lineEdit_3->clear();
    }
    else{
        QString t;
        t=t.fromLocal8Bit("您选择的课程已选或不存在");
        ui->lineEdit_3->setText(t);
    }
}

void stuDialog::on_pushButton_2_clicked()
{
    QString a;
    a=ui->lineEdit_2->text();
    int n(0),m(0),l(0);
    for(int i=0;i<m_S.m_student.size();i++){
        if(m_qstr==m_S.m_student[i].getID()){n=i;}
    }
    for(int j=0;j<m_S.m_student[n].m_les.size();j++){
        if(a==m_S.m_student[n].m_les[j].getmodID()){
           l++;
           m=j;
        }
    }

    if(l!=0){
        m_S.m_student[n].m_nles.push_back(m_S.m_student[n].m_les[m]);
        m_S.m_student[n].m_les.erase(m);
    QString Y;
    for(int z=0;z<m_S.m_student[n].m_nles.size();z++){
        Y+=m_S.m_student[n].m_nles[z].getmodID()+'\t'+m_S.m_student[n].m_nles[z].getmodname()+'\t'
                +m_S.m_student[n].m_nles[z].getcredits()+'\t'+m_S.m_student[n].m_nles[z].gettime()+'\t'
                +m_S.m_student[n].m_nles[z].getkind()+'\n';
    }
    ui->textEdit_3->setText(Y);
    QString Z,r;
    r=r.fromLocal8Bit("#课程编号   课程名称  学分   学时   课程类别 ");
    Z=r+'\n';
    for(int z=0;z<m_S.m_student[n].m_les.size();z++){
        Z+=m_S.m_student[n].m_les[z].getmodID()+'\t'+m_S.m_student[n].m_les[z].getmodname()+'\t'
                +m_S.m_student[n].m_les[z].getcredits()+'\t'+m_S.m_student[n].m_les[z].gettime()+'\t'
                +m_S.m_student[n].m_les[z].getkind()+'\n';
    }
    ui->textEdit_2->setText(Z);

    ui->lineEdit_2->clear();
    }
    else{
        QString t;
        t=t.fromLocal8Bit("您退选的课程已不在您的课表中");
        ui->lineEdit_2->setText(t);
    }


}
