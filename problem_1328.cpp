#include "util.h"

class Solution {
public:
	string Demo() {
		return "demo";
	}

	string breakPalindrome(string palindrome) {
		if (palindrome.size() <= 1) {
			return "";
		}
		
		int l = 0;
		int r = palindrome.size() - 1;
		while(l < r && palindrome[l] == 'a') {
			l++;
			r--;
		}
		if (l == r || l > r) {
			// aba || aaaa
			palindrome[palindrome.size()-1] = 'b';
		} else if (l < r) {
			// abccba
			palindrome[l] = 'a';
		}
		return palindrome;
    }
};

int main(int argc, char* argv[]) {
	Solution solution;
	string p = "aba";
	auto res = solution.breakPalindrome(p);
	println(res);
	
	string p2 = "abccba";
	auto res2 = solution.breakPalindrome(p2);
	println(res2);
	
	return 0;
}
