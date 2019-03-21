#pragma once

#include "common.h"

class UVA_12279
{
public:

	void Solution()
	{
		int n;
		int x;
		int caseNum = 1;

		while (cin >> n, n)
		{
			int res = 0;
			while (n--)
			{
				cin >> x;
				x > 0 ? ++res : --res;
			}

			cout << "Case " << caseNum++ << ": " << res << endl;
		}
	}

	void Solution(const char* input, const char* output)
	{
		ifstream in(input, ios::in);
		ofstream out(output, ios::out | ios::trunc);

		int n;
		int x;
		int caseNum = 1;

		while (in >> n, n)
		{
			int res = 0;
			while (n--)
			{
				in >> x;
				x > 0 ? ++res : --res;
			}

			out << "Case " << caseNum++ << ": " << res << endl;
		}

		in.close();
		out.close();
	}
};