#include <iostream>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	map<string, int> m;

	// 참가자목록을 맵에 넣는다.
	for (string name : participant)
	{
		auto it = m.find(name);

		if (it == m.end())
		{
			m.insert(make_pair(name, 1));
		}
		else
		{
			(it->second)++;
		}
	}

	// 완료자 명단을 순회하며 하나씩 찾아서 뺀다.
	// 참여자 > 완료자 즉, 완료자가 참여자의 부분집합이기 때문에 가능.(n > n-1)
	for (string name : completion)
	{
		auto it = m.find(name);

		if ((it->second) != 1)
			(it->second)--;
		else
			m.erase(it);
	}

	return m.begin()->first;
}

int main()
{
	return 0;
}