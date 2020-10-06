#include <iostream>
#include <algorithm>
using namespace std;
int nMin = 1000000;

int dp(int** p, const int N)
{
	int dp[3] = { p[0][0], p[0][1], p[0][2] };
	int idx[3] = { 0, 1, 2 };

	for (int i = 1; i < N; i++)
	{
		if (p[i][(idx[0] + 1) % 3] < p[i][(idx[0] + 2) % 3])
		{
			dp[0] += p[i][(idx[0] + 1) % 3];
			idx[0] = (idx[0] + 1) % 3;
		}
		else
		{
			dp[0] += p[i][(idx[0] + 2) % 3];
			idx[0] = (idx[0] + 2) % 3;
		}

		if (p[i][(idx[1] + 1) % 3] < p[i][(idx[1] + 2) % 3])
		{
			dp[1] += p[i][(idx[1] + 1) % 3];
			idx[1] = (idx[1] + 1) % 3;
		}
		else
		{
			dp[1] += p[i][(idx[1] + 2) % 3];
			idx[1] = (idx[1] + 2) % 3;
		}

		if (p[i][(idx[2] + 1) % 3] < p[i][(idx[2] + 2) % 3])
		{
			dp[2] += p[i][(idx[2] + 1) % 3];
			idx[2] = (idx[2] + 1) % 3;
		}
		else
		{
			dp[2] += p[i][(idx[2] + 2) % 3];
			idx[2] = (idx[2] + 2) % 3;
		}
	}

	return min(min(dp[0], dp[1]), dp[2]);
}

int main()
{
	int N = 0;
	cin >> N;

	int** p = new int*[N];

	for (int i = 0; i < N; i++)
	{
		p[i] = new int[3];
		for (int j = 0; j < 3; j++)
			cin >> p[i][j];
	}

	cout<<dp(p, N);

	return 0;
}