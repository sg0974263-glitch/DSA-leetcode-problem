// LeetCode 19 - Remove Nth Node From End of List (Medium)
// Approach: Fast & Slow pointers with a dummy head
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* slow = &dummy;
        ListNode* fast = &dummy;

        // Move fast pointer n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Move both pointers together
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // Delete the nth node from the end
        slow->next = slow->next->next;

        return dummy.next;
    }
};

int main() {
    // 1 -> 2 -> 3 -> 4 -> 5, n = 2
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution sol;
    ListNode* res = sol.removeNthFromEnd(head, 2);
    for (ListNode* p = res; p != nullptr; p = p->next)
        cout << p->val << " ";  // 1 2 3 5
    cout << endl;
    return 0;
}
