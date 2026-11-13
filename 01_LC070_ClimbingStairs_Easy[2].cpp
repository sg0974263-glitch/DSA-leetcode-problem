// LeetCode 70 - Climbing Stairs (Easy)
// Approach: Dynamic Programming / Iteration (Fibonacci pattern)
// Time: O(n), Space: O(1)
#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2)
            return n;

        int a = 1;  // ways to reach step n-2
        int b = 2;  // ways to reach step n-1

        for (int i = 3; i <= n; i++) {
            int c = a + b;
            a = b;
            b = c;
        }

        return b;
    }
};

int main() {
    Solution sol;
    cout << sol.climbStairs(2) << endl;  // 2
    cout << sol.climbStairs(3) << endl;  // 3
    cout << sol.climbStairs(5) << endl;  // 8
    return 0;
}
