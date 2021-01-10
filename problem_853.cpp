#include "util.h"

class Solution {
public:
	string Demo() {
		return "demo";
	}

	int carFleet(int target, vector<int>& position, vector<int>& speed) {
		if (position.empty()) return 0;

		vector<pair<int, double>> left(position.size());
		for (size_t i = 0; i < position.size(); i++) {
			left[i] = make_pair(position[i], double(target - position[i]) / speed[i]);
		}
		sort(left.begin(), left.end(), [](const pair<int, double>& p1, const pair<int, double>& p2) {
			return p1.first > p2.first;
		});

		int cnt = 1;
		int first = 0;
		for (size_t i = 1; i < left.size(); i++) {
			if (left[i].second <= left[first].second) {
				continue;
			}
			cnt++;
			first = i;
		}
		return cnt;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	{
		vector<int> position = {10, 8, 0, 5, 3};
		vector<int> speed = {2, 4, 1, 1, 3};
		auto res = solution.carFleet(12, position, speed);
		println(res);
	}

	return 0;
}
