#pragma once


// CPict

class CPict : public CStatic
{
	DECLARE_DYNAMIC(CPict)

public:
	CPict();
	virtual ~CPict();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
 };


