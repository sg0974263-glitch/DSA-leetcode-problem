// LeetCode 1047 - Remove All Adjacent Duplicates In String (Easy)
// Approach: String used as a Stack (push/pop via back/pop_back)
// Time: O(n), Space: O(n)
#include <iostream>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";  // acts as a stack

        for (int i = 0; i < s.length(); i++) {
            if (!ans.empty() && ans.back() == s[i]) {
                ans.pop_back();  // duplicate found, remove it
            }
            else {
                ans.push_back(s[i]);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;
    cout << sol.removeDuplicates("abbaca") << endl;  // ca
    cout << sol.removeDuplicates("azxxzy") << endl;  // ay
    return 0;
}
