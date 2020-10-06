// CPict.cpp : implementation file
//

#include "stdafx.h"
#include "Controls.h"
#include "CPict.h"


// CPict

IMPLEMENT_DYNAMIC(CPict, CStatic)

CPict::CPict()
{

}

CPict::~CPict()
{
}


BEGIN_MESSAGE_MAP(CPict, CStatic)
	ON_WM_PAINT()
	ON_WM_HSCROLL()
END_MESSAGE_MAP()



// CPict message handlers



extern int ellipseOffset;
void CPict::OnPaint()
{
	CPaintDC dc(this); // device context for painting
					   // TODO: Add your message handler code here
					   // Do not call CStatic::OnPaint() for painting messages
	RECT rt;
	GetWindowRect(&rt);
	OffsetRect(&rt, -rt.left, -rt.top);
	CBrush brushW(RGB(255, 255, 255));
	dc.FillRect(&rt, &brushW);
	RECT ellipseRect = rt;
	ellipseRect.left += ellipseOffset;
	ellipseRect.top += ellipseOffset;
	ellipseRect.right -= ellipseOffset;
	ellipseRect.bottom -= ellipseOffset;
	dc.Ellipse(&ellipseRect);
}
 