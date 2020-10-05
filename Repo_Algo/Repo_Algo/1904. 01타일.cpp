#include <iostream>

using namespace std;

int cal(int N)
{
	if (N < 4) return N;

	int a = 1;
	int b = 2;
	int nSum = 0;

	for (int i = 0; i < N - 2; i++)
	{
		nSum = (a + b) % 15746;
		a = b;
		b = nSum;
	}

	return nSum;
}

int main()
{
	int N = 0;
	cin >> N;

	cout << cal(N);

	return 0;
}