#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<string> sorted;
    map<string, vector<string>> grouped;

    for (auto &it : strs) {
      string sortedWord = it;
      sort(sortedWord.begin(), sortedWord.end());

      sorted.push_back(sortedWord);
    }

    for (int i = 0; i < sorted.size(); i++) {
      auto it = grouped.find(sorted[i]);

      if (it != grouped.end()) {
        it->second.push_back(strs[i]);
      } else {
        vector<string> anagram{strs[i]};
        grouped.insert(pair<string, vector<string>>(sorted[i], anagram));
      }
    }

    vector<vector<string>> anagrams{};

    for (auto it = grouped.begin(); it != grouped.end(); ++it) {
      anagrams.push_back(it->second);
    }

    return anagrams;
  }
};

int main() {
  vector<string> vec{"eat", "tea", "tan", "ate", "nat", "bat"};

  Solution s;
  auto anagrams = s.groupAnagrams(vec);

  for (auto &it : anagrams) {
    for (auto &i : it) {
      cout << i << " ";
    }
    cout << endl;
  }

  return 0;
}