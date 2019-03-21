#pragma once

#include "common.h"

class UVA_12403
{
public:

	void Solution()
	{
		unsigned int sum = 0;
		unsigned int tmp;
		int t;
		string s;

		cin >> t;
		while (t--)
		{
			cin >> s;
			if (s == "donate")
			{
				cin >> tmp;
				sum += tmp;
			}
			else
			{
				cout << sum << endl;
			}
		}
	}

	void Solution(const char* input, const char* output)
	{
		ifstream in(input, ios::in);
		ofstream out(output, ios::out | ios::trunc);

		unsigned int sum = 0;
		unsigned int tmp;
		int t;
		string s;

		in >> t;
		while (t--)
		{
			in >> s;
			if (s == "donate")
			{
				in >> tmp;
				sum += tmp;
			}
			else
			{
				out << sum << endl;
			}
		}
		
		in.close();
		out.close();
	}
};