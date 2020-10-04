#include "util.h"

class Solution {
public:
	void Demo() {
		cout << "demo" << endl;
	}

	int findKthLargest(vector<int>& nums, int k) {
		return quickSelect(nums, 0, nums.size()-1, nums.size()-k+1);
    }

	int quickSelect(vector<int>& nums, int l, int r, int k) {
		int tmp = nums[r];
		int i = l;
		for (int j = l; j < r; j++) {
			if (nums[j] <= tmp) {
				swap(nums[i++], nums[j]);
			}
		}
		swap(nums[i], nums[r]);
		if (i-l+1 == k) return tmp;
		if (i-l+1 < k) return quickSelect(nums, i+1, r, k-i+l-1);
		return quickSelect(nums, l, i-1, k);
	}
};

int main(int argc, char* argv[]) {
	Solution solution;

	vector<int> nums = {3, 2, 1, 5, 4, 6};
	int k = 2;

	std::cout << solution.findKthLargest(nums, k) << std::endl;
	
	return 0;
}
