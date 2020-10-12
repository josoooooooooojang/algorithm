#include <iostream>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
	map<string, int> m;

	// �����ڸ���� �ʿ� �ִ´�.
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

	// �Ϸ��� ����� ��ȸ�ϸ� �ϳ��� ã�Ƽ� ����.
	// ������ > �Ϸ��� ��, �Ϸ��ڰ� �������� �κ������̱� ������ ����.(n > n-1)
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