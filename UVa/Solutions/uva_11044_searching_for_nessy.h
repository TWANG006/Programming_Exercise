#pragma once

#include "common.h"

class UVA_11044
{
public:
	void Solution()
	{
		int tc;
		int n, m;

		scanf("%d", &tc);

		while (tc--)
		{
			scanf("%d %d", &n, &m);
			printf("%d\n", (n / 3) * (m / 3));
		}
	}

	void Solution(const char* input, const char* output)
	{
		FILE *cfin = fopen(input, "r");
		FILE *cfout = fopen(output, "w");

		int tc;
		int n, m;

		fscanf(cfin, "%d", &tc);

		while (tc--)
		{
			fscanf(cfin, "%d %d", &n, &m);
			fprintf(cfout, "%d\n", (n / 3) * (m / 3));
		}

		fclose(cfin);
		fclose(cfout);
	}
};