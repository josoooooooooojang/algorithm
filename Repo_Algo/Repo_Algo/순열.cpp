#include <iostream>

using namespace std;

void printArr(int* nArr, int d)
{
	for (int i = 0; i < d; i++)
		cout << nArr[i] << " ";
	cout << "\n";
}

void swap(int* nArr, int a, int b)
{
	int temp = nArr[a];
	nArr[a] = nArr[b];
	nArr[b] = temp;
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
		swap(nArr, d, i);
		permutation(nArr, d + 1, N, M);
		swap(nArr, d, i);
	}

	return;
}

int main()
{

	int N, M;
	cin >> N >> M;

	int* nArr = new int[N];
	for (int i = 0; i < N; i++)
		nArr[i] = i + 1;

	permutation(nArr, 0, N, M);

	delete[] nArr;

	return 0;
}