#include "util.h"

class Solution {
public:
	string Demo() {
		return "demo";
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	auto res = solution.Demo();
	println(res);
	
	return 0;
}
