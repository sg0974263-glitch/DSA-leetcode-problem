// LeetCode 80 - Remove Duplicates from Sorted Array II (Medium)
// Approach: In-place overwrite, allow at most 2 copies (compare with nums[k-2])
// Time: O(n), Space: O(1)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0;  // next write position

        for (int i = 0; i < nums.size(); i++) {
            if (k < 2 || nums[i] != nums[k - 2]) {
                nums[k] = nums[i];
                k++;
            }
        }

        return k;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = sol.removeDuplicates(nums);
    cout << k << endl;  // 5
    for (int i = 0; i < k; i++) cout << nums[i] << " ";  // 1 1 2 2 3
    cout << endl;
    return 0;
}
