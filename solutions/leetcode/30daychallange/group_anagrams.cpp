#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int hasGroup(vector<vector<string>> groups, string str) {
    for (int i = 0; i < groups.size(); i++) {
      auto group = groups[i];

      if (group.size() > 0 && group[0].size() == str.size()) {
        string sortedWord = group[0];
        sort(sortedWord.begin(), sortedWord.end());

        string itSortedWord = str;
        sort(itSortedWord.begin(), itSortedWord.end());

        if (sortedWord == itSortedWord) {
          return i;
        }
      }
    }

    return -1;
  }

  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    vector<vector<string>> anagrams{};

    for (auto &it : strs) {
      auto index = hasGroup(anagrams, it);

      if (index != -1) {
        anagrams[index].push_back(it);
      } else {
        vector<string> anagram{it};
        anagrams.push_back(anagram);
      }
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