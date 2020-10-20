#include <iostream>
#include <string.h>
using namespace std;
long long nArr[91];

long long fibo(int n)
{
	if (nArr[n] == -1)
		nArr[n] = fibo(n - 2) + fibo(n - 1);

	return nArr[n];
}

int main()
{
	memset(nArr, -1, sizeof(nArr));
	nArr[0] = 0;
	nArr[1] = 1;

	int N = 0;
	cin >> N;

	cout << fibo(N);

	return 0;
}