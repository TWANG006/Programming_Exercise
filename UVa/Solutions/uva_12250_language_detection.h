#pragma once


#include "common.h"

class UVA_12250
{
public:

	void Solution()
	{
		string s;
		int caseNum = 1;

		while (cin >> s, s != "#")
		{
			if (s == "HELLO") cout << "Case " << caseNum++ << ": " << "ENGLISH" << endl;
			else if (s == "HOLA") cout << "Case " << caseNum++ << ": " << "SPANISH" << endl;
			else if (s == "HALLO") cout << "Case " << caseNum++ << ": " << "GERMAN" << endl;
			else if (s == "BONJOUR") cout << "Case " << caseNum++ << ": " << "FRENCH" << endl;
			else if (s == "CIAO") cout << "Case " << caseNum++ << ": " << "ITALIAN" << endl;
			else if (s == "ZDRAVSTVUJTE") cout << "Case " << caseNum++ << ": " << "RUSSIAN" << endl;
			else cout << "Case " << caseNum++ << ": " << "UNKNOWN" << endl;
		}
	}

	void Solution(const char* input, const char* output)
	{
		ifstream in(input, ios::in);
		ofstream out(output, ios::out | ios::trunc);

		string s;
		int caseNum = 1;

		while (in >> s, s != "#")
		{
			if (s == "HELLO") out << "Case " << caseNum++ << ": " << "ENGLISH" << endl;
			else if (s == "HOLA") out << "Case " << caseNum++ << ": " << "SPANISH" << endl;
			else if (s == "HALLO") out << "Case " << caseNum++ << ": " << "GERMAN" << endl;
			else if (s == "BONJOUR") out << "Case " << caseNum++ << ": " << "FRENCH" << endl;
			else if (s == "CIAO") out << "Case " << caseNum++ << ": " << "ITALIAN" << endl;
			else if (s == "ZDRAVSTVUJTE") out << "Case " << caseNum++ << ": " << "RUSSIAN" << endl;
			else out << "Case " << caseNum++ << ": " << "UNKNOWN" << endl;
		}

		in.close();
		out.close();
	}

};