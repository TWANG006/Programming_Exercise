#pragma once

#include "common.h"

class UVA_11364
{
public:

	void Solution()
	{
		int tc;
		int n;
		int tmp;
		int max_d = -1, min_d = 100;

		scanf("%d", &tc);

		while (tc--)
		{
			max_d = -1, min_d = 100;

			scanf("%d", &n);
			while (n--)
			{
				scanf("%d", &tmp);
				if (tmp > max_d)
					max_d = tmp;
				if (tmp < min_d)
					min_d = tmp;
			}

			printf("%d\n", 2 * (max_d - min_d));
		}
	}

	void Solution(const char* input, const char* output)
	{
		FILE *cfin = fopen(input, "r");
		FILE *cfout = fopen(output, "w");

		int tc;
		int n;
		int tmp;
		int max_d = -1, min_d = 100;

		fscanf(cfin, "%d", &tc);

		while (tc--)
		{
			max_d = -1, min_d = 100;

			fscanf(cfin, "%d", &n);
			while (n--)
			{
				fscanf(cfin, "%d", &tmp);
				if (tmp > max_d)
					max_d = tmp;
				if (tmp < min_d)
					min_d = tmp;
			}

			fprintf(cfout, "%d\n", 2 * (max_d - min_d));
		}

		fclose(cfin);
		fclose(cfout);
	}
};