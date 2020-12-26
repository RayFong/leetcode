#include "util.h"

class Solution {
public:
	string Demo() {
		return "demo";
	}

	vector<int> nextGreaterElements(vector<int>& nums) {
		vector<int> res(nums.size(), -1);
		stack<int> stk;
		for (int n = nums.size() - 2; n >= 0; n--) {
			while(!stk.empty() && stk.top() <= nums[n]) stk.pop();
			stk.push(nums[n]);
		}
		for (int n = nums.size() - 1; n >= 0; n--) {
			while(!stk.empty() && stk.top() <= nums[n]) stk.pop();
			if (!stk.empty()) {
				res[n] = stk.top();
			}
			stk.push(nums[n]);
		}
		return res;
    }
};

int main(int argc, char* argv[]) {
	Solution solution;
	vector<int> nums = {1, 2, 1};
	auto res = solution.nextGreaterElements(nums);
	println(res);
	
	return 0;
}
