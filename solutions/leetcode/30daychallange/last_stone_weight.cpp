#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int lastStoneWeight(vector<int> &stones) {
    while (stones.size() > 1) {
      sort(stones.begin(), stones.end(), greater<int>());

      if (stones[0] == stones[1]) {
        stones.erase(stones.begin(), stones.begin() + 2);
      } else {
        stones[1] = stones[0] - stones[1];
        stones.erase(stones.begin());
      }
    }

    if (stones.size() == 1) {
      return stones[0];
    }

    return 0;
  }
};

int main() {
  vector<int> vec{2, 7, 4, 1, 8, 1};

  Solution s;
  cout << s.lastStoneWeight(vec) << endl;

  return 0;
}