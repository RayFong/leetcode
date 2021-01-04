#include "util.h"

class Solution {
public:
	string Demo() {
		return "demo";
	}

	vector<int> partitionLabels(string S) {
		vector<int> cnts(26, -1);
		for (auto ch : S) {
			cnts[ch - 'a']++;
		}

		int leftCnt = 0;
		int segLen = 0;
		vector<int> res;
		for (auto ch : S) {
			int idx = ch - 'a';
			segLen++;
			leftCnt += cnts[idx];
			cnts[idx] = -1;

			if (leftCnt == 0) {
				res.push_back(segLen);
				segLen = 0;
			}
		}
		return res;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	{
		auto res = solution.partitionLabels("ababcbacadefegdehijhklij");
		println(res);
	}
	{
		auto res = solution.partitionLabels("abcd");
		println(res);
	}

	return 0;
}
