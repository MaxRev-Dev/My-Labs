#include "Recipe.h"
// BookOfRecipesDlg.h : header file
//

#pragma once


// CBookOfRecipesDlg dialog
class CBookOfRecipesDlg : public CDHtmlDialog
{
// Construction
public:
	CBookOfRecipesDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BOOKOFRECIPES_DIALOG, IDH = IDR_HTML_BOOKOFRECIPES_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	 
	HRESULT OnNextRecipe(IHTMLElement *pElement);
	HRESULT OnPrevRecipe(IHTMLElement *pElement);
	HRESULT OnToggleBtn(IHTMLElement *pElement); 
	HRESULT EvalScript(ATL::CComPtr<IHTMLDocument2> doc, wstring content); 
	HRESULT OnRetryBtn(IHTMLElement *); 
	HRESULT SetElemInner(wstring id, wstring innerHtml);
	void SetRecipeWithIndex(int *i); 

// Implementation
protected:
	HICON m_hIcon;
	RecipeFetch container;
	Recipe selectedRecipe;
	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	DECLARE_DHTML_EVENT_MAP()
public:
	afx_msg void OnAbout(); 
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct); 
	void OnDocumentComplete(LPDISPATCH pDisp, LPCTSTR szUrl); 
};
