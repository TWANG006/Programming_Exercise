#pragma once

#include "common.h"

class UVA_01124
{
public:
	void Solution()
	{
		/*int main()
		{*/
		char c;
		while (scanf("%c", &c) != EOF)
		{
			printf("%c", c);
		}
		/*	return 0;
		}*/
	}

	void Solution(const char* input, const char* output)
	{
		FILE *cfin = fopen(input, "r");
		FILE *cfout = fopen(output, "w");

		char c;
		while (fscanf(cfin, "%c", &c) != EOF)
		{
			fprintf(cfout, "%c", c);
		}

		fclose(cfin);
		fclose(cfout);
	}
};
