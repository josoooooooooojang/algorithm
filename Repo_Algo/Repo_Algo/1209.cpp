#pragma warning(disable:4996)

#include <string.h>
#include <stdio.h>
#include <algorithm>

using namespace std;

int nRowArr[100] = { 0, };
int nColArr[100] = { 0, };
int nSumL2B = 0;
int nSumR2B = 0;
int nRowMax = 0;
int nColMax = 0;

void init()
{
	memset(nRowArr, 0, sizeof(nRowArr));
	memset(nColArr, 0, sizeof(nColArr));
	nSumL2B = 0;
	nSumR2B = 0;
	nRowMax = 0;
	nColMax = 0;
}

int main()
{
	for (int t = 1; t <= 10; t++)
	{
		scanf("%d", &t);
		init();

		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				int input = 0;
				scanf("%d", &input);

				nRowArr[i] += input;
				nColArr[j] += input;				
				nSumL2B = (i == j) ? nSumL2B + input : nSumL2B;
				nSumR2B = (i + j == 99) ? nSumR2B + input : nSumR2B;

				nRowMax = max(nRowArr[i], nRowMax);
				nColMax = max(nColArr[j], nColMax);
			}
		}

		int nMax = max(nSumL2B, nSumR2B);
		nMax = max(nMax, nRowMax);
		nMax = max(nMax, nColMax);

		printf("#%d %d\n", t, nMax);
	}

	return 0;
}