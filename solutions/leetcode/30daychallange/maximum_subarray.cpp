#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int maxSubArray(std::vector<int> &nums) {
    int max = 0;
    int maxCurrent = 0;
    bool hasPositive = false;

    for (auto &it : nums) {
      maxCurrent = maxCurrent + it;

      if (maxCurrent < 0) {
        maxCurrent = 0;
      }
      if (max < maxCurrent) {
        max = maxCurrent;
      }

      if (it > 0) {
        hasPositive = true;
      }
    }

    if (!hasPositive) {
      auto maxElement = std::max_element(nums.begin(), nums.end());
      max = *maxElement;
    }

    return max;
  }
};

int main() {
  std::vector<int> vec{-2, 1, -3, 4, -1, 2, 1, -5};

  Solution s;
  std::cout << s.maxSubArray(vec) << std::endl;

  return 0;
}