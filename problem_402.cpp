#include "util.h"

class Solution {
public:
	string Demo() {
		return "demo";
	}

	string removeKdigits(string num, int k) {
		stack<char> stk;
		for (auto ch : num) {
			while(k > 0 && !stk.empty() && stk.top() > ch) {
				k--;
				stk.pop();
			}
			if (!(stk.empty() && ch == '0')) {
				stk.push(ch);
			}
		}
		while(k > 0 && !stk.empty()) {
			k--;
			stk.pop();
		}
		if (stk.empty()) {
			return "0";
		}
		string ans(stk.size(), '0');
		for (int i = stk.size() - 1; i >= 0; i--) {
			ans[i] = stk.top();
			stk.pop();
		}
		return ans;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	auto res = solution.removeKdigits("10200", 1);
	println(res);
	
	auto res1 = solution.removeKdigits("10", 2);
	println(res1);
	
	auto res2 = solution.removeKdigits("1432219", 3);
	println(res2);
	
	auto res3 = solution.removeKdigits("9", 1);
	println(res3);
	
	return 0;
}
