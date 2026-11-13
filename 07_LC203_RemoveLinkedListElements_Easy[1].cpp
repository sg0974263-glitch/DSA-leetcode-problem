// LeetCode 203 - Remove Linked List Elements (Easy)
// Approach: Dummy node + traversal with pointer skipping
// Time: O(n), Space: O(1)
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* curr = &dummy;

        while (curr->next != nullptr) {
            if (curr->next->val == val) {
                curr->next = curr->next->next;  // skip the node
            }
            else {
                curr = curr->next;
            }
        }

        return dummy.next;
    }
};

int main() {
    // 1 -> 2 -> 6 -> 3 -> 4 -> 5 -> 6, val = 6
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(6);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(4);
    head->next->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next->next = new ListNode(6);

    Solution sol;
    ListNode* res = sol.removeElements(head, 6);
    for (ListNode* p = res; p != nullptr; p = p->next)
        cout << p->val << " ";  // 1 2 3 4 5
    cout << endl;
    return 0;
}
