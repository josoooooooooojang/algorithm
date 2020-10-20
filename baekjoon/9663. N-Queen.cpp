#include <iostream>
#include <string.h>

using namespace std;

int nAns = 0;

bool isOk(int* pArr, const int d)
{
	// 현재 놓여진 퀸들 위치와 비교
	for (int i = 0; i < d; i++)
		if (pArr[i] == pArr[d] || (i+pArr[i]) == (d+pArr[d]) || (i-pArr[i]) == (d-pArr[d]))
			return false;

	return true;
}


void dfs(int* pArr, int d, const int N)
{
	// 퀸을 다 놓으면 탈출
	if (d == N)
	{
		nAns++;

		return;
	}

	// 결국 해당 열에 1개가 꼭 픽스되야 넘어가므로 다시 되돌려줄필요없을듯
	for (int i = 0; i < N; i++)
	{
		pArr[d] = i;

		if (isOk(pArr,d))	
			dfs(pArr, d + 1, N);
	}
}

int main()
{
	int N;
	cin >> N;
	nAns = 0;
	int* pArr = new int[N];

	// 퀸을 놓을 수 있는 상태는 0
	memset(pArr, -1, sizeof(int)*N);
	dfs(pArr, 0, N);
	cout << nAns;

	delete[] pArr;

	return 0;
}