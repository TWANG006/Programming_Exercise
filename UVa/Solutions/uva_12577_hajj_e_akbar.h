#pragma once

#include "common.h"

class UVA_12577
{
public:

	void Solution()
	{
		string s;

		int caseNum = 1;

		while (cin >> s, s != "*")
		{
			if (s == "Hajj")
				cout << "Case " << caseNum++ << ": Hajj-e-Akbar" << endl;
			else
				cout << "Case " << caseNum++ << ": Hajj-e-Asghar" << endl;
		}
	}

	void Solution(const char* input, const char* output)
	{
		ifstream in(input, ios::in);
		ofstream out(output, ios::out | ios::trunc);

		string s;

		int caseNum = 1;

		while (in >> s, s != "*")
		{
			if (s == "Hajj")
				out << "Case " << caseNum++ << ": Hajj-e-Akbar" << endl;
			else
				out << "Case " << caseNum++ << ": Hajj-e-Asghar" << endl;
		}

		in.close();
		out.close();
	}
};