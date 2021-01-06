#include "util.h"

class Solution {
public:
	string Demo() {
		return "demo";
	}

	vector<vector<int>> threeSum(vector<int>& nums) {
		std::sort(nums.begin(), nums.end());
		vector<vector<int>> res;

		int n = nums.size();
		for (int k = 0; k < n; k++) {
			if (k > 0 && nums[k] == nums[k-1]) continue;

			int target = -nums[k];
			int i = k + 1;
			int j = n - 1;
			while(i < j) {
				if (nums[i] + nums[j] == target) {
					res.push_back({nums[k], nums[i], nums[j]});
					while(i < j && nums[i+1] == nums[i]) i++;
					while(i < j && nums[j-1] == nums[j]) j--;
					i++;
					j--;
				} else if (nums[i] + nums[j] > target) {
					j--;
				} else {
					i++;
				}
			}
		}
		return res;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	{
		vector<int> nums = {-1, -1,0, 1, 2, -1, -4};
		auto res = solution.threeSum(nums);
		println(res);
	}

	return 0;
}
