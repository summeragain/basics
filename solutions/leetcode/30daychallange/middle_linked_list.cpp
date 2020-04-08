#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *middleNode(ListNode *head) {
    ListNode *slow = head;
    ListNode *fast = head;

    while (fast != NULL && fast->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;
    }

    return slow;
  }
};

int main() {
  ListNode head = 1;
  ListNode second = 2;
  head.next = &second;

  Solution s;
  ListNode *middle = s.middleNode(&head);

  return 0;
}