#include "util.h"

class Solution {
public:
	string Demo() {
		return "demo";
	}

	int numJewelsInStones(string J, string S) {
		unordered_set<char> d;
		for(auto ch : J) d.insert(ch);
		return std::count_if(S.begin(), S.end(), [&d](char ch) {return d.find(ch) != d.end();});
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	cout << solution.numJewelsInStones("aZ", "abbzzZ") << endl;
	
	return 0;
}
