#include <iostream>
# define PLUS		0
# define MINUS		1
# define MULTI		2
# define DIVISION	3
using namespace std;

int nMax, nMin;

void swap(int* arr, const int a, const int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void cal(int* nArr, int* nOper, const int N)
{
	int nVal = nArr[0];

	for (int i = 0; i < N; i++)
	{
		switch (nOper[i])
		{
		case PLUS:
			nVal += nArr[i + 1];
			break;
		case MINUS:
			nVal -= nArr[i + 1];
			break;
		case MULTI:
			nVal *= nArr[i + 1];
			break;
		case DIVISION :
			bool isMinus = (nVal < 0) ? true : false;
			nVal = (isMinus) ? nVal * (-1) : nVal;
			nVal = (int)(nVal / nArr[i + 1]);
			nVal = (isMinus) ? nVal * (-1) : nVal;
			break;
		}
	}

	nMax = (nVal > nMax) ? nVal : nMax;
	nMin = (nVal < nMin) ? nVal : nMin;
}

void dfs(int d, const int N, int* nArr, int* nOper)
{
	if (d == N)
	{
		cal(nArr, nOper, N);

		return;
	}

	for (int i = d; i < N; i++)
	{
		if (i != d && nOper[d] == nOper[i])	continue;
		swap(nOper, d, i);
		dfs(d + 1, N, nArr, nOper);
		swap(nOper, d, i);
	}
}

int main()
{
	nMax = -1000000000; nMin = 1000000000;

	int N = 0;
	cin >> N;

	int* nArr = new int[N];
	int* nOperators = new int[N - 1];

	for (int i = 0; i < N; i++)
		cin >> nArr[i];

	int j = 0;
	for (int i = 0; i < 4; i++)
	{
		int nTemp = 0;
		cin >> nTemp;

		for (int t = j; t<j+nTemp; t++)
			nOperators[t] = i;
		j = j + nTemp;
	}

	dfs(0, N-1, nArr, nOperators);

	cout << nMax << "\n";
	cout << nMin;

	delete[] nArr, nOperators;

	return 0;
}