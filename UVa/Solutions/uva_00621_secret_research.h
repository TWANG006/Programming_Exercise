#pragma once

#include "common.h"

class UVA_00621
{
public:
	void Solution()
	{
		int n;
		string s;
		int len;

		cin >> n;

		while (n--)
		{
			cin >> s;
			len = s.length();

			if (s == "1" || s == "4" || s == "78") cout << "+" << endl;
			else if (s.back() == '5' && s[len - 2] == '3') cout << "-" << endl;
			else if (s.front() == '9' && s.back() == '4') cout << "*" << endl;
			else cout << "?" << endl;
		}
	}

	void Solution(const char* input, const char* output)
	{
		ifstream in(input, ios::in);
		ofstream out(output, ios::out | ios::trunc);

		int n;
		string s;
		int len;

		in >> n;

		while (n--)
		{
			in >> s;
			len = s.length();

			if (s == "1" || s == "4" || s == "78") out << "+" << endl;
			else if (s.back() == '5' && s[len - 2] == '3') out << "-" << endl;
			else if (s.front() == '9' && s.back() == '4') out << "*" << endl;
			else out << "?" << endl;
		}

		in.close();
		out.close();
	}
};