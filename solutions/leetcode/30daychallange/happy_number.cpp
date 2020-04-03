#include <cmath>
#include <iostream>
#include <set>

class Solution {
public:
  bool isHappy(int n) {
    std::set<int> results;

    while (n != 1 && !(results.find(n) != results.end())) {
      results.insert(n);
      n = squared(n);
    }

    return n == 1;
  }

  int squared(int n) {
    if (n < 10) {
      return pow(n % 10, 2);
    }
    return pow(n % 10, 2) + squared(n / 10);
  }
};

int main() {
  Solution s;
  std::cout << s.isHappy(198) << std::endl;

  return 0;
}