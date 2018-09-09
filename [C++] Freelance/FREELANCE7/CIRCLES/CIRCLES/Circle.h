#pragma once
#ifndef AFX_CIRCLE_H
#define AFX_CIRCLE_H
#endif // !AFX_CIRCLE_H

class Circle
{
public:
	Circle(double x,double y,double r);
	virtual ~Circle();
	void DrawCircle(HDC hDC);
private :
	double m_x, m_y, m_r;
};

