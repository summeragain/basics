#include <algorithm>
#include <iostream>
#include <vector>

class Solution {
public:
  int singleNumber(std::vector<int> &nums) {
    std::sort(nums.begin(), nums.end());

    const int size = nums.size() - 1;
    int result = nums[size];

    for (int i = 0; i < size; i += 2) {
      if (nums[i] != nums[i + 1]) {
        result = nums[i];
        break;
      }
    }

    return result;
  }
};

int main() {
  std::vector<int> vec{4, 2, 1, 2, 1};

  Solution s;
  std::cout << s.singleNumber(vec) << std::endl;

  return 0;
}