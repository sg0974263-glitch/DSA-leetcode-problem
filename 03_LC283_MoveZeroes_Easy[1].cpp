// LeetCode 283 - Move Zeroes (Easy)
// Approach: Two pointers (in-place, non-zero elements shifted forward)
// Time: O(n), Space: O(1)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int j = 0;  // position for next non-zero element

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[j]);
                j++;
            }
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 1, 0, 3, 12};
    sol.moveZeroes(nums);
    for (int x : nums) cout << x << " ";  // 1 3 12 0 0
    cout << endl;
    return 0;
}
