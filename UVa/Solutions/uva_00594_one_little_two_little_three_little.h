#pragma once

#include "common.h"

class UVA_00594
{
public:

	void Solution()
	{
		int i;

		while (cin >> i)
		{
			int y = 0;
			for (int j = 0; j < 4; j++)
			{
				y = (y << 8) | ((i >> 8 * j) & 255);
			}

			cout << i << " converts to " << y << endl;
		}
	}

	void Solution(const char* input, const char* output)
	{
		ifstream in(input, ios::in);
		ofstream out(output, ios::out | ios::trunc);

		int i;

		while (in >> i)
		{
			int y = 0; 
			for (int j = 0; j < 4; j++)
			{
				y = (y << 8) | ((i >> 8 * j) & 255);
			}

			out << i << " converts to " << y << endl;
		}
		
		in.close();
		out.close();
	}
};