#pragma once

#include "common.h"

class UVA_11459
{
public:

	void Solution()
	{
		int tc;

		vi players(MX, 1);	// Players
		vi snake_and_ladder(101, -1);

		cin >> tc;
		while (tc--)
		{
			int a, b, c;
			cin >> a >> b >> c;

			REP(i, 1, a) players[i] = 1;
			REP(i, 1, 100) snake_and_ladder[i] = -1;

			// Get the snakes and ladders
			while (b--)
			{
				int k, v;
				cin >> k >> v;
				snake_and_ladder[k] = v;
			}

			bool finished = false;
			// Begin the movement
			REP(i, 1, c)
			{
				// The movement is for person p
				int p = (i - 1) % a + 1;

				// The movement amount
				int m;
				cin >> m;

				if (finished) continue;

				players[p] = min(players[p] + m, 100);
				if (snake_and_ladder[players[p]] != -1)
					players[p] = snake_and_ladder[players[p]];
				if (players[p] == 100)
					finished = true;
			}

			// Print the result
			REP(i, 1, a)
				cout << "Position of player " << i << " is " << players[i] << "." << endl;

		}
	}

	void Solution(const char* input, const char* output)
	{
		ifstream in(input, ios::in);
		ofstream out(output, ios::out | ios::trunc);

		int tc;

		vi players(MX, 1);	// Players
		vi snake_and_ladder(101, -1);

		in >> tc;
		while (tc--)
		{
			int a, b, c;
			in >> a >> b >> c;

			REP(i, 1, a) players[i] = 1;
			REP(i, 1, 100) snake_and_ladder[i] = -1;

			// Get the snakes and ladders
			while (b--)
			{
				int k, v;
				in >> k >> v;
				snake_and_ladder[k] = v;
			}

			bool finished = false;
			// Begin the movement
			REP(i, 1, c)
			{
				// The movement is for person p
				int p = (i - 1) % a + 1;

				// The movement amount
				int m;
				in >> m;

				if (finished) continue;

				players[p] = min(players[p] + m, 100);
				if (snake_and_ladder[players[p]] != -1)
					players[p] = snake_and_ladder[players[p]];
				if (players[p] == 100)
						finished = true;
			}

			// Print the result
			REP(i, 1, a)
				out << "Position of player " << i << " is " << players[i] << "." << endl;

		}

		in.close();
		out.close();
	}
};