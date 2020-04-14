#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  string stringShift(string s, vector<vector<int>> &shift) {
    int counter = 0;

    for (auto &it : shift) {
      int direction = it[0];
      int amount = it[1];

      if (direction == 0) {
        counter -= amount;
      } else {
        counter += amount;
      }
    }

    counter = abs(counter) % s.size() * (counter > 0 ? 1 : -1);

    if (counter == 0) {
      return s;
    }

    int amount = abs(counter);
    int pos = counter > 0 ? s.size() - amount : 0;

    if (counter > 0) {
      return s.substr(pos, amount) + s.substr(0, pos);
    } else {
      return s.substr(amount) + s.substr(pos, amount);
    }
  }
};

int main() {
  string str = "abcdefg";
  vector<vector<int>> vec{{1, 1}, {1, 1}, {0, 2}, {1, 3}};
  Solution s;

  cout << s.stringShift(str, vec) << endl;
  return 0;
}