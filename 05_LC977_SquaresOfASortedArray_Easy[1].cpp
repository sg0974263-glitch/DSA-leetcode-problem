// LeetCode 977 - Squares of a Sorted Array (Easy)
// Approach: Two pointers from both ends filling result backwards
// Time: O(n), Space: O(n)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);

        int left = 0;
        int right = n - 1;

        int index = n - 1;

        while (left <= right) {
            if (abs(nums[left]) > abs(nums[right])) {
                ans[index] = nums[left] * nums[left];
                left++;
            }
            else {
                ans[index] = nums[right] * nums[right];
                right--;
            }

            index--;
        }

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-4, -1, 0, 3, 10};
    vector<int> res = sol.sortedSquares(nums);
    for (int x : res) cout << x << " ";  // 0 1 9 16 100
    cout << endl;
    return 0;
}
