#include <iostream>
#include <vector>
#include <string>

using namespace std;

int isExisted(int nVal, vector<pair<int, int>> check)
{
	for (int i = 0; i < check.size(); i++)
	{
		pair<int, int> v = check.at(i);

		if (v.first == nVal) return i;
	}

	return -1;
}

int solution(int k, vector<int> score)
{
	//차이나는 값이 몇개인지 확인
	vector<pair<int, int>> check;
	int answer = score.size();
	int nCnt = 0;
	int nTemp = -1;
	int preVal = -1;

	for (int i = 1; i < score.size(); i++)
	{
		int pScore = score.at(i - 1);
		int nScore = score.at(i);

		int nVal = nScore - pScore;
		nVal = (nVal < 0) ? (nVal * -1) : nVal;

		if (nVal == preVal)
		{
			nCnt++;
		}
		else
		{
			int nIdx = isExisted(nVal, check);

			if (nIdx != -1)
			{
				check.at(nIdx).second += nCnt;
			}
			else
			{
				check.push_back(make_pair(nVal, 1));
			}

			preVal = nVal;
		}

	}

	for (int i = 0; i < check.size(); i++)
	{
		pair<int, int> p = check.at(i);

		if (p.second >= k) answer -= p.second;
	}

	return answer;
}

int main()
{
	int k = 3;
	vector<int> score;
	score.push_back(24);
	score.push_back(22);
	score.push_back(20);
	score.push_back(10);
	score.push_back(5);
	score.push_back(3);
	score.push_back(2);
	score.push_back(1);

	cout << solution(k, score);

	return 0;
}