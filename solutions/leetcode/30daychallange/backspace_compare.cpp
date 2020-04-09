#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  string escapeCharacters(string s) {
    string result = "";

    for (char &c : s) {
      if (c == '#') {
        if (result.length() > 0) {
          result.pop_back();
        }
      } else {
        result.push_back(c);
      }
    }

    return result;
  }

  bool backspaceCompare(string S, string T) {
    string s = escapeCharacters(S);
    string t = escapeCharacters(T);

    return s == t;
  }
};

int main() {
  Solution s;
  cout << s.backspaceCompare("a#r", "r") << endl;

  return 0;
}