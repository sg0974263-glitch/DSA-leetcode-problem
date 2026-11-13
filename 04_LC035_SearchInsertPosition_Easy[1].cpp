// LeetCode 35 - Search Insert Position (Easy)
// Approach: Binary Search O(log n)
// Time: O(log n), Space: O(1)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return low;  // insertion position
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 5, 6};
    cout << sol.searchInsert(nums, 5) << endl;  // 2
    cout << sol.searchInsert(nums, 2) << endl;  // 1
    cout << sol.searchInsert(nums, 7) << endl;  // 4
    return 0;
}
