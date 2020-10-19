#include <iostream>
#include <stdlib.h>
#define MAX_WIDTH 9

using namespace std;

int nSdoku[10][10];
int answer[10][10];

// �ش� ĭ�� �������� Ȯ���ϴ� �Լ�
bool isOk(int row, int col, int num)
{
	// ����, ���� ã��
	for (int i = 1; i <= MAX_WIDTH; i++)
		if (nSdoku[row][i] == num || nSdoku[i][col] == num)	 return false;

	// �ڽ� ã��
	int sX = col;
	int sY = row;

	while (sX % 3 != 1)	sX--;
	while (sY % 3 != 1)	sY--;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (nSdoku[sY+i][sX+j] == num)		return false;

	return true;
}

// ä���� ������ ����ϴ� �Լ�
void printSdoku()
{
	for (int i = 1; i <= MAX_WIDTH; i++)
	{
		for (int j = 1; j <= MAX_WIDTH; j++)
			cout << nSdoku[i][j] << " ";
		cout << "\n";
	}
}

void dfs(int row, int col)
{
	// ������ �ٱ��� ���� �� �̻��� ������ ����ϰ� ���μ��� ����
	if (row > MAX_WIDTH)
	{
		printSdoku();
		exit(0);
	}

	// ��ĭ�� �ƴϸ� ���� ĭ���� �̵��Ѵ�
	if (nSdoku[row][col] != 0)
	{
		// ������ ĭ���� ���� �ε����� ���� �� ������ ����������.		
		if (col == MAX_WIDTH)	
			dfs(row + 1, 1);
		else
			dfs(row, col + 1);

		return;
	}

	// �ش� ĭ�� �� �� �ִ� ���ڸ� ã��.
	for (int n = 1; n <= MAX_WIDTH; n++)
	{
		//if (nSdoku[row][col] != 0) continue;
		// ã�� ���� �־ �Ǵ��� Ȯ���Ѵ�.
		if (isOk(row, col, n))
		{
			// ���� �ְ� ���� ĭ���� ����.
			nSdoku[row][col] = n;

			if (col == MAX_WIDTH)
				dfs(row + 1, 1);
			else
				dfs(row, col + 1);

			// ���� ������ �߾ȵ����� �ٽ� ���ƿͼ� ĭ�� �������.
			nSdoku[row][col] = 0;
		}
	}
}

int main()
{
	for (int i = 1; i <= MAX_WIDTH; i++)
	for (int j = 1; j <= MAX_WIDTH; j++)
		cin >> nSdoku[i][j];

	dfs(1, 1);

	return 0;
}