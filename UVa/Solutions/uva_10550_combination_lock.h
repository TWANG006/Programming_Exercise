#pragma once

#include "common.h"

class UVA_10550
{
public:

	/* Note: Look at the picture: the counter-clock and clock are reversed.*/
	void Solution()
	{
		int ini, a, b, c;
		while (scanf("%d %d %d %d", &ini, &a, &b, &c), (ini || a || b || c))
		{
			printf("%d\n", 1080 + ((ini - a + 40) % 40 + (b - a + 40) % 40 + (b - c + 40) % 40) * 9);
		}
	}

	void Solution(const char* input, const char* output)
	{
		FILE *cfin = fopen(input, "r");
		FILE *cfout = fopen(output, "w");


		int ini, a, b, c;
		while (fscanf(cfin, "%d %d %d %d", &ini, &a, &b, &c), (ini || a || b || c))
		{
			fprintf(cfout, "%d\n", 1080 + ((ini - a + 40) % 40 + (b - a + 40) % 40 + (b - c + 40) % 40) * 9);
		}

		fclose(cfin);
		fclose(cfout);
	}
};