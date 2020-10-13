#include <string.h>
#include <vector>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;
	int check[101];

	for (vector<int> v : commands) {
		memset(check, 0, sizeof(check));

		int start = v.at(0);
		int end = v.at(1);
		int order = v.at(2);

		for (int i = start - 1; i < end; i++) {
			int val = array.at(i);
			check[val]++;
		}

		int cnt = 0;

		for (int i = 1; i < 101; i++) {
			if (check[i] == 0) continue;
			else {
				check[i]--;
				cnt++;
				i--;

				if (cnt == order) {
					answer.push_back(i + 1);
					break;
				}
			}
		}
	}

	return answer;
}