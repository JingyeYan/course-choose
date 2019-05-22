#ifndef MODULE_H
#define MODULE_H

#include<string>
#include<iostream>
#include<QString>

using namespace std;

class module {
protected:
    QString  m_modID, m_modname, m_credits, m_time, m_kind;
public:
	module();
    module(const QString&a, const QString&b, const QString&c, const QString&d, const QString&e);
	~module() {}
    const QString&getmodID();
    const QString&getmodname();
    const QString&getcredits();
    const QString&gettime();
    const QString&getkind();


};

#endif // !MODULE_H
