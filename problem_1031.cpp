#include "util.h"

class Solution {
public:
	string Demo() {
		return "demo";
	}

	int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
		for (size_t i = 1; i < A.size(); i++) {
			A[i] += A[i-1];
		}

		int res = A[L+M-1];
		int l = A[L-1], r = A[M-1];
		for (size_t i = L+M; i < A.size(); i++) {
			l = max(l, A[i-M] - A[i-L-M]);
			r = max(r, A[i-L] - A[i-L-M]);
			res = max(res, max(l + A[i] - A[i-M], r + A[i] - A[i-L]));
		}
		return res;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	{
		vector<int> A = {0,6,5,2,2,5,1,9,4};
		auto res = solution.maxSumTwoNoOverlap(A, 1, 2);
		println(res);
	}

	return 0;
}
