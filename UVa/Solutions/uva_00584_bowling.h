#pragma once

#include "common.h"

class UVA_00584
{
public:

	void Solution()
	{
		string s;
		int scores[30];

		while (getline(cin, s), s != "Game Over")
		{
			int total = 0;

			// Rmove all the spaces
			s.erase(remove(s.begin(), s.end(), ' '), s.end());

			// Transfer string scores into ints
			for (int i = 0; i < s.size(); i++)
			{
				if (s[i] == 'X' || s[i] == '/') scores[i] = 10;
				else scores[i] = s[i] - '0';
			}

			int fms = 0;
			for (int i = 0; i < s.size() && fms < 10;)
			{
				if (s[i] == 'X')
				{
					int tmp = 0;
					if (s[i + 2] == '/')
						tmp = 10 - scores[i + 1];
					else
						tmp = scores[i + 2];

					total += 10 + tmp + scores[i + 1];
					i++;
				}
				else
				{
					if (s[i + 1] == '/')
						total += 10 + scores[i + 2];
					else
						total += scores[i] + scores[i + 1];

					i += 2;
				}
				fms++;
			}
			cout << total << endl;
		}
	}

	void Solution(const char* input, const char* output)
	{
		ifstream in(input, ios::in);
		ofstream out(output, ios::out | ios::trunc);

		string s;
		int scores[30];

		while (getline(in, s), s != "Game Over")
		{
			int total = 0;

			// Rmove all the spaces
			s.erase(remove(s.begin(), s.end(), ' '), s.end());

			// Transfer string scores into ints
			for (int i = 0; i < s.size(); i++)
			{
				if (s[i] == 'X' || s[i] == '/') scores[i] = 10;
				else scores[i] = s[i] - '0';
			}

			int fms = 0;
			for (int i = 0; i < s.size() && fms < 10;)
			{
				if (s[i] == 'X')
				{
					int tmp = 0;
					if (s[i + 2] == '/')
						tmp = 10 - scores[i + 1];
					else
						tmp = scores[i + 2];

					total += 10 + tmp + scores[i + 1];
					i++;
				}
				else
				{
					if (s[i + 1] == '/')
						total += 10 + scores[i + 2];
					else
						total += scores[i] + scores[i + 1];

					i += 2;
				}
				fms++;
			}
			out << total << endl;
		}

		in.close();
		out.close();
	}
};