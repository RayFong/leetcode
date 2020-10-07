#include "util.h"

class Solution {
public:
	string Demo() {
		return "demo";
	}

	vector<int> asteroidCollision(vector<int>& asteroids) {
		vector<int> left;
		for (auto v : asteroids) {
			if (left.empty() || !(left.back() > 0 && v < 0)) {
				// 没有元素或之前元素没有右移或非左移
				left.push_back(v);
			} else {
				while (!left.empty() && left.back() > 0 && left.back() + v < 0) {
					left.pop_back();
				}

				if (left.empty() || left.back() < 0) {
					left.push_back(v);
				} else if (left.back() + v == 0) {
					left.pop_back();
				}
			}
		}
		return left;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	vector<int> asteroids = {-2, -2, 1, -2};
	printVector(solution.asteroidCollision(asteroids));
	
	return 0;
}
