#include "util.h"

class SolutionTimeout {
public:
	vector<int> cnts;
	int miss_match;
	int ceil;

	inline void add(int idx) {
		cnts[idx]++;
		if (cnts[idx] == 1) {
			miss_match++;
		} else if (cnts[idx] == ceil) {
			miss_match--;
		}
	}

	inline void remove(int idx) {
		if (cnts[idx] == ceil) {
			miss_match++;
		} else if (cnts[idx] == 1) {
			miss_match--;
		}

		cnts[idx]--;
	}

	int longestSubstring(string s, int k) {
		if (k <= 1) {
			return s.size();
		}

		cnts.resize(26);
		miss_match = 0;
		ceil = k;

		for (int l = int(s.size()); l >= k; l--) {
			std::fill(cnts.begin(), cnts.end(), 0);
			miss_match = 0;

			for (int j = 0; j < l - 1; j++) {
				add(s[j] - 'a');
			}

			for (int i = 0; i <= int(s.size()) - l; i++) {
				add(s[i+l-1] - 'a');
				if (miss_match == 0) {
					return l;
				}
				remove(s[i] - 'a');
			}
		}
		return 0;
	}
};

class Solution {
public:
	int maxLen = 0;

    int longestSubstring(string s, int k) {
		if (k <= 1) {
			return s.size();
		}
		cout << s << endl;

		unordered_map<char, int> cnts;
		for (auto ch : s) {
			cnts[ch]++;
		}

		size_t l = 0;
		for (size_t r = 0; r < s.size(); r++) {
			if (cnts[s[r]] < k) {
				if (r-l > maxLen) {
					int subLen = longestSubstring(s.substr(l, r-l), k);
					maxLen = max(maxLen, subLen);
				}
				l = r + 1;
			}
		}
		if (l == 0) {
			return s.size();
		}

		if (s.size() - l > maxLen) {
			int subLen = longestSubstring(s.substr(l, s.size()-l), k);
			return max(maxLen, subLen);
		}

		return maxLen;
    }
};

int main(int argc, char* argv[]) {
	Solution solution;
	cout << solution.longestSubstring("bbaaacbd", 3) << endl;
	
	return 0;
}
