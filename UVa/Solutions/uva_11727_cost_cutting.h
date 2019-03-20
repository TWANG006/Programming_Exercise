#pragma once

#include "common.h"

class UVA_11727
{
public:

	void Solution()
	{
		int t;
		int a[3];
		int caseNum = 1;

		scanf("%d", &t);
		while (t--)
		{
			scanf("%d %d %d", &a[0], &a[1], &a[2]);

			sort(a, a + 3);

			printf("Case %d: %d\n", caseNum++, a[1]);
		}
	}

	void Solution(const char* input, const char* output)
	{
		FILE *cfin = fopen(input, "r");
		FILE *cfout = fopen(output, "w");

		int t;
		int a[3];
		int caseNum = 1;

		fscanf(cfin, "%d", &t);
		while (t--)
		{
			fscanf(cfin, "%d %d %d", &a[0], &a[1], &a[2]);
			sort(a, a + 3);

			fprintf(cfout, "Case %d: %d\n", caseNum++, a[1]);
		}

		fclose(cfin);
		fclose(cfout);
	}
};