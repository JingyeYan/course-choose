#pragma once
#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include"staff.h"
#include<QFile>
#include<QTextStream>
#include"score.h"


class management {
protected:
	MyVector<staff> m_staff;
	MyVector<student> m_student;
	MyVector<module> m_module;
    MyVector<score> m_score;
public:
    friend class MainWindow;
    QString m_qstr;
	management();
	~management(){}
    void input();
    bool stuadd(const QString&a,const QString&b,const QString&c,const QString&d);
    bool sturemove(const QString&a);                       //ѧ����ɾ
    void stushow();                         //ϵͳ������ѧ����Ϣ��ʾ
    bool teaadd(const QString&a,const QString&b,const QString&c);
    bool tearemove(const QString&a);                       //��ʦ��ɾ
	void teashow();                         //ϵͳ�����н�ʦ��Ϣ��ʾ
    bool modadd(const QString&a,const QString&b,const QString&c,const QString&d,const QString&e);
    bool modremove(const QString&a);                       //�γ���ɾ
	void modshow();                         //ϵͳ�����пγ���Ϣ��ʾ
    int store(int i);                           //�����ĵ�
    void moduleinput();
	
};


#endif
