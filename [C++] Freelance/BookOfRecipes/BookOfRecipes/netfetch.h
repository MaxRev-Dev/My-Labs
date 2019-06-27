#include <windows.h>
#include <string>
#include <stdio.h>

#pragma once
using std::string;

class NetFetch { 

private:
	HINSTANCE hInst;
	WSADATA wsaData;
	void mParseUrl(const char *mUrl, string &serverName, string &filepath, string &filename);
	SOCKET connectToServer(char *szServerName, WORD portNum);
	int getHeaderLength(char *content);
	char *readUrl2(const char *szUrl, long &bytesReturnedOut, char **headerOut);
public:
	string Get(string str);
};