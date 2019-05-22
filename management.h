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
    bool sturemove(const QString&a);                       //学生增删
    void stushow();                         //系统内所有学生信息显示
    bool teaadd(const QString&a,const QString&b,const QString&c);
    bool tearemove(const QString&a);                       //教师增删
	void teashow();                         //系统内所有教师信息显示
    bool modadd(const QString&a,const QString&b,const QString&c,const QString&d,const QString&e);
    bool modremove(const QString&a);                       //课程增删
	void modshow();                         //系统内所有课程信息显示
    int store(int i);                           //存入文档
    void moduleinput();
	
};


#endif
