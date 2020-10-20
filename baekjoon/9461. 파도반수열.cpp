#include <iostream>

using namespace std;

long long cal(int n)
{
	long long nArr[5] = { 1,1,1,2, 2 };

	for (int nIdx = 6; nIdx <= n; nIdx++)
		nArr[(nIdx - 1) % 5] = nArr[(nIdx - 1) % 5] + nArr[(nIdx - 2) % 5];

	return nArr[(n - 1) % 5];
}

int main()
{
	int T = 0;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int N = 0;
		cin >> N;

		cout << cal(N) << endl;

	}
	return 0;
}