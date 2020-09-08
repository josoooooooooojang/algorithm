#pragma warning(disable:4996)
#include <string>

// �������� ������ ��ŭ ������ ����
int DoDump(int* arr, int d)
{
	// ��źȭ�� �� ��ġ�� ã�´�.
	int nIndex = 0;
	while (arr[++nIndex] == 100);

	// ��źȭ�� ���� ������ ����
	arr[nIndex] += d;

	// �ʰ��� �������� �ؼҵ� ������ ���� ������ �����۾��� �ѱ��
	while (arr[nIndex] > 100)
	{
		// ���� 100���� 100���� �� ��Ȱȭ�� ���� �����ϱ� ����
		if (nIndex == 101) break;

		// ������(nIndex+1)�� �������� �ʰ���(arr[nIndex] % 100)�� �����ش�.
		arr[nIndex + 1] += arr[nIndex] % 100;

		// �������� ��Ȱȭ �۾� �Ϸ� ǥ�ø� �ϰ� ���������� �Ѿ��(++)
		arr[nIndex++] = 100;
	}

	// ��źȭ�� �Ϸ�� ���� ���� �������� ã�´� ==> ��źȭ�� �ʿ��� ���� �Ʒ���
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

			// �� ���� ���� �����Ѵ�.
			while (input != 0)
				nAccumHeight[input--]++;
		}

		int nLeft = 0;
		int nRight = 101;

		// ���� ���� ���ΰ� �� ������ �ݺ�
		// nLeft == nRight �������� �ݺ� Ż���Ͽ� �ð����డ��
		while (D != 0)
		{
			// ������ ���� ���� �������� ���� ��� ���� �� ��� ����
			if (D > nAccumHeight[nRight])
			{
				D -= nAccumHeight[nRight];
				nLeft = DoDump(nAccumHeight, nAccumHeight[nRight]);
				nAccumHeight[nRight--] = 0;
			}
			// ������ ���� ���� �������� Ŭ ��� ���� ��ŭ�� ����
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