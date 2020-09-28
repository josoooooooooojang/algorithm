#include <iostream>>

using namespace std;

void printArr(int d, bool* bCheck)
{
	for (int i = 0; i < d; i++)
		if (bCheck[i]) cout << (i + 1) << " ";
	cout << "\n";
}

void dfs(int d, int cnt, const int N, const int M, bool* bCheck)
{
	if (cnt == M)
	{
		printArr(d, bCheck);

		return;
	}

	if (d == N)
		return;

	bCheck[d] = true;
	dfs(d + 1, cnt + 1, N, M, bCheck);
	bCheck[d] = false;
	dfs(d + 1, cnt, N, M, bCheck);
}

int main()
{
	int N, M;
	cin >> N >> M;

	bool* pCheck = new bool[N];
	for (int i = 0; i < N; i++)
		pCheck[i] = false;

	dfs(0, 0, N, M, pCheck);

	delete[] pCheck;

	return 0;
}