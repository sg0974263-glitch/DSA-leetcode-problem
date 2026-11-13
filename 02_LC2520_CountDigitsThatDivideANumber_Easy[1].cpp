// LeetCode 2520 - Count the Digits That Divide a Number (Easy)
// Approach: Loop + modulo operator
// Time: O(log10(num)), Space: O(1)
#include <iostream>
using namespace std;

class Solution {
public:
    int countDigits(int num) {
        int temp = num;
        int count = 0;

        while (temp > 0) {
            int digit = temp % 10;

            if (digit != 0 && num % digit == 0) {
                count++;
            }

            temp = temp / 10;
        }

        return count;
    }
};

int main() {
    Solution sol;
    cout << sol.countDigits(7) << endl;     // 1
    cout << sol.countDigits(121) << endl;   // 2
    cout << sol.countDigits(1248) << endl;  // 4
    return 0;
}
