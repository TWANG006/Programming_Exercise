#pragma once

#include "common.h"

class UVA_12289
{
public:
	void Solution()
	{
		int tc;
		string s;

		cin >> tc;

		while (tc--)
		{
			cin >> s;
			if (s.size() == 5) cout << "3" << endl;
			else {
				if ((s[0] == 'o' && (s[1] == 'n' || s[2] == 'e')) ||
					(s[1] == 'n' && (s[0] == 'o' || s[2] == 'e')) ||
					(s[2] == 'e' && (s[0] == 'o' || s[1] == 'n')))
					cout << "1" << endl;
				else
					cout << "2" << endl;
			}
		}
	}

	void Solution(const char* input, const char* output)
	{
		ifstream in(input, ios::in);
		ofstream out(output, ios::out | ios::trunc);

		int tc;
		string s;

		in >> tc;

		while (tc--)
		{
			in >> s;
			if (s.size() == 5) out << "3" << endl;
			else {
				if ((s[0] == 'o' && (s[1] == 'n' || s[2] == 'e')) ||
					(s[1] == 'n' && (s[0] == 'o' || s[2] == 'e')) ||
					(s[2] == 'e' && (s[0] == 'o' || s[1] == 'n')))
					out << "1" << endl;
				else
					out << "2" << endl;
			}
		}

		in.close();
		out.close();
	}
};