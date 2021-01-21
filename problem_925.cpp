#include "util.h"

class Solution {
public:
	string Demo() {
		return "demo";
	}

	bool isLongPressedName(string name, string typed) {
		size_t n = 0, t = 0;
		while(n < name.size() && t < typed.size()) {
			if (name[n] == typed[t]) {
				n++;
				t++;
			} else if (t > 0 && typed[t] == typed[t-1]) {
				t++;
			} else {
				return false;
			}
		}

		if (n != name.size()) return false;
		while(t < typed.size()) {
			if (t > 0 && typed[t] == typed[t-1]) t++;
			else return false;
		}
		return true;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	{
		string name = "leelee";
		string typed = "lleeeelee";
		auto res = solution.isLongPressedName(name, typed);
		println(res);
	}
	{
		string name = "saeed";
		string typed = "ssaaedd";
		auto res = solution.isLongPressedName(name, typed);
		println(res);
	}
	{
		string name = "saeed";
		string typed = "aaeedd";
		auto res = solution.isLongPressedName(name, typed);
		println(res);
	}

	return 0;
}
