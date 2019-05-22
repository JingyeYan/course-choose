#include "module.h"

module::module():m_modID(" "),m_credits(" "),m_kind(" "),m_modname(" "),m_time(" ")
{
}

module::module(const QString & a, const QString & b, const QString & c, const QString & d, const QString & e): m_modID(a), m_modname(b), m_credits(c), m_time(d), m_kind(e)
{
}

const QString & module::getmodID()
{
	return m_modID;
}

const QString & module::getmodname()
{
	return m_modname;
}

const QString & module::getcredits()
{
	return m_credits;
}

const QString & module::gettime()
{
	return m_time;
}

const QString & module::getkind()
{
	return m_kind;
}


