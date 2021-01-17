#include "util.h"

class Solution {
public:
	string Demo() {
		return "demo";
	}

	bool search(vector<int>& nums, int target) {
		if (nums.empty()) return false;
		return search(nums, 0, nums.size() - 1, target);
	}

	bool search(vector<int>& nums, int l, int r, int target) {
		if (l > r) return false;
		if (l == r) {
			return nums[l] == target;
		}

		if (nums[l] < nums[r]) {
			// binary search
			while (l <= r) {
				int mid = (l + r) / 2;
				if (nums[mid] == target) return true;
				if (nums[mid] < target) l = mid + 1;
				else r = mid - 1;
			}
		} else {
			int mid = (l + r) / 2;
			return search(nums, l, mid, target) || search(nums, mid+1, r, target);
		}

		return false;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	{
		vector<int> nums = {2, 5, 6, 0, 0, 1, 2};
		auto res = solution.search(nums, 2);
		println(res);
	}

	return 0;
}
