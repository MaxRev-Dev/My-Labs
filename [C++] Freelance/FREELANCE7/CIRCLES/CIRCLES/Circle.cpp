#include "stdafx.h"
#include "Circle.h"
#include <math.h>

Circle::Circle(double x, double y, double r)
{
	m_x = x; m_y = y; m_r = r;
}

Circle::~Circle()
{
}

void Circle::DrawCircle(HDC hDC)
{
	int n = (int)(30 * m_r + 8);
	POINT point;
	double theta = (double)(2 * 3.14 / n);
	MoveToEx(hDC, (int)(m_x + m_r), (int)m_y, &point);
	for (int i = 1; i <= n; i++)
		LineTo(hDC, (int)(m_x + m_r * cos(i*theta)),
		(int)(m_y + m_r * sin(i*theta)));

}
