#pragma warning(disable:4996)

#include <stdio.h>
#include <string.h>

#define MAX_HEIGHT 255

int check(int* arr, int c)
{
	int min = MAX_HEIGHT;

	for (int i = 1; i < 5; i++)
	{
		int val = arr[c%5] - arr[(c+i)%5];
		if (val < 0)
			return 0;
		min = val < min ? val : min;
	}

	return min;
}

int main()
{
	for (int t = 0; t < 10; t++)
	{
		int N = 0;  
		scanf("%d", &N);

		int arr[5];
		int ans = 0;

		for (int i = 0; i < N; i++)
		{
			int input = 0;
			scanf("%d", &input);
			arr[i % 5] = input;
			if (i >= 4)
				ans += check(arr, i-2);
		}
		printf("#%d %d\n", t+1,ans);
	}

	return 0;
}
