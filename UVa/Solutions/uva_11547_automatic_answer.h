#pragma once

#include "common.h"

class UVA_11547
{
public:
	void Solution()
	{
		/* 36962 + 315n */
		int tc;
		int n;

		scanf("%d", &tc);

		while (tc--)
		{
			scanf("%d", &n);
			printf("%d\n", abs((36962 + 315 * n)) / 10 % 10);
		}
	}

	void Solution(const char* input, const char* output)
	{
		FILE *cfin = fopen(input, "r");
		FILE *cfout = fopen(output, "w");

		int tc;
		int n;

		fscanf(cfin, "%d", &tc);

		while (tc--)
		{
			fscanf(cfin, "%d", &n);
			fprintf(cfout, "%d\n", abs((36962 + 315 * n)) / 10 % 10);
		}

		fclose(cfin);
		fclose(cfout);
	}
};