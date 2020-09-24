#include <iostream>
#include <stdlib.h>
#define MAX_WIDTH 9

using namespace std;

int nSdoku[10][10];
int answer[10][10];

// 해당 칸이 가능한지 확인하는 함수
bool isOk(int row, int col, int num)
{
	// 가로, 세로 찾기
	for (int i = 1; i <= MAX_WIDTH; i++)
		if (nSdoku[row][i] == num || nSdoku[i][col] == num)	 return false;

	// 박스 찾기
	int sX = col;
	int sY = row;

	while (sX % 3 != 1)	sX--;
	while (sY % 3 != 1)	sY--;

	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (nSdoku[sY+i][sX+j] == num)		return false;

	return true;
}

// 채워진 스도쿠를 출력하는 함수
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
	// 마지막 줄까지 했을 때 이상이 없으면 출력하고 프로세스 종료
	if (row > MAX_WIDTH)
	{
		printSdoku();
		exit(0);
	}

	// 빈칸이 아니면 다음 칸으로 이동한다
	if (nSdoku[row][col] != 0)
	{
		// 마지막 칸까지 가면 인덱스를 다음 줄 것으로 변경해주자.		
		if (col == MAX_WIDTH)	
			dfs(row + 1, 1);
		else
			dfs(row, col + 1);

		return;
	}

	// 해당 칸에 들어갈 수 있는 숫자를 찾자.
	for (int n = 1; n <= MAX_WIDTH; n++)
	{
		//if (nSdoku[row][col] != 0) continue;
		// 찾은 값을 넣어도 되는지 확인한다.
		if (isOk(row, col, n))
		{
			// 값을 넣고 다음 칸으로 간다.
			nSdoku[row][col] = n;

			if (col == MAX_WIDTH)
				dfs(row + 1, 1);
			else
				dfs(row, col + 1);

			// 이후 진행이 잘안됐으면 다시 돌아와서 칸을 비워놓자.
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