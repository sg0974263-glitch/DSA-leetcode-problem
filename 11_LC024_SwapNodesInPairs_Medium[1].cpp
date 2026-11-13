// LeetCode 24 - Swap Nodes in Pairs (Medium)
// Approach: Dummy node + pointer manipulation to swap adjacent nodes
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
    ListNode* swapPairs(ListNode* head) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* prev = &dummy;

        while (prev->next != nullptr &&
               prev->next->next != nullptr) {

            ListNode* first = prev->next;
            ListNode* second = first->next;

            // Swap the nodes
            first->next = second->next;
            second->next = first;
            prev->next = second;

            // Move to the next pair
            prev = first;
        }

        return dummy.next;
    }
};

int main() {
    // 1 -> 2 -> 3 -> 4
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);

    Solution sol;
    ListNode* res = sol.swapPairs(head);
    for (ListNode* p = res; p != nullptr; p = p->next)
        cout << p->val << " ";  // 2 1 4 3
    cout << endl;
    return 0;
}
