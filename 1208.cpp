#pragma warning(disable:4996)
#include <string>

// 고점부터 가능한 만큼 덤프를 진행
int DoDump(int* arr, int d)
{
	// 평탄화를 할 위치를 찾는다.
	int nIndex = 0;
	while (arr[++nIndex] == 100);

	// 평탄화할 층에 덤프를 진행
	arr[nIndex] += d;

	// 초과된 덤프량이 해소될 때까지 다음 층으로 덤프작업을 넘기기
	while (arr[nIndex] > 100)
	{
		// 만약 100층이 100으로 다 평활화될 수도 있으니까 방지
		if (nIndex == 101) break;

		// 다음층(nIndex+1)에 현재층의 초과분(arr[nIndex] % 100)을 더해준다.
		arr[nIndex + 1] += arr[nIndex] % 100;

		// 현재층은 평활화 작업 완료 표시를 하고 다음층으로 넘어간다(++)
		arr[nIndex++] = 100;
	}

	// 평탄화가 완료된 층중 가장 높은층을 찾는다 ==> 평탄화가 필요한 층의 아래층
	int nLow = 1;
	while (arr[++nLow] == 100);

	return nLow - 1;
}

int main()
{
	for (int t = 0; t < 10; t++)
	{
		int D = 0;
		scanf("%d", &D);

		int nAccumHeight[101] = { 0, };
		for (int i = 0; i < 100; i++)
		{
			int input = 0;
			scanf("%d", &input);

			// 각 층에 값을 누적한다.
			while (input != 0)
				nAccumHeight[input--]++;
		}

		int nLeft = 0;
		int nRight = 101;

		// 덤프 값이 제로가 될 때까지 반복
		// nLeft == nRight 조건으로 반복 탈출하여 시간단축가능
		while (D != 0)
		{
			// 고점의 누적 값이 덤프보다 작을 경우 누적 값 모두 진행
			if (D > nAccumHeight[nRight])
			{
				D -= nAccumHeight[nRight];
				nLeft = DoDump(nAccumHeight, nAccumHeight[nRight]);
				nAccumHeight[nRight--] = 0;
			}
			// 고점의 누적 값이 덤프보다 클 경우 덤프 만큼만 진행
			else
			{
				nAccumHeight[nRight] -= D;
				if (nAccumHeight[nRight] == 0)
					nRight--;
				nLeft = DoDump(nAccumHeight, D);
				D = 0;
			}
		}
		printf("#%d %d\n", (t + 1), (nRight - nLeft));
	}

	return 0;
}