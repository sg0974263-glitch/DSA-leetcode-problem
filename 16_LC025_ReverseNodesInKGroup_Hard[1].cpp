// LeetCode 25 - Reverse Nodes in k-Group (Hard)
// Approach: Dummy node - find kth node, reverse the group in place, repeat
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* groupPrev = &dummy;

        while (true) {
            ListNode* kth = groupPrev;

            for (int i = 0; i < k && kth != nullptr; i++) {
                kth = kth->next;
            }
            if (kth == nullptr) {
                break;  // fewer than k nodes remain, leave as is
            }

            ListNode* groupNext = kth->next;

            // Reverse the group
            ListNode* prev = groupNext;
            ListNode* curr = groupPrev->next;

            while (curr != groupNext) {
                ListNode* temp = curr->next;

                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            ListNode* temp = groupPrev->next;  // old head of group

            groupPrev->next = kth;             // kth is the new head
            groupPrev = temp;                  // continue after the group
        }

        return dummy.next;
    }
};

int main() {
    // 1 -> 2 -> 3 -> 4 -> 5, k = 2
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    ListNode* res = sol.reverseKGroup(head, 2);
    for (ListNode* p = res; p != nullptr; p = p->next)
        cout << p->val << " ";  // 2 1 4 3 5
    cout << endl;
    return 0;
}
