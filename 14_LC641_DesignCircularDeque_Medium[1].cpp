// LeetCode 641 - Design Circular Deque (Medium)
// Approach: Circular array with front/rear indices and count
// All operations: O(1)
#include <iostream>
#include <vector>
using namespace std;

class MyCircularDeque {
private:
    vector<int> arr;
    int front;
    int rear;
    int count;
    int capacity;

public:
    MyCircularDeque(int k) {
        capacity = k;
        arr.resize(k);

        front = 0;
        rear = -1;
        count = 0;
    }

    bool insertFront(int value) {
        if (isFull())
            return false;

        if (isEmpty()) {
            front = rear = 0;
        }
        else {
            front = (front - 1 + capacity) % capacity;
        }

        arr[front] = value;
        count++;

        return true;
    }

    bool insertLast(int value) {
        if (isFull())
            return false;

        if (isEmpty()) {
            front = rear = 0;
        }
        else {
            rear = (rear + 1) % capacity;
        }

        arr[rear] = value;
        count++;

        return true;
    }

    bool deleteFront() {
        if (isEmpty())
            return false;

        front = (front + 1) % capacity;
        count--;

        return true;
    }

    bool deleteLast() {
        if (isEmpty())
            return false;

        rear = (rear - 1 + capacity) % capacity;
        count--;

        return true;
    }

    int getFront() {
        if (isEmpty())
            return -1;

        return arr[front];
    }

    int getRear() {
        if (isEmpty())
            return -1;

        return arr[rear];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }
};

int main() {
    MyCircularDeque dq(3);
    cout << dq.insertLast(1) << endl;   // 1
    cout << dq.insertLast(2) << endl;   // 1
    cout << dq.insertFront(3) << endl;  // 1
    cout << dq.insertFront(4) << endl;  // 0 (full)
    cout << dq.getRear() << endl;       // 2
    cout << dq.isFull() << endl;        // 1
    cout << dq.deleteLast() << endl;    // 1
    cout << dq.insertFront(4) << endl;  // 1
    cout << dq.getFront() << endl;      // 4
    return 0;
}
