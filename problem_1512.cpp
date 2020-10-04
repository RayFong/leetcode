#include "util.h"

class Solution {
public:
	void Demo() {
		cout << "demo" << endl;
	}

	int numIdenticalPairs(vector<int>& nums) {
		std::sort(nums.begin(), nums.end());
		int prev = nums[0];
		int cnt = 0;
		int ans = 0;
		for (auto n : nums) {
			if (n != prev) {
				ans += cnt * (cnt-1) / 2;
				cnt=0;
				prev=n;
			}
			cnt++;
		}
		return ans + cnt*(cnt-1)/2;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	vector<int> nums = {1, 2, 3, 1, 1, 3};
	cout << solution.numIdenticalPairs(nums) << endl;	
	return 0;
}
