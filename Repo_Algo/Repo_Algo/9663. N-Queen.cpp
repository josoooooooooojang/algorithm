#include <iostream>
#include <string.h>

using namespace std;

int nAns = 0;

bool isOk(int* pArr, const int d)
{
	// ���� ������ ���� ��ġ�� ��
	for (int i = 0; i < d; i++)
		if (pArr[i] == pArr[d] || (i+pArr[i]) == (d+pArr[d]) || (i-pArr[i]) == (d-pArr[d]))
			return false;

	return true;
}


void dfs(int* pArr, int d, const int N)
{
	// ���� �� ������ Ż��
	if (d == N)
	{
		nAns++;

		return;
	}

	// �ᱹ �ش� ���� 1���� �� �Ƚ��Ǿ� �Ѿ�Ƿ� �ٽ� �ǵ������ʿ������
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

	// ���� ���� �� �ִ� ���´� 0
	memset(pArr, -1, sizeof(int)*N);
	dfs(pArr, 0, N);
	cout << nAns;

	delete[] pArr;

	return 0;
}