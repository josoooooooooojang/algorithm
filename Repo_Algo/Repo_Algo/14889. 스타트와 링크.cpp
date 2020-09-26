#include <iostream>

using namespace std;

int nMin = 9999999;

// �������� ����ϴ� �Լ�
int cal(int N, bool* bChecked, int* nAbilities)
{
	int nScore = 0;

	for (int i = 0; i < N; i++)
	{
		if (bChecked[i])
		{
			for (int j = 0; j < N; j++)
				nScore = (bChecked[j]) ? nScore + nAbilities[i*N + j] : nScore;
		}
		else
		{
			for (int j = 0; j < N; j++)
				nScore = (!bChecked[j]) ? nScore - nAbilities[i*N + j] : nScore;
		}
	}

	nScore = (nScore < 0) ? nScore * (-1) : nScore;

	return nScore;
}

void dfs(int d, int cnt, const int N, bool* bChecked, int* nAbilities)
{
	// ������ �� Ȯ���غ��� Ȯ��
	if (cnt == N/2)
	{
		// �������� ����� ��, �ּڰ��� ��
		int nVal = cal(N, bChecked, nAbilities);
		nMin = (nVal < nMin) ? nVal : nMin;
		return;
	}

	if (d == N) return;

	// ���� d��° ������ �ִ´�.
	bChecked[d] = true;
	dfs(d + 1, cnt+1, N, bChecked, nAbilities);
	
	// ���� �پ�� ���δ�. ���� ������ ã�ƺ���
	bChecked[d] = false;
	dfs(d + 1, cnt, N, bChecked, nAbilities);
}
int main()
{
	nMin = 999999;
	int N = 0;
	cin >> N;

	int* pAbilities = new int[N*N];
	for (int i = 0; i < N; i++)
	for (int j = 0; j < N; j++)
		cin >> pAbilities[i*N + j];

	bool* pCheckd = new bool[N];
	for (int i = 0; i < N; i++)
		pCheckd[i] = false;

	dfs(0,0,N, pCheckd, pAbilities);

	cout << nMin;

	delete[] pAbilities;
	return 0;
}