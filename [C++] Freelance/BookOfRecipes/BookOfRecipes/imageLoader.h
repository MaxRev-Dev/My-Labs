#pragma once

#include "stdafx.h"
#include <iostream>
#include <windows.h> 
#include <WinInet.h>  // from SDK
#include "string.h"
#include <TCHAR.H> 
#include "tools.h"
#ifndef UNICODE  
typedef std::string String;
#else
typedef std::wstring String;
#endif
#pragma warning(disable:4996) 
using namespace std;  



inline int convertURLtofname(TCHAR * szURL, TCHAR * szname)
// extract the filename from the URL 
{
	HRESULT result = NULL;
	size_t i, j;
	int fresult;

	fresult = 0;

	size_t nchars = _tcslen(szURL);
	i = nchars - 1;
	while ((i > 0) && (szURL[i] != '/') && (szURL[i] != '\\')) { i--; }
	j = 0; i++;
	while (i < nchars) { szname[j++] = szURL[i++]; }
	szname[j] = _T('\0');

	//  wcstombs ( aszfilename, szname, 100 );
	//     cout << aszfilename << endl;
	//----------------------------------------------
	return fresult;
}

inline int determinepathfilename(TCHAR * szURL, TCHAR * szpath, TCHAR * szname, TCHAR * szpathfilename)
{
	// use path and filename when supplied.  If filename (e.g. funkypic.jpg) is not supplied, then the
	// filename will be extracted from the last part of the URL
	int result;
	result = 0;
	TCHAR szname_copy[100];

	if ((szname == NULL) || (szname[0] == '\0'))
		convertURLtofname(szURL, szname_copy);
	else
		_tcscpy(szname_copy, szname);

	if ((szpath == NULL) || (szpath[0] == '\0'))
		_tcscpy(szpathfilename, szname_copy);
	else
	{
		_tcscpy(szpathfilename, szpath);
		_tcscat(szpathfilename, szname_copy);
	}
	return result;
} 
inline std::wstring s2ws(const std::string& s)
{
	int len;
	int slength = (int)s.length() + 1;
	len = MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, 0, 0);
	wchar_t* buf = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, s.c_str(), slength, buf, len);
	std::wstring r(buf);
	delete[] buf;
	return r;
}
inline wstring GetFile(HINTERNET hOpen, // Handle from InternetOpen()
	TCHAR *szURL,        // Full URL
	TCHAR * szpath,
	TCHAR * szname)
{
	DWORD dwSize;
	TCHAR szHead[15];
	BYTE * szTemp[1024];
	HINTERNET  hConnect;
	FILE * pFile;
	TCHAR  szpathfilename[100];

	szHead[0] = '\0';

	if (!(hConnect = InternetOpenUrl(hOpen, szURL, szHead, 15, INTERNET_FLAG_DONT_CACHE, 0)))
	{
		std::cout << "Error: InternetOpenUrl" << std::endl;
		return L"";
	}

	determinepathfilename(szURL, szpath, szname, szpathfilename);

	if (!(pFile = _tfopen(szpathfilename, _T("wb"))))
	{
		std::cerr << "Error _tfopen" << std::endl;
		return L"";
	}
	do
	{
		// Keep copying in 1024 bytes chunks, while file has any data left.
		// Note: bigger buffer will greatly improve performance.
		if (!InternetReadFile(hConnect, szTemp, 1024, &dwSize))
		{
			fclose(pFile);
			std::cerr << "Error InternetReadFile" << std::endl;
			return FALSE;
		}
		if (!dwSize)
			break;  // Condition of dwSize=0 indicate EOF. Stop.
		else
			fwrite(szTemp, sizeof(BYTE), dwSize, pFile);
	}   // do
	while (TRUE);
	fflush(pFile);
	fclose(pFile);  
	String str = szpathfilename;
	auto ret = s2ws(string(szpathfilename));
	return ret ;
}

inline wstring DownloadURLImage(TCHAR * szURL, TCHAR * szpath, TCHAR * szname)
{
	int result;

	HINTERNET hInternet;

	result = 0;

	hInternet = InternetOpen(_T("imaged"),
		INTERNET_OPEN_TYPE_DIRECT,  //__in  DWORD dwAccessType
		NULL,                       //__in  LPCTSTR lpszProxyName,
		NULL,                       //__in  LPCTSTR lpszProxyBypass,
		NULL                        //_in   DWORD dwFlags
	);

	auto path  = GetFile(hInternet, szURL, szpath, szname);
	InternetCloseHandle(hInternet);
	return path;
}


 