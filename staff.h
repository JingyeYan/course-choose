
#ifndef STAFF_H
#define STAFF_H

#include"student.h"

using namespace std;

class staff{
protected:
    QString m_staffID, m_staffname, m_teachles;
    MyVector<student> m_stu;
public:
    friend class stamanagement;
    friend class staDialog;
	staff();
    staff(const QString&a, const QString&b, const QString&c);
	~staff() {}
    const QString&getstaffID();
    const QString&getstaffname();
    const QString&getteachles();

};



#endif // !STAFF_H
