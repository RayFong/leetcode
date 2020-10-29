#include "util.h"

// 简单dp
class Solution {
public:
	string Demo() {
		return "demo";
	}

	int numberOfArithmeticSlices(vector<int>& A) {
		if (A.size() <= 2) return 0;

		int prev = A[1] - A[0];
		int cnt = 2;
		int ans = 0;
		for (size_t i = 2; i < A.size(); i++) {
			if (A[i] - A[i-1] == prev) {
				cnt++;
			} else {
				ans += (cnt - 2) * (cnt - 1) / 2;
				cnt = 2;
				prev = A[i] - A[i-1];
			}
		}
		return ans + (cnt - 2) * (cnt - 1) / 2;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	vector<int> A = {1, 2, 3, 4};
	auto res = solution.numberOfArithmeticSlices(A);
	println(res);
	
	return 0;
}
