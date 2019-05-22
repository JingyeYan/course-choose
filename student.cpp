#include "student.h"

student::student():m_classID(" "),m_ID(" "),m_major(" "),m_name(" "){}

student::student(const QString & a, const QString & b, const QString & c, const QString & d):m_ID(a),m_name(b),m_classID(c),m_major(d)
{
}

const QString & student::getID()
{
	return m_ID;
}

const QString & student::getname()
{
    return m_name;
}

const QString & student::getclassID()
{
    return m_classID;
}

const QString & student::getmajor()
{
    return m_major;
}


