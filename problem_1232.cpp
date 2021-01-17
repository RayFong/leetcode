#include "util.h"

class Solution {
public:
	string Demo() {
		return "demo";
	}

	bool checkStraightLine(vector<vector<int>>& coordinates) {
		if (coordinates.size() <= 2) return true;
		long dx = coordinates[0][0] - coordinates[1][0];
		long dy = coordinates[0][1] - coordinates[1][1];

		for (size_t i = 2; i < coordinates.size(); i++) {
			long x = coordinates[0][0] - coordinates[i][0];
			long y = coordinates[0][1] - coordinates[i][1];
			if (dx * y != dy * x) {
				return false;
			}
		}
		return true;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	{
		vector<vector<int>> c = {{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}};
		auto res = solution.checkStraightLine(c);
		println(res);
	}

	return 0;
}
