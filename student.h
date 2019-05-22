#ifndef STUDENT_H
#define STUDENT_H


#include"module.h"
#include"Myvector.h"

class student {
protected:
    QString m_ID, m_name, m_classID, m_major;
    MyVector<module> m_les;      // ��ѡ�γ�
    MyVector<module> m_nles;       //ϵͳ��δѡ�γ�
public:
    friend class stumanagement;
    friend class stamanagement;
    friend class management;
    friend class stuDialog;
	student();
    student(const QString &a,const QString &b, const QString& c,const QString& d);
	~student(){}
    const QString&getID();
    const QString&getname();
    const QString&getclassID();
    const QString&getmajor();
};


#endif // !STUDENT_H
