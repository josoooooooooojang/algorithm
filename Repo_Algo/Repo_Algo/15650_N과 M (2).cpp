#include <iostream>

using namespace std;

bool isAscend(int* pArr, int d)
{
	bool bAnswer = true;
	int nTemp = pArr[0];

	for (int i = 1; i < d; i++)
	{
		if (nTemp > pArr[i])
		{
			bAnswer = false;
			break;
		}

		nTemp = pArr[i];
	}

	return bAnswer;
}

void printArr(int* pArr, const int d)
{
	for (int i = 0; i < d; i++)
		cout << pArr[i] << " ";
	cout << "\n";
}

void rightShift(int* pArr, int start, int end)
{
	int nTemp = pArr[end];

	for (int i = end; i > start; i--)
		pArr[i] = pArr[i - 1];

	pArr[start] = nTemp;
}

void leftShift(int * pArr, int start, int end)
{
	int nTemp = pArr[start];

	for (int i = start; i < end; i++)
		pArr[i] = pArr[i+1];

	pArr[end] = nTemp;
}

void permutation(int* pArr, int d, const int N, const int M)
{
	if (d == M)
	{
		// 출력하기전에 하나씩 확인하여 오름차순인지를 확인한다
		if (isAscend(pArr, d))
			printArr(pArr, d);

		return;
	}
	
	for (int i = d; i < N; i++)
	{		
		rightShift(pArr, d, i);
		permutation(pArr, d + 1, N, M);
		leftShift(pArr, d, i);
	}
}

int main()
{
	int N, M;
	cin >> N >> M;

	int* pArr = new int[N];
	bool* pCheck = new bool[N];
	for (int i = 0; i < N; i++)
	{
		pArr[i] = (i + 1);
		pCheck[i] = false;
	}
	
	permutation(pArr, 0, N, M);

	delete pArr, pCheck;

	return 0;
}