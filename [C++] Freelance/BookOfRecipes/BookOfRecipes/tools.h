#ifndef TOOLS
#define TOOLS

#pragma once
#include <windows.h>
#include <stdio.h>
#include <vector>
#include <string>
#include <sstream>
#include <locale> 
#include <codecvt>
#include <iterator> 
#include <regex> 
#include "imageLoader.h" 
#include "tools.h"
using namespace std;

namespace tools {
	// basic string converions between wstring <=> string 
	// trim-join methods
	namespace str {
		inline TCHAR* ToTCHAR(string str) {
			TCHAR *param = new TCHAR[str.size() + 1];
			param[str.size()] = 0;
			//As much as we'd love to, we can't use memcpy() because
			//sizeof(TCHAR)==sizeof(char) may not be true:
			std::copy(str.begin(), str.end(), param);
			return param;
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
		inline std::wstring join(vector<wstring> vec, string sep)
		{
			std::wostringstream oss;
			std::vector<std::wstring> cont;

			// Convert all but the last element to avoid a trailing "," 
			std::copy(vec.begin(), vec.end() - 1,
				std::ostream_iterator<wstring, wchar_t>(oss, L"\n"));

			// Now add the last element with no delimiter
			oss << vec.back().c_str();
			return oss.str();
		}
		inline std::wstring trim(wstring str) {
			wstringstream wstr;
			size_t i = 0;
			while (str[i] == ' ') i++;
			while (i < str.length())
			{
				if (str[i] != '\n'
					&& str[i] != '\t'
					&& str[i] != '\r')
					wstr << str[i];
				i++;
			}
			while (wstr.get() == 32);
			return wstr.str();
		}
		inline std::string WstrToUtf8Str(const std::wstring& wstr)
		{
			std::string retStr;
			if (!wstr.empty())
			{
				int sizeRequired = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, NULL, 0, NULL, NULL);

				if (sizeRequired > 0)
				{
					std::vector<char> utf8String(sizeRequired);
					int bytesConverted = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(),
						-1, &utf8String[0], (int)utf8String.size(), NULL,
						NULL);
					if (bytesConverted != 0)
					{
						retStr = &utf8String[0];
					}
					else
					{
						std::stringstream err;
						err << __FUNCTION__
							<< " std::string WstrToUtf8Str failed to convert wstring '"
							<< wstr.c_str() << L"'";
						throw std::runtime_error(err.str());
					}
				}
			}
			return retStr;
		}
	}

	inline void CreateFolder(string path)
	{
		auto wwpath = path.c_str();
		LPCSTR wpath = path.c_str(); //tools::str::s2ws( wwpath).c_str();
		if (!CreateDirectory(wpath, NULL))
		{
			return;
		}
	}

	namespace extractors {
		//basic html parser. IT NOT INCLUDES HTML PARSING EXCEPTIONS
		inline wstring extract(wstring html, wstring matchingTag, int *offset = new int{ 0 })
		{
			if ((UINT)offset[0] >= html.length())return L"";
			html = html.substr(offset[0]);
			auto prep = html.find(matchingTag);
			if (prep != string::npos) {
				auto start = html.substr(prep);
				int ib = 0, ob = 0, i = 0, in = 0, out = 0;
				bool comment = false;

				while (true)
				{
					if (start.length() == i - 1)
						break;
					auto vv = start.substr(i);
					auto g = start[i];
					if (g == '\n' || g == '\t' || g == '\r' || g == ' ')
					{
						i++; continue;
					}
					if (g == '<') {
						if (start[i + 1] == '!'&&start[i + 2] == '-') {
							while (true) {
								i++;
								if (start[i] == '>')
									if (start[i - 1] == '-'&&start[i - 2] == '-')
										break;
							}
							continue;
						}
						ib++;
						if (start[i + 1] == '/') {
							while (start[i] != '>') i++;
							out++; ib--;
							continue;
						}
						while (start[i] != '>') i++;
						ob++;
						if (ib == ob) in++;
						if (start[i - 1] == '/') {
							i++;
							if (in == 1 && out == 0) { break; }
							ib--; ob--; in--;
							continue;
						}
					}
					i++;
					if (in == out || (out == in - 1 && out > 1) || (out + 1 == in) && out == -1)
						break;
				}
				*offset = offset[0] + (int)prep + i + 1;
				return start.substr(0, i);

			}
			return L"";

		}
		//extract attibute value or ""
		inline wstring GetByAttribute(wstring html, string attr) {

			wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;
			string s = converter.to_bytes(html);
			regex wordRegex(attr + "=\"(.*?)\"",
				std::regex_constants::ECMAScript | std::regex_constants::icase);
			auto words_begin =
				sregex_iterator(s.begin(), s.end(), wordRegex);
			auto words_end = std::sregex_iterator();

			std::sregex_iterator i = words_begin;
			if (i == words_end) return L"";
			std::smatch match = *i;
			std::string match_strx = match[1].str();
			return converter.from_bytes(match_strx);

		}
		// html to text 
		inline wstring RemoveBrackets(wstring html) {
			std::vector<std::wstring>    text;
			while (true)
			{
				std::string::size_type  startpos;

				startpos = html.find('<');
				if (startpos == std::string::npos)
				{
					// no tags left only text!
					text.push_back(html);
					break;
				}

				// handle the text before the tag    
				if (0 != startpos)
				{
					text.push_back(html.substr(0, startpos));
					html = html.substr(startpos, html.size() - startpos);
					startpos = 0;
				}

				//  skip all the text in the html tag
				std::string::size_type endpos;
				for (endpos = startpos;
					endpos < html.size() && html[endpos] != '>';
					++endpos)
				{
					// since '>' can appear inside of an attribute string we need
					// to make sure we process it properly.
					if (html[endpos] == '"')
					{
						endpos++;
						while (endpos < html.size() && html[endpos] != '"')
						{
							endpos++;
						}
					}
				}

				//  Handle text and end of html that has beginning of tag but not the end
				if (endpos == html.size())
				{
					html = html.substr(endpos, html.size() - endpos);
					break;
				}
				else
				{
					//  handle the entire tag
					endpos++;
					html = html.substr(endpos, html.size() - endpos);
				}
			}
			auto str = str::join(text, ",");
			return str::trim(str);
		}
		// extract recipe card
		inline Recipe ExtractCard(wstring baseHost, wstring html, int *offset = new int{ 0 }) {
			auto cardHtml = extract(html, L"<div class=\"recipe clearfix\">", offset);
			auto imgHtml = extract(cardHtml, L"<img");
			auto contentHtml = extract(cardHtml, L"<div class=\"entry-content\">");
			auto dateHtml = extract(cardHtml, L"<span class=\"control-tip\">");
			auto date = RemoveBrackets(dateHtml);
			auto content = RemoveBrackets(contentHtml);
			auto title = GetByAttribute(imgHtml, "title");
			auto href = GetByAttribute(imgHtml, "src");

			auto recUrlHtml = extract(cardHtml, L"<div class=\"entry-title\">");
			auto recUrl = GetByAttribute(recUrlHtml, "href");
			wstring_convert<std::codecvt_utf8_utf16<wchar_t>> converter;

			Recipe r;

#pragma region Optional
			// optional local image cache
			// app currently use web images
			string out = "./images/";
			CreateFolder(out);
			auto tcout = DownloadURLImage(str::ToTCHAR(converter.to_bytes(href)), str::ToTCHAR(out), NULL);
			r.ImageLocal = tcout;
#pragma endregion

			r.ContentIntro = content;
			r.ImageUrl = href;
			r.Title = title;
			r.Url = baseHost + recUrl;
			return r;

		}
	}
}
#endif // !TOOLS
