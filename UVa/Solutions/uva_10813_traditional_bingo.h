#pragma once

#include "common.h"

class UVA_10813
{
	bool bingo[25];
	int bingoNums[25];

	bool checkBingo()
	{
		bool isBingo = false;

		// Check rows and cols
		REP(i, 0, 4)
		{
			if ((bingo[0 * 5 + i] && bingo[1 * 5 + i] && bingo[2 * 5 + i] && bingo[3 * 5 + i] && bingo[4 * 5 + i]) ||
				(bingo[i * 5 + 0] && bingo[i * 5 + 1] && bingo[i * 5 + 2] && bingo[i * 5 + 3] && bingo[i * 5 + 4]))
			{
				isBingo = true;
				break;
			}
		}

		// Check diagonal
		if (!isBingo)
			if ((bingo[0] && bingo[6] && bingo[12] && bingo[18] && bingo[24]) ||
				(bingo[20] && bingo[16] && bingo[12] && bingo[8] && bingo[4]))
			{
				isBingo = true;
			}

		return isBingo;
	}
	void initBingo()
	{
		REP(i, 0, 24)
		{

			bingo[i] = false;

		}
		bingo[12] = true;	// free space
	}

public:

	void Solution()
	{
		int tc;
		cin >> tc;
		while (tc--)
		{

			initBingo();
			bool isbingo = false;

			// Get bingo card
			REP(i, 0, 24)
			{
				if (i == 12)
					continue;
				cin >> bingoNums[i];
			}

			int num;
			int solution = 0;
			// Get readings
			REP(i, 0, 74)
			{
				cin >> num;

				if (isbingo)
					continue;

				const int *it = find(bingoNums, bingoNums + 25, num);
				if (it != bingoNums + 25)
				{
					bingo[it - bingoNums] = true;
				}

				isbingo = checkBingo();

				if (isbingo)
					solution = i + 1;
			}

			cout << "BINGO after " << solution << " numbers announced" << endl;
		}
	}

	void Solution(const char* input, const char* output)
	{
		ifstream in(input, ios::in);
		ofstream out(output, ios::out | ios::trunc);

		int tc;
		in >> tc;
		while (tc--)
		{

			initBingo();
			bool isbingo = false;

			// Get bingo card
			REP(i, 0, 24)
			{
				if (i == 12)
					continue;
				in >> bingoNums[i];
			}

			int num;
			int solution = 0;
			// Get readings
			REP(i, 0, 74)
			{
				in >> num;
				
				if (isbingo)
					continue;

				const int *it = find(bingoNums, bingoNums + 25, num);
				if (it != bingoNums + 25)
				{
					bingo[it - bingoNums] = true;
				}

				isbingo = checkBingo();

				if (isbingo)
					solution = i + 1;
			}

			out << "BINGO after " << solution << " numbers announced" << endl;
		}

		in.close();
		out.close();
	}
};