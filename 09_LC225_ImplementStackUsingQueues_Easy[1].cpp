// LeetCode 225 - Implement Stack using Queues (Easy)
// Approach: Two queues - new element pushed to q2, old elements moved on top, then swap
// push: O(n), pop/top/empty: O(1)
#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {
    }

    void push(int x) {
        q2.push(x);

        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }

    int pop() {
        int x = q1.front();
        q1.pop();
        return x;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};

int main() {
    MyStack myStack;
    myStack.push(1);
    myStack.push(2);
    cout << myStack.top() << endl;   // 2
    cout << myStack.pop() << endl;   // 2
    cout << myStack.empty() << endl; // 0 (false)
    return 0;
}
