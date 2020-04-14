#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string stringShift(string s, vector<vector<int>> &shift) {
    for (auto &it : shift) {
      auto direction = it[0];
      auto amount = it[1];
      auto pos = direction == 0 ? 0 : s.size() - amount;

      string substr = s.substr(pos, amount);
      s.replace(pos, amount, "");

      if (direction == 0) {
        s.append(substr);
      } else {
        s.insert(0, substr);
      }
    }
    return s;
  }
};

int main() {
  string str = "abcdefg";
  vector<vector<int>> vec{{1, 1}, {1, 1}, {0, 2}, {1, 3}};
  Solution s;

  cout << s.stringShift(str, vec) << endl;
  return 0;
}