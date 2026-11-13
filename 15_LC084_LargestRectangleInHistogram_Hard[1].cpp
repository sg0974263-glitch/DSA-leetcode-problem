// LeetCode 84 - Largest Rectangle in Histogram (Hard)
// Approach: Monotonic increasing stack (nearest smaller element on both sides)
// Time: O(n), Space: O(n)
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxArea = 0;
        int n = heights.size();

        for (int i = 0; i <= n; i++) {
            // Sentinel height 0 at i == n flushes remaining bars
            int curr = (i == n) ? 0 : heights[i];

            while (!st.empty() && heights[st.top()] > curr) {
                int h = heights[st.top()];
                st.pop();

                int width;

                if (st.empty()) {
                    width = i;
                }
                else {
                    width = i - st.top() - 1;
                }

                int area = h * width;

                maxArea = max(maxArea, area);
            }

            if (i < n) {
                st.push(i);
            }
        }

        return maxArea;
    }
};

int main() {
    Solution sol;
    vector<int> h = {2, 1, 5, 6, 2, 3};
    cout << sol.largestRectangleArea(h) << endl;  // 10
    vector<int> h2 = {2, 4};
    cout << sol.largestRectangleArea(h2) << endl;  // 4
    return 0;
}
