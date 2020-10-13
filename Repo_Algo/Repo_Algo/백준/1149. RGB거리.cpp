#include <iostream>

using namespace std;

int min(int a, int b) { return a < b ? a : b; }

int main()
{
	int N = 0;
	cin >> N;

	int nCost[1000][3];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < 3; j++)
			cin >> nCost[i][j];

	int nDP[1000][3] = { nCost[0][0], nCost[0][1], nCost[0][2], };

	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int nVal = min(nDP[i - 1][(j + 1) % 3], nDP[i - 1][(j + 2) % 3]);
			nDP[i][j] = nVal + nCost[i][j];
		}
	}

	cout << min(min(nDP[N - 1][0], nDP[N - 1][1]), nDP[N - 1][2]);

	return 0;
}