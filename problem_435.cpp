#include "util.h"

class Solution {
public:
	string Demo() {
		return "demo";
	}

	int eraseOverlapIntervals(vector<vector<int>>& intervals) {
		std::sort(intervals.begin(), intervals.end(), [](const vector<int>& v1, const vector<int>& v2) { return v1[1] < v2[1] || (v1[1] == v2[1] && v1[0] < v2[0]); });
		int cnt = 0;
		size_t prev = 0;
		for (size_t i = 1; i < intervals.size(); i++) {
			auto& v1 = intervals[prev];
			auto& v2 = intervals[i];
			if (v2[0] < v1[1]) {
				cnt++;
			} else {
				prev = i;
			}
		}
		return cnt;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	vector<vector<int>> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
	auto res = solution.eraseOverlapIntervals(intervals);
	println(res);
	
	return 0;
}
