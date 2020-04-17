#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void dfs(vector<vector<char>> &grid, int i, int j) {
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) {
      return;
    }

    if (grid[i][j] == '0') {
      return;
    }

    grid[i][j] = '0';
    dfs(grid, i, j - 1);
    dfs(grid, i, j + 1);
    dfs(grid, i - 1, j);
    dfs(grid, i + 1, j);
  }

  int numIslands(vector<vector<char>> &grid) {
    int counter = 0;

    for (int i = 0; i < grid.size(); i++) {
      for (int j = 0; j < grid[0].size(); j++) {
        if (grid[i][j] == '1') {
          counter++;
          dfs(grid, i, j);
        }

        grid[i][j] = '0';
      }
    }

    return counter;
  }
};

int main() {
  vector<vector<char>> vec{{'1', '1', '0', '0', '0'},
                           {'1', '1', '0', '0', '0'},
                           {'0', '0', '1', '0', '0'},
                           {'0', '0', '0', '1', '1'}};

  Solution s;
  cout << s.numIslands(vec) << endl;
  return 0;
}