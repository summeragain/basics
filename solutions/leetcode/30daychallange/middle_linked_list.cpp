#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  int getSize(ListNode *head) {
    int counter = 0;
    ListNode *node = head;

    while (node != NULL) {
      node = node->next;
      counter++;
    }

    return counter;
  }

  ListNode *middleNode(ListNode *head) {
    if (head == NULL) {
      return NULL;
    }

    int size = getSize(head);
    int counter = 0;
    ListNode *node = head;

    while (node != NULL && counter < size / 2) {
      node = node->next;
      counter++;
    }

    return node;
  }
};

int main() {
  ListNode head = 1;
  ListNode second = 2;
  head.next = &second;

  Solution s;
  s.middleNode(&head);

  return 0;
}