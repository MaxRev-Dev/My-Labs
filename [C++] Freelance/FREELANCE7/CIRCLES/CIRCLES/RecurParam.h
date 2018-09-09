#pragma once
#ifndef AFX_RECURPARAM_H
#define AFX_RECURPARAM_H
#endif // !AFX_RECURPARAM_H

class RecurParam
{
public:
	RecurParam();
	~RecurParam();
	int m_n, m_nsat;
	double m_f, m_c;
	double m_ccos[100], m_csin[100];
};

