#include "util.h"

class Solution {
public:
	string Demo() {
		return "demo";
	}

	int minCut(string s) {
		vector<vector<bool>> isPar(s.size(), vector<bool>(s.size(), false));
		// 计算每个字串是否是回文子串
		for (size_t l = 1; l <= s.size(); l++) {
			for (size_t i = 0; i + l <= s.size(); i++) {
				auto j = i + l - 1;
				isPar[i][j] = (s[i] == s[j]) && (i+2 > j || isPar[i+1][j-1]);
			}
		}

		// 计算每个长度切割成全部回文子串需要的次数
		vector<int> dp(s.size(), s.size());
		for (size_t l = 0; l < s.size(); l++) {
			if (isPar[0][l]) {
				dp[l] = 0;
				continue;
			}

			for (size_t k = 0; k < l; k++) {
				if (isPar[k+1][l]) {
					dp[l] = min(dp[l], dp[k]+1);
				}
			}
		}

		return dp.back();
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	cout << solution.minCut("aaba") << endl;
	
	return 0;
}
