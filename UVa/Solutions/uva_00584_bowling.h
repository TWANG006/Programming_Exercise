#pragma once

#include "common.h"

class UVA_00584
{
public:

	void Solution()
	{
		
	}

	void Solution(const char* input, const char* output)
	{
		ifstream in(input, ios::in);
		ofstream out(output, ios::out | ios::trunc);

		string s;

		
		while (getline(in, s), s != "Game Over")
		{
			
			cout << s << endl;
		}

		in.close();
		out.close();
	}
};