#pragma once

#include "common.h"

class UVA_11498
{
public:

	void Solution()
	{
		int k;
		int n, m;
		int x, y;
		int dif_x, dif_y;


		while (scanf("%d", &k), k)
		{
			scanf("%d %d", &n, &m);

			while (k--)
			{
				scanf("%d %d", &x, &y);

				dif_x = x - n;
				dif_y = y - m;

				if (dif_x == 0 || dif_y == 0)
				{
					printf("divisa\n");
				}
				else if (dif_x > 0 && dif_y > 0)
				{
					printf("NE\n");
				}
				else if (dif_x > 0 && dif_y < 0)
				{
					printf("SE\n");
				}
				else if (dif_x < 0 && dif_y < 0)
				{
					printf("SO\n");
				}
				else
				{
					printf("NO\n");
				}
			}
		}
	}

	void Solution(const char* input, const char* output)
	{
		FILE *cfin = fopen(input, "r");
		FILE *cfout = fopen(output, "w");

		int k;
		int n, m;
		int x, y;
		int dif_x, dif_y;


		while (fscanf(cfin, "%d", &k), k)
		{
			fscanf(cfin, "%d %d", &n, &m);

			while (k--)
			{
				fscanf(cfin, "%d %d", &x, &y);

				dif_x = x - n;
				dif_y = y - m;

				if (dif_x == 0 || dif_y == 0)
				{
					fprintf(cfout, "divisa\n");
				}
				else if (dif_x > 0 && dif_y > 0)
				{
					fprintf(cfout, "NE\n");
				}
				else if (dif_x > 0 && dif_y < 0)
				{
					fprintf(cfout, "SE\n");
				}
				else if (dif_x < 0 && dif_y < 0)
				{
					fprintf(cfout, "SO\n");
				}
				else
				{
					fprintf(cfout, "NO\n");
				}
			}
		}

		fclose(cfin);
		fclose(cfout);
	}
};