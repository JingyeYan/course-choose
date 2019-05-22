#include "management.h"


using namespace std;



management::management():m_qstr("")
{
}








void management::input(){
       QFile stud("J:\\QTcode\\Choose\\student.txt");
       if(stud.open(QFile::ReadOnly)){

           QStringList list;
           QTextStream in(&stud);
           while(1){
           QString a,b,c,d;
           QString line;
           line=in.readLine();
           line=line.simplified();
           list=line.split(" ");
            if(list[0]=="#END"){
                stud.close();
               break;
           }
            else{
               a=list[0];
               b=list[1];
               c=list[2];
               d=list[3];

            }
            m_student.push_back(student(a,b,c,d));
           }
       }

       QFile sta("J:\\QTcode\\Choose\\staff.txt");
       if(sta.open(QFile::ReadOnly)){

           QStringList list;
           QTextStream in(&sta);
           while(1){
           QString a,b,c;
           QString line;
           line=in.readLine();
           line=line.simplified();
           list=line.split(" ");
            if(list[0]=="#END"){
                sta.close();
               break;
           }
            else{
               a=list[0];
               b=list[1];
               c=list[2];
            }
            m_staff.push_back(staff(a,b,c));
           }
       }

       QFile mod("J:\\QTcode\\Choose\\module.txt");
       if(mod.open(QFile::ReadOnly)){

           QStringList list;
           QTextStream in(&mod);
           while(1){
           QString a,b,c,d,e;
           QString line;
           line=in.readLine();
           line=line.simplified();
           list=line.split(" ");
            if(list[0]=="#END"){
                mod.close();
               break;
           }
            else{
               a=list[0];
               b=list[1];
               c=list[2];
               d=list[3];
               e=list[4];

            }
            m_module.push_back(module(a,b,c,d,e));
           }
       }


           QFile sco("J:\\QTcode\\Choose\\score.txt");
           if(sco.open(QFile::ReadOnly)){

               QStringList list;
               QTextStream in(&sco);
               while(1){
               QString a,b,c,d;
               QString line;
               line=in.readLine();
               line=line.simplified();
               list=line.split(" ");
                if(list[0]=="#END"){
                    sco.close();
                   break;
               }
                else{
                   a=list[0];
                   b=list[1];
                   c=list[2];
                   d=list[3];

                }
                m_score.push_back(score(a,b,c,d));
               }
           }

}



void management::moduleinput(){

    for(int n=0;n<m_student.size();n++){
    for(int x=0;x<m_score.size();x++){
        if(m_student[n].getID()==m_score[x].getstuID()){
            for(int y=0;y<m_module.size();y++){
                if(m_module[y].getmodname()==m_score[x].getlesname()){
                    m_student[n].m_les.push_back(m_module[y]);
                }
            }
        }
    }
    }

    for(int n=0;n<m_student.size();n++){
    for(int j=0;j<m_module.size();j++){
        int p(0);
        for(int k=0;k<m_student[n].m_les.size();k++){
            if(m_module[j].getmodID()==m_student[n].m_les[k].getmodID()){p++;}
        }
        if(p==0){m_student[n].m_nles.push_back(m_module[j]);}
    }
    }


}



bool management::stuadd(const QString&a,const QString&b,const QString&c,const QString&d)
{
    int m(0);
    for(int i=0;i<m_student.size();i++){
        if(a==m_student[i].getID())m++;
    }
    if(m!=0){return 0;}
    else{
    m_student.push_back(student(a, b, c, d));
    return 1;
        }
}

bool management::sturemove(const QString&a)
{
		int b(0), c(0);
		for (int i = 0;i < m_student.size();i++) {
			if (a == m_student[i].getID() || a == m_student[i].getname()) { b += 1;c = i; }
		}
		if (b == 0) {
            return 0;
		}
		else { 
			m_student.erase(c);
            return 1;
		}
}

void management::stushow()
{
    for(int i=0;i<m_student.size();i++){

        m_qstr+=m_student[i].getID();
        m_qstr+=" ";
        m_qstr+=m_student[i].getname();
        m_qstr+=" ";
        m_qstr+=m_student[i].getclassID();
        m_qstr+=" ";
        m_qstr+=m_student[i].getmajor();
        m_qstr+='\n';
}

}

bool management::teaadd(const QString&a,const QString&b,const QString&c)
{
    int m(0);
    for(int i=0;i<m_staff.size();i++){
        if(a==m_staff[i].getstaffID())m++;
    }
    if(m!=0){return 0;}
    else{
    m_staff.push_back(staff(a, b, c));
    return 1;
        }
}

bool management::tearemove(const QString&a)
{
		int b(0), c(0);
		for (int i = 0;i < m_staff.size();i++) {
			if (a == m_staff[i].getstaffID() || a == m_staff[i].getstaffname()) { b += 1;c = i; }
		}
		if (b == 0) {
            return 0;
		}
		else {
			m_staff.erase(c);
            return 1;
		}

}

void management::teashow()
{
    for(int i=0;i<m_staff.size();i++){

        m_qstr+=m_staff[i].getstaffID();
        m_qstr+=" ";
        m_qstr+=m_staff[i].getstaffname();
        m_qstr+=" ";
        m_qstr+=m_staff[i].getteachles();
        m_qstr+='\n';

}
}

bool management::modadd(const QString&a,const QString&b,const QString&c,const QString&d,const QString&e)
{

    int m(0);
    for(int i=0;i<m_module.size();i++){
        if(a==m_module[i].getmodID()) m++;
    }
    if(m!=0){return 0;}
    else{
    m_module.push_back(module(a, b, c, d,e));
    return 1;
        }
}

bool management::modremove(const QString&a)
{
        int b(0), c(0);
		for (int i = 0;i < m_module.size();i++) {
			if (a == m_module[i].getmodID() || a == m_module[i].getmodname()) { b += 1;c = i; }
		}
		if (b == 0) {
                     return 0;
		}
		else {
			m_module.erase(c);
            return 1;
		}
}

void management::modshow()
{
    for(int i=0;i<m_module.size();i++){

        m_qstr+=m_module[i].getmodID();
        m_qstr+=" ";
        m_qstr+=m_module[i].getmodname();
        m_qstr+=" ";
        m_qstr+=m_module[i].getcredits();
        m_qstr+=" ";
        m_qstr+=m_module[i].gettime();
        m_qstr+=" ";
        m_qstr+=m_module[i].getkind();
        m_qstr+='\n';
}

}

int management::store(int i)
{
    if(i==1){
    QFile writefile("J:\\QTcode\\Choose\\studenttext.txt");
    if(!writefile.open(QIODevice::WriteOnly|QIODevice::Text)){
       return -1;
    }
    QTextStream txtOutput(&writefile);
    txtOutput<<m_qstr<<endl;

    writefile.close();
    }
    else if(i==2){
        QFile writefile("J:\\QTcode\\Choose\\stafftext.txt");
        if(!writefile.open(QIODevice::WriteOnly|QIODevice::Text)){
           return -1;
        }
        QTextStream txtOutput(&writefile);
        txtOutput<<m_qstr<<endl;

        writefile.close();
    }
    else{
        QFile writefile("J:\\QTcode\\Choose\\moduletext.txt");
        if(!writefile.open(QIODevice::WriteOnly|QIODevice::Text)){
           return -1;
        }
        QTextStream txtOutput(&writefile);
        txtOutput<<m_qstr<<endl;

        writefile.close();
    }


}
