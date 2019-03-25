#pragma once

#include "common.h"

class UVA_10443
{
	char original[100 + 2][100 + 2];
	char updated[100 + 2][100 + 2];

	bool isValid(int x, int y, int r, int c)
	{
		if (x < 0 || x >= c || y < 0 || y >= r)
			return false;
		else
			return true;
	}
	void fight(int cx, int cy, int nx, int ny)
	{
		if (original[cy][cx] != original[ny][nx])
		{
			switch (original[cy][cx])
			{
			case 'R':
				if (original[ny][nx] == 'S') {
					updated[ny][nx] = 'R';
				}
				else {
					updated[cy][cx] = 'P';
				}
				break;
			case 'S':
				if (original[ny][nx] == 'R') {
					updated[cy][cx] = 'R';
				}
				else {
					updated[ny][nx] = 'S';
				}
				break;
			case 'P':
				if (original[ny][nx] == 'R') {
					updated[ny][nx] = 'P';
				}
				else {
					updated[cy][cx] = 'S';
				}
				break;
			}
		}

	}
	void duplicate(int r, int c)
	{
		REP(i, 0, r - 1)
		{
			REP(j, 0, c - 1)
			{
				original[i][j] = updated[i][j];
			}
		}
	}

public:

	void Solution()
	{
		int tc;
		cin >> tc;

		bool firstTime = true;

		while (tc--)
		{
			int r, c, n;
			cin >> r >> c >> n;

			REP(i, 0, r - 1)
			{
				cin >> updated[i];
			}
			duplicate(r, c);

			int dx[] = { -1, 0, 1, 0 };
			int dy[] = { 0, 1, 0, -1 };

			while (n--)
			{
				// fight
				REP(cy, 0, r - 1)
				{
					REP(cx, 0, c - 1)
					{
						for (int k = 0; k < 4; k++)
						{
							int nx = cx + dx[k];
							int ny = cy + dy[k];

							if (isValid(nx, ny, r, c))
							{
								fight(cx, cy, nx, ny);
							}
						}
					}
				}
				duplicate(r, c);
			}

			// Output
			if (!firstTime)
			{
				cout << endl;
			}

			firstTime = false;

			REP(i, 0, r - 1)
			{
				REP(j, 0, c - 1)
				{
					cout << original[i][j];
				}
				cout << endl;
			}
		}
	}

	void Solution(const char* input, const char* output)
	{
		ifstream in(input, ios::in);
		ofstream out(output, ios::out | ios::trunc);

		int tc;
		in >> tc;

		bool firstTime = true;

		while (tc--)
		{
			int r, c, n;
			in >> r >> c >> n;

			REP(i, 0, r - 1)
			{
				in >> updated[i];
			}
			duplicate(r, c);

			int dx[] = { -1, 0, 1, 0 };
			int dy[] = { 0, 1, 0, -1 };

			while (n--)
			{
				// fight
				REP(cy, 0, r - 1)
				{
					REP(cx, 0, c - 1)
					{
						for (int k = 0; k < 4; k++)
						{
							int nx = cx + dx[k];
							int ny = cy + dy[k];

							if (isValid(nx, ny, r, c))
							{
								fight(cx, cy, nx, ny);
							}
						}
					}
				}
				duplicate(r, c);
			}

			// Output
			if (!firstTime)
			{
				out << endl;
			}

			firstTime = false;

			REP(i, 0, r - 1)
			{
				REP(j, 0, c - 1)
				{
					out << original[i][j];
				}
				out << endl;
			}
		}

		in.close();
		out.close();
	}




};