#include "util.h"

class Solution {
public:
	string Demo() {
		return "demo";
	}

	int evalRPN(vector<string>& tokens) {
		stack<long> stk;
		for (auto& token : tokens) {
			if (token == "+" || token == "-" || token == "*" || token == "/") {
				auto a2 = stk.top();
				stk.pop();
				auto a1 = stk.top();
				stk.pop();

				if (token == "+") {
					stk.push(a1+a2);
				} else if (token == "-") {
					stk.push(a1 - a2);
				} else if (token == "*") {
					stk.push(a1 * a2);
				} else {
					stk.push(a1 / a2);
				}
			} else {
				stk.push(atol(token.c_str()));
			}
		}
		return stk.top();
    }
};

int main(int argc, char* argv[]) {
	Solution solution;
    vector<string> tokens = {"3", "4", "-"};
	auto res = solution.evalRPN(tokens);
	println(res);
	
	return 0;
}
