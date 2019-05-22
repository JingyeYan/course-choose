#include "score.h"

score::score(const QString &a, const QString &b, const QString &c, const QString &d):m_lesname(c),m_score(d),m_stuID(a),m_stuname(b)
{
}

const QString & score::getstuID()
{
	return m_stuID;
}

const QString & score::getstuname()
{
	return m_stuname;
}

const QString & score::getlesname()
{
	return m_lesname;
}

const QString & score::getscore()
{
	return m_score;
}


