#pragma once

#include "common.h"

class UVA_10189
{
public:

	void Solution()
	{
		vector<vi> count(100, vi(100, 0));
		char rowChar[101];
		int numFiled = 1;

		int n, m;

		while (cin >> n >> m, n || m)
		{
			clearCount(count);

			REP(i, 0, n - 1)
			{
				cin >> rowChar;

				REP(j, 0, m - 1)
				{
					if (rowChar[j] == '*')
						countNumber(count, i, j, n, m);
				}

			}

			if (numFiled > 1)
				cout << endl;

			// Print
			cout << "Field #" << numFiled << ":" << endl;

			REP(i, 0, n - 1)
			{
				REP(j, 0, m - 1)
				{
					if (count[i][j] == -1)
						cout << "*";
					else
						cout << count[i][j];
				}
				cout << endl;
			}

			numFiled++;
		}
	}

	void Solution(const char* input, const char* output)
	{
		ifstream in(input, ios::in);
		ofstream out(output, ios::out | ios::trunc);

		vector<vi> count(100, vi(100, 0));
		char rowChar[101];
		int numFiled = 1;

		int n, m;

		while (in >> n >> m, n || m)
		{
			clearCount(count);

			REP(i, 0, n - 1)
			{
				in >> rowChar;

				REP(j, 0, m - 1)
				{
					if(rowChar[j]=='*')
						countNumber(count, i, j, n, m);
				}

			}

			if (numFiled > 1)
				out << endl;

			// Print
			out << "Field #" << numFiled << ":" << endl;

			REP(i, 0, n - 1)
			{
				REP(j, 0, m - 1)
				{
					if (count[i][j] == -1)
						out << "*";
					else
						out << count[i][j];
				}
				out << endl;
			}

			numFiled++;
		}	


		in.close();
		out.close();
	}

private:

	void countNumber(vector<vi>& v_count, int y, int x, int n, int m)
	{
		v_count[y][x] = -1;

		for (int i = -1; i <= 1; i++)
		{
			for (int j = -1; j <= 1; j++)
			{
				if (y + i >= 0 && y + i < n && x + j >= 0 && x + j < m && v_count[y + i][x + j] != -1)
				{
					v_count[y + i][x + j]++;
				}
			}
		}
	}

	void clearCount(vector<vi>& v_count)
	{
		for (auto &sub : v_count)
		{
			fill(sub.begin(), sub.end(), 0);
		}
	}
};