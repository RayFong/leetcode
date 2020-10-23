#include "util.h"

// 路径压缩

class Solution {
public:
	string Demo() {
		return "demo";
	}

	vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
		string q(64, '0');
		for (auto &it : queens) {
			q[it[0]*8 + it[1]] = '1';
		}
		

		int n = 8;
		vector<int> dx = {1, 1, 0, -1, -1, -1, 0, 1};
		vector<int> dy = {0, -1, -1, -1, 0, 1, 1, 1};
		vector<vector<int>> res;
		for (int k = 0; k < 8; k++) {
			int i = king[0] + dx[k];
			int j = king[1] + dy[k];
			while(i >=0 && i < n && j >= 0 && j < n) {
				if (q[i*8+j] == '1') {
					res.push_back({i, j});
					break;
				}
				i += dx[k];
				j += dy[k];
			}
		}
		return res;
	}
};

int main(int argc, char* argv[]) {
	Solution solution;
	
	vector<vector<int>> queens = {{0,1},{1,0}};
	vector<int> king = {0, 0};
	auto res = solution.queensAttacktheKing(queens, king);
	println(res);
	
	return 0;
}
