#include "staff.h"


staff::staff():m_staffID(" "),m_staffname(" "),m_teachles(" "){}

staff::staff(const QString & a, const QString & b, const QString & c):m_staffID(a),m_staffname(b),m_teachles(c)
{
}

const QString & staff::getstaffID()
{
	return m_staffID;
}

const QString & staff::getstaffname()
{
	return m_staffname;
}

const QString & staff::getteachles()
{
	return m_teachles;
}


