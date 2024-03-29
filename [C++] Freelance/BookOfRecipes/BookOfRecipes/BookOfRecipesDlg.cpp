
// BookOfRecipesDlg.cpp : implementation file
//

#include "stdafx.h"
#include "BookOfRecipes.h"
#include "BookOfRecipesDlg.h"
#include "afxdialogex.h"
#include "Recipe.h"
#include "tools.h"
#include <ExDisp.h>
#include <mshtml.h>
#include <dispex.h>
#include <atlbase.h>
#include <atlcomcli.h>
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//hresult wrap
#define _S(a) \
    { HRESULT hr = (a); if (FAILED(hr)) return hr; } 


// cast dispatch driver to interface type
#define disp_cast(disp) \
    ((CComDispatchDriver&)(void(static_cast<IDispatch*>(disp)), reinterpret_cast<CComDispatchDriver&>(disp)))

struct ComInit {
	ComInit() { ::CoInitialize(NULL); }
	~ComInit() { CoUninitialize(); }
};

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CBookOfRecipesDlg dialog

BEGIN_DHTML_EVENT_MAP(CBookOfRecipesDlg)
	DHTML_EVENT_ONCLICK(_T("NextRecipe"), OnNextRecipe)
	DHTML_EVENT_ONCLICK(_T("PrevRecipe"), OnPrevRecipe)
	DHTML_EVENT_ONCLICK(_T("ToggleBtn"), OnToggleBtn)
	DHTML_EVENT_ONCLICK(_T("RetryBtn"), OnRetryBtn)

END_DHTML_EVENT_MAP()


CBookOfRecipesDlg::CBookOfRecipesDlg(CWnd* pParent /*=nullptr*/)
	: CDHtmlDialog(IDD_BOOKOFRECIPES_DIALOG, IDR_HTML_BOOKOFRECIPES_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CBookOfRecipesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDHtmlDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CBookOfRecipesDlg, CDHtmlDialog)
	ON_WM_SYSCOMMAND()
	ON_COMMAND(ID_ABOUT, &CBookOfRecipesDlg::OnAbout)
	ON_WM_ACTIVATEAPP()
	ON_WM_CREATE() 
END_MESSAGE_MAP()


// CBookOfRecipesDlg message handlers

bool ListInitialized = false;
bool RecipeShown = false;
int *imageIndex = new int{ -1 }; //for ref in methods
bool handledIndex = false;

inline wstring GetShowBtn(wstring text) {
	return  L" <button STYLE=\"WIDTH:100\" ID=\"ToggleBtn\" type=\"button\" class=\"btn btn-info\">" + text + L"</button>";
}

BOOL CBookOfRecipesDlg::OnInitDialog()
{
	SetHostFlags(DOCHOSTUIFLAG_FLAT_SCROLLBAR);
	CDHtmlDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CBookOfRecipesDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDHtmlDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.
void CBookOfRecipesDlg::OnPaint()
{

	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDHtmlDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CBookOfRecipesDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

HRESULT CBookOfRecipesDlg::OnNextRecipe(IHTMLElement* /*pElement*/)
{
	RecipeShown = handledIndex = false;
	(*imageIndex)++; //change index;
	SetRecipeWithIndex(imageIndex);

	return S_OK;
}
HRESULT CBookOfRecipesDlg::OnPrevRecipe(IHTMLElement* /*pElement*/)
{
	RecipeShown = handledIndex = false;
	(*imageIndex)--; //change index;
	SetRecipeWithIndex(imageIndex);
	return S_OK;
}

inline void CBookOfRecipesDlg::SetRecipeWithIndex(int *i) {
	auto list = container.GetList();
	if (list.size() > 0) {

		EvalScript(m_spHtmlDoc, L"try{player.destroy()}catch(e){}"); //destroy player

		selectedRecipe = list[
			*i <= -1 ? *i = (int)list.size() - 1 : //loop list
				*i >= (int)list.size() - 1 ? *i = 0 : *i];

		//update ui state
		SetElemInner(L"ImgHolder", L"<img class=\"card-img-top\" src='" + selectedRecipe.ImageUrl + L"'/>");
		SetElemInner(L"headerText", L"<h2>" + selectedRecipe.Title + L"<h2/>");
		SetElemInner(L"headerDesc", L"<p>" + selectedRecipe.ContentIntro + L"<p/>");
		SetElemInner(L"ToggleBtnContainer", GetShowBtn(L"Show more"));
		SetElemInner(L"ContentContainer", L"");
	}
}

//evaluate script in document
HRESULT CBookOfRecipesDlg::EvalScript(ATL::CComPtr<IHTMLDocument2> doc, wstring content) {

	CComPtr<IHTMLWindow2> htmlWindow;
	_S(doc->get_parentWindow(&htmlWindow));
	CComPtr<IDispatchEx> dispatchWindow;
	_S(htmlWindow->QueryInterface(&dispatchWindow));

	CComBSTR __execScriptCode(content.c_str());

	DISPID dispid = -1;
	_S(dispatchWindow->GetDispID(CComBSTR("eval"), fdexNameCaseSensitive, &dispid));
	_S(disp_cast(dispatchWindow).Invoke1(dispid, &CComVariant(__execScriptCode)));
	return S_OK;
}

HRESULT CBookOfRecipesDlg::OnToggleBtn(IHTMLElement* pElement) {
	if (!RecipeShown) {
		if (selectedRecipe.Content == L"")
			container.GetRecipeFull(selectedRecipe);
		auto content = tools::str::trim(selectedRecipe.Content) == L"" ? L"Sorry, this recipe is empty!" : selectedRecipe.Content;
		if (tools::str::WstrToUtf8Str(content).find("new YT.Player") == wstring::npos) {
			//not a script
			SetElemInner(L"ContentContainer", content);
		}
		else {
			SetElemInner(L"PlayerWrap", L"<div id=\"ytplayer\" class=\"w-100 text-center justify-content-center\"></div>");
			EvalScript(m_spHtmlDoc, content);
		}
		SetElemInner(L"ToggleBtnContainer", GetShowBtn(L"Hide"));
		RecipeShown = true;
	}
	else {
		SetElemInner(L"ToggleBtnContainer", GetShowBtn(L"Show more"));
		EvalScript(m_spHtmlDoc, L"try{player.destroy()}catch(e){}"); //destroy player, cause it global
		SetElemInner(L"ContentContainer", L"");
		RecipeShown = false;
	}
	return S_OK;
}
HRESULT CBookOfRecipesDlg::OnRetryBtn(IHTMLElement* /*pElement*/) {

	if (!container.GetList().size()) {
		container = RecipeFetch::RecipeFetch();
		container.FetchRoot();
	}
	//check again and try to set up item
	if (container.GetList().size()) {
		ListInitialized = true;
		SetRecipeWithIndex(imageIndex);
	}
	return S_OK;
}
HRESULT CBookOfRecipesDlg::SetElemInner(wstring id, wstring innerHtml) {

	IHTMLElement* pLinkElement = NULL;
	_bstr_t b = innerHtml.c_str();
	auto wsx = tools::str::WstrToUtf8Str(id);
	auto sx = wsx.c_str();
	if (GetElement(sx, &pLinkElement) == S_OK &&
		pLinkElement != NULL)
	{
		pLinkElement->put_innerHTML(b);

		pLinkElement->Release();
		return S_OK;
	}
	return S_FALSE;
}

void CBookOfRecipesDlg::OnAbout()
{
	CAboutDlg dlgAbout;
	dlgAbout.DoModal();
}


int CBookOfRecipesDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDHtmlDialog::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!ListInitialized) {
		container = RecipeFetch::RecipeFetch();
		container.FetchRoot();
	}
	return 0;
}

void CBookOfRecipesDlg::OnDocumentComplete(
	LPDISPATCH pDisp,
	LPCTSTR szUrl
) {

	if (!ListInitialized) {
		if (!container.GetList().size()) //vector is empty cause we are offline
		{
			SetElemInner(L"headerDesc", L"No internet connection detected");
			SetElemInner(L"ToggleBtnContainer", L" <BUTTON STYLE=\"WIDTH:100\" ID=\"RetryBtn\">Try Again!</BUTTON>");
		}
		else {
			auto playerInit =
				L" var tag = document.createElement('script');"\
				" tag.src = \"https://www.youtube.com/player_api\";"\
				" var firstScriptTag = document.getElementsByTagName('script')[0];"\
				" firstScriptTag.parentNode.insertBefore(tag, firstScriptTag);";
			EvalScript(m_spHtmlDoc, playerInit);

			ListInitialized = true;
			SetRecipeWithIndex(imageIndex);
		}
	}
}
