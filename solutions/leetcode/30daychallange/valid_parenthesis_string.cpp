#include <iostream>
#include <string>

class Solution {
public:
  bool checkValidString(std::string s) {
    std::string chars;

    for (auto c : s) {
      if (c == ')') {
        if (chars.length() == 0) {
          return false;
        }

        if (chars.find_last_of('(') != std::string::npos) {
          chars.erase(chars.find_last_of('('), 1);
        } else if (chars.find_last_of('*') != std::string::npos) {
          chars.erase(chars.find_last_of('*'), 1);
        }
      } else {
        chars += c;
      }
    }

    int i = 0;
    while (chars.length() > 0 && i < chars.length()) {
      if (chars[i] == '(') {
        auto pos = chars.find('*', i);

        if (pos == std::string::npos) {
          return false;
        }

        chars.erase(i, 1);
        chars.erase(pos - 1, 1);
      } else {
        i++;
      }
    }

    return true;
  }
};

int main() {
  std::string str = "((*(";
  Solution s;
  std::cout << s.checkValidString(str) << std::endl;

  return 0;
}
