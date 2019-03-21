#pragma once

#include "common.h"

class UVA_12372
{
public:

	void Solution()
	{
		int tc;
		cin >> tc;
		int l, w, h;

		int caseNum = 1;

		while (tc--)
		{
			cin >> l >> w >> h;

			if (l <= 20 && w <= 20 && h <= 20)
				cout << "Case " << caseNum++ << ": " << "good" << endl;
			else
				cout << "Case " << caseNum++ << ": " << "bad" << endl;
		}
	}

	void Solution(const char* input, const char* output)
	{
		ifstream in(input, ios::in);
		ofstream out(output, ios::out | ios::trunc);

		int tc;
		in >> tc;
		int l, w, h;

		int caseNum = 1;

		while (tc--)
		{
			in >> l >> w >> h;

			if (l <= 20 && w <= 20 && h <= 20)
				out << "Case " << caseNum++ << ": " << "good" << endl;
			else
				out << "Case " << caseNum++ << ": " << "bad" << endl;
		}


		in.close();
		out.close();
	}
};