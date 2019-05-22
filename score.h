#ifndef SCORE_H
#define SOCRE_H

#include<string>
#include<iostream>
#include<QString>

using namespace std;

class score {
protected:
    QString m_stuID, m_stuname, m_lesname, m_score;
public:
    score(){}
    score(const QString&a,const QString&b,const QString&c,const QString&d);
	~score(){}
    const QString&getstuID();
    const QString&getstuname();
    const QString&getlesname();
    const QString&getscore();
};

#endif // !SCORE_H
