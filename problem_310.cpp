#include "util.h"

class Solution {
public:
	string Demo() {
		return "demo";
	}

	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
		vector<vector<int>> nodes(n);
		for (auto& edge : edges) {
			nodes[edge[0]].push_back(edge[1]);
			nodes[edge[1]].push_back(edge[0]);
		}

		// calculate the node height when root is 0
		vector<int> heights(n, 0);
		calculateTreeHeight(-1, 0, nodes, heights);

		// calculate tree height for each root
		vector<int> h2(n, 0);
	}

	void calculateTreeHeight(int p, int c, const vector<vector<int>>& nodes, vector<int>& heights) {
		int maxHeight = 0;
		for (int n : nodes[c]) {
			if (n == p) {
				continue;
			}
			calculateTreeHeight(c, n, nodes, heights);
			maxHeight = max(maxHeight, heights[n]);
		}
		heights[c] = maxHeight + 1;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	{
		auto res = solution.Demo();
		println(res);
	}

	return 0;
}
