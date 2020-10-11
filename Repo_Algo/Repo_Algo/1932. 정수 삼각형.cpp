#include <iostream>

using namespace std;

int max(int a, int b) { return (a > b) ? a : b; }

int main()
{
	int N = 0;
	cin >> N;

	int nDP[500];
	int nTemp[500];
	int nMax = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			int nVal = 0;
			cin >> nVal;

			if (i == 0)
			{
				nDP[0] = nVal;
				nTemp[0] = nVal;

				continue;
			}

			int nNumA = (j - 1 >= 0) ? nDP[j - 1] : 0;
			int nNumB = (j < i) ? nDP[j] : 0;

			nTemp[j] = max(nNumA, nNumB) + nVal;
		}

		for (int j = 0; j <= i; j++)
		{
			nDP[j] = nTemp[j];
			nMax = max(nTemp[j], nMax);
		}
	}

	cout << nMax;

	return 0;
}