#include "util.h"

class Solution {
public:
	string Demo() {
		return "demo";
	}

	int countServers(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();

		vector<int> rows(n, 0);
		vector<int> cols(m, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				rows[i] += grid[i][j];
				cols[j] += grid[i][j];
			}
		}

		int servers = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (grid[i][j] == 1 && (rows[i] > 1 || cols[j] > 1)) {
					servers++;
				}
			}
		}
		return servers;
    }
};

int main(int argc, char* argv[]) {
	Solution solution;
	vector<vector<int>> grid = {{1, 0}, {1, 1}};
	cout << solution.countServers(grid) << endl;
	
	return 0;
}
