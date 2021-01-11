#include "util.h"

class Solution {
public:
	string Demo() {
		return "demo";
	}

	int findPoisonedDuration(vector<int>& timeSeries, int duration) {
		if (timeSeries.empty()) return 0;

		sort(timeSeries.begin(), timeSeries.end());
		int cnt = duration;
		for (size_t i = 1; i < timeSeries.size(); i++) {
			auto diff = timeSeries[i] - timeSeries[i-1];
			cnt += min(diff, duration);
		}
		return cnt;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	{
		vector<int> timeSeries = {1, 2};
		auto res = solution.findPoisonedDuration(timeSeries, 2);
		println(res);
	}
	{
		vector<int> timeSeries = {1, 4};
		auto res = solution.findPoisonedDuration(timeSeries, 2);
		println(res);
	}

	return 0;
}
