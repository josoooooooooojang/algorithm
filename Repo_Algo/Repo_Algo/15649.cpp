#include <iostream>

using namespace std;

void printArr(int* nArr, int d)
{
	for (int i = 0; i < d; i++)
		cout << nArr[i] << " ";
	cout << "\n";
}

void rightShift(int* nArr, int start, int end)
{
	int temp = nArr[end];

	for (int i = end; i > start; i--)
		nArr[i] = nArr[i - 1];

	nArr[start] = temp;
}

void leftShift(int * nArr, int start, int end)
{
	int temp = nArr[start];

	for (int i = start; i < end; i++)
		nArr[i] = nArr[i + 1];

	nArr[end] = temp;
}
void permutation(int* nArr, int d, const int N, const int M)
{
	if (d == M)
	{
		printArr(nArr, d);

		return;
	}

	for (int i = d; i < N; i++)
	{
		rightShift(nArr, d, i);
		permutation(nArr, d + 1, N, M);
		leftShift(nArr, d, i);
	}
}

int main()
{

	int N, M;
	cin >> N >> M;

	int* nArr = new int[N];
	for (int i = 0; i < N; i++)
		nArr[i] = i + 1;

	permutation(nArr, 0, N, M);

	return 0;
}