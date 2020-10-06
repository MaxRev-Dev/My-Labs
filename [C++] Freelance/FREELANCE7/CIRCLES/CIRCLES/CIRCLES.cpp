// CIRCLES.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#include "math.h"
#include "Circle.h"
#include "RecurParam.h"
#include <stdio.h>
#include "CIRCLES.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

//Custom
RecurParam *pRecur;
LRESULT CALLBACK TestRecurse(HWND, UINT, WPARAM, LPARAM);
void HandleOnOk(HWND hDlg);
void HandleOnInitDialog(HWND hDlg);
void DrawCircles(HDC hdc, int w, int h, int n, double c);



int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.

	// Initialize global strings
	LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadStringW(hInstance, IDC_CIRCLES, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance(hInstance, nCmdShow))
	{
		return FALSE;
	}

	HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_CIRCLES));

	MSG msg;

	// Main message loop:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	if (pRecur != NULL) delete pRecur;
	return (int)msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_CIRCLES));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_CIRCLES);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	hInst = hInstance; // Store instance handle in our global variable

	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	pRecur = new RecurParam;

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		// Parse the menu selections:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		case IDM_TEST_PARAM: { //test param
			if (DialogBox(hInst, (LPCTSTR)IDD_DIALOG_PARAM, hWnd, (DLGPROC)TestRecurse) == IDOK) {
				RECT rc;
				GetClientRect(hWnd, &rc); // full redraw
				InvalidateRect(hWnd, &rc, TRUE);
			}
			break;
		}
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
	}
	break;
	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hWnd, &ps);
		RECT rt; 
		GetClientRect(hWnd, &rt);
		RedrawWindow(hWnd, &rt, NULL, RDW_ERASE);
		GetStockObject(BLACK_PEN);
		DrawCircles(hdc, (rt.right - rt.left) / 2, (rt.bottom - rt.top) / 2,
			pRecur->m_n,
			pRecur->m_c);
		EndPaint(hWnd, &ps);
	}
	break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

LRESULT CALLBACK TestRecurse(HWND hDlg, UINT mess,
	WPARAM wPar, LPARAM lPar)
{
	switch (mess)
	{
	case WM_INITDIALOG: {
		HandleOnInitDialog(hDlg);
		break;
	}
	case WM_COMMAND: {
		if (LOWORD(wPar) == IDCANCEL) {
			EndDialog(hDlg, LOWORD(wPar));
			return TRUE;
		}
		if (LOWORD(wPar) == IDOK) {
			HandleOnOk(hDlg);
			EndDialog(hDlg, LOWORD(wPar));
			return TRUE;
		}
		break;
	}
	default:
		break;
	}
	return FALSE;
}

void HandleOnOk(HWND hDlg)
{
	wchar_t buff[20], *pEnd;
	GetDlgItemText(hDlg, IDC_EDIT_N, buff, 20);
	pRecur->m_n = _wtoi(buff);
	GetDlgItemText(hDlg, IDC_EDIT_F, (LPWSTR)buff, 20);

	pRecur->m_f = _wtof(buff);
	GetDlgItemText(hDlg, IDC_EDIT_C, (LPWSTR)buff, 20);
	pRecur->m_c = _wtof(buff);
	GetDlgItemText(hDlg, IDC_EDIT_NSAT, (LPWSTR)buff, 20);
	pRecur->m_nsat = _wtoi(buff);
}
void HandleOnInitDialog(HWND hDlg)
{
	char buff[20]; wchar_t res[20];
	size_t outSize;
	SetDlgItemInt(hDlg, IDC_EDIT_N, pRecur->m_n, TRUE);
	SetDlgItemInt(hDlg, IDC_EDIT_NSAT, pRecur->m_nsat, TRUE);

	sprintf_s(buff, "%f", pRecur->m_f);
	mbstowcs_s(&outSize, res, buff, strlen(buff) + 1);
	SetDlgItemText(hDlg, IDC_EDIT_F, res);

	sprintf_s(buff, "%f", pRecur->m_c);
	mbstowcs_s(&outSize, res, buff, strlen(buff) + 1);
	SetDlgItemText(hDlg, IDC_EDIT_C, res);
}

void Circles(HDC hdc, double x, double y, double r, int n) {
	int nl = n - 1, i;
	double fr = pRecur->m_f*r;
	if (n-- > 0) {
		Circle cir(x, y, r);
		cir.DrawCircle(hdc);
		for (int i = 0; i < pRecur->m_nsat; i++) {
			Circles(hdc, x + r * pRecur->m_ccos[i],
				y + r * pRecur->m_csin[i], fr, nl);
		}
	}
}
void DrawCircles(HDC hdc, int w, int h, int n, double c) {
	double p = 1., R, theta, r;
	int minWH = (w > h) ? h : w;
	for (int i = 0; i < n; i++)p *= pRecur->m_f;
	theta = 2 * 3.14 / pRecur->m_nsat;
	for (int i = 0; i < pRecur->m_nsat; ++i) {
		pRecur->m_ccos[i] = c * cos(i*theta);
		pRecur->m_csin[i] = c * sin(i*theta);
	}
	R = minWH * (1 - pRecur->m_f) / (1 - p);
	r = R / c;
	Circles(hdc, w, h, r, n);
}