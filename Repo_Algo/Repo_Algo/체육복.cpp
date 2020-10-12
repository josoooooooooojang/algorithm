#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	vector<int> none;
	int val[3] = { 0, -1, 1 };

	for (int loss : lost) {
		int i = 0;

		for (; i < 3; i++) {
			auto it = find(reserve.begin(), reserve.end(), loss + val[i]);

			if (it != reserve.end()) {
				if (i == 2) {
					if (find(lost.begin(), lost.end(), loss + val[i]) != lost.end())
						continue;
				}
				reserve.erase(it);
				break;
			}
		}

		if (i == 3)
			none.push_back(loss);
	}

	return n - none.size();
}