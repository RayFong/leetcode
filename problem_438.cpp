#include "util.h"

class Solution {
public:
	string Demo() {
		return "demo";
	}

	vector<int> findAnagrams(string s, string p) {
		unordered_map<char, int> left;
		for (auto ch : p) {
			left[ch]++;
		}
		int m = p.size();

		vector<int> res;
		int l = 0;

		auto lF = [&]() {
			left[s[l]]++;
			m++;
			l++;
		};

		for (size_t r = 0; r < s.size(); r++) {
			if (left.find(s[r]) == left.end()) {
				// reset
				while (l < r) lF();
				l++;
			} else if (left[s[r]] == 0) {
				// overflow, move the l to next of the first `s[r]` position
				while (s[l] != s[r]) lF();
				l++;
			} else {
				left[s[r]]--;
				m--;
				if (m == 0) {
					// all is same, save the result
					res.push_back(l);
					
					// move the l to next pos
					lF();
				}
			}
		}
		return res;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	{
		auto res = solution.findAnagrams("abab", "ab");
		println(res);
	}
	{
		auto res = solution.findAnagrams("cbaebabacd", "abc");
		println(res);
	}

	return 0;
}
