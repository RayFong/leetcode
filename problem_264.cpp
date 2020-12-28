#include "util.h"

class Solution {
public:
	string Demo() {
		return "demo";
	}

	int nthUglyNumber(int n) {
		vector<int> nums(n, 1);
		vector<int> ptr(3, 0);
		vector<int> factor = {2, 3, 5};
		int minVal;
		for (int i = 1; i < n; i++) {
			for (int j = 0; j < ptr.size(); j++) {
				while (nums[ptr[j]] * factor[j] <= nums[i-1]) ptr[j]++;
			}

			minVal = nums[ptr[0]] * factor[0];
			for (int j = 1; j < ptr.size(); j++) {
				auto tmp = nums[ptr[j]] * factor[j];
				if (tmp < minVal) {
					minVal = tmp;
				}
			}
			nums[i] = minVal;
		}
		println(nums);
		return nums.back();
    }
};

int main(int argc, char* argv[]) {
	Solution solution;
	auto res = solution.nthUglyNumber(10);
	println(res);
	
	return 0;
}
