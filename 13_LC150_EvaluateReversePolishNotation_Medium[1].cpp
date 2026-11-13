// LeetCode 150 - Evaluate Reverse Polish Notation (Medium)
// Approach: Stack - push numbers, pop two operands on operators
// Time: O(n), Space: O(n)
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (int i = 0; i < tokens.size(); i++) {
            string s = tokens[i];

            if (s == "+" || s == "-" || s == "*" || s == "/") {
                int b = st.top();
                st.pop();

                int a = st.top();
                st.pop();

                if (s == "+")
                    st.push(a + b);

                else if (s == "-")
                    st.push(a - b);

                else if (s == "*")
                    st.push(a * b);

                else if (s == "/")
                    st.push(a / b);  // truncates toward zero in C++
            }
            else {
                st.push(stoi(s));
            }
        }

        return st.top();
    }
};

int main() {
    Solution sol;
    vector<string> t1 = {"2", "1", "+", "3", "*"};
    vector<string> t2 = {"4", "13", "5", "/", "+"};
    cout << sol.evalRPN(t1) << endl;  // 9
    cout << sol.evalRPN(t2) << endl;  // 6
    return 0;
}
