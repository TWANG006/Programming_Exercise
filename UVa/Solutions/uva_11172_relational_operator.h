#pragma once

class UVA_11172
{
public:

	void Solution()
	{
		int tc;
		long int a, b;

		scanf("%d", &tc);

		while (tc--)
		{
			scanf("%ld %ld", &a, &b);
			if (a > b)
				printf(">\n");
			else if (a < b)
				printf("<\n");
			else
				printf("=\n");
		}
	}

	void Solution(const char* input, const char* output)
	{
		FILE *cfin = fopen(input, "r");
		FILE *cfout = fopen(output, "w");

		int tc;
		long int a, b;

		fscanf(cfin, "%d", &tc);

		while (tc--)
		{
			fscanf(cfin, "%ld %ld", &a, &b);
			if (a > b)
				fprintf(cfout, ">\n");
			else if (a < b)
				fprintf(cfout, "<\n");
			else
				fprintf(cfout, "=\n");
		}

		fclose(cfin);
		fclose(cfout);
	}
};