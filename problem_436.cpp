#include "util.h"

class Solution {
public:
	vector<int> findRightInterval(vector<vector<int>>& intervals) {
		int n = intervals.size();
		vector<int> idx(n);
		for (int i = 0; i < n; i++) {
			idx[i] = i;
		}
		sort(idx.begin(), idx.end(), [&intervals](int i, int j) {
			return intervals[i][0] < intervals[j][0];
		});

		vector<int> res(n);
		for (int k = 0; k < n - 1; k++) {
			// find the idx[k]'s result for using binary search
			auto p = lower_bound(idx.begin()+k, idx.end(), idx[k], [&intervals](int i, int k) {
				return intervals[i][0] < intervals[k][1];
			});
			if (p == idx.end()) {
				res[idx[k]] = -1;
			} else {
				res[idx[k]] = *p;
			}
		}
		res[idx[n-1]] = -1;
		return res;
    }
};

int main(int argc, char* argv[]) {
	Solution solution;
	{
		vector<vector<int>> intervals = {{3, 4}, {2, 3}, {1, 2}};
		auto res = solution.findRightInterval(intervals);
		println(res);
	}
	{
	{
		vector<vector<int>> intervals = {{1, 1}, {3, 4}};
		auto res = solution.findRightInterval(intervals);
		println(res);
	}
		vector<vector<int>> intervals = {{1, 4}, {2, 3}, {3, 4}};
		auto res = solution.findRightInterval(intervals);
		println(res);
	}

	return 0;
}
