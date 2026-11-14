/*
 * Problem 622: Design Circular Queue
 * Approach: Store values in a fixed-size vector and track the front index
 * and number of elements. Modulo arithmetic wraps indices to the start.
 * Time: O(1) per operation. Space: O(k).
 */
#include <iostream>
#include <vector>
using namespace std;

class MyCircularQueue {
private:
    vector<int> data;
    int frontIndex;
    int count;

public:
    MyCircularQueue(int k) : data(k), frontIndex(0), count(0) {}

    bool enQueue(int value) {
        if (isFull()) return false;
        int rearIndex = (frontIndex + count) % static_cast<int>(data.size());
        data[rearIndex] = value;
        ++count;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        frontIndex = (frontIndex + 1) % static_cast<int>(data.size());
        --count;
        return true;
    }

    int Front() {
        return isEmpty() ? -1 : data[frontIndex];
    }

    int Rear() {
        if (isEmpty()) return -1;
        int rearIndex = (frontIndex + count - 1) % static_cast<int>(data.size());
        return data[rearIndex];
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == static_cast<int>(data.size());
    }
};

#ifdef LOCAL_TEST
static bool check(bool actual, bool expected, const string& name) {
    cout << name << " expected " << (expected ? "true" : "false")
         << ", actual " << (actual ? "true" : "false") << "\n";
    return actual == expected;
}

static bool check(int actual, int expected, const string& name) {
    cout << name << " expected " << expected << ", actual " << actual << "\n";
    return actual == expected;
}

int main() {
    int failures = 0;
    MyCircularQueue queue(3);
    failures += !check(queue.enQueue(1), true, "LeetCode example: enqueue 1");
    failures += !check(queue.enQueue(2), true, "LeetCode example: enqueue 2");
    failures += !check(queue.enQueue(3), true, "LeetCode example: enqueue 3");
    failures += !check(queue.enQueue(4), false, "Reject when full");
    failures += !check(queue.Rear(), 3, "Rear when full");
    failures += !check(queue.isFull(), true, "Full state");
    failures += !check(queue.deQueue(), true, "Dequeue from full queue");
    failures += !check(queue.enQueue(4), true, "Wrap around and enqueue");
    failures += !check(queue.Rear(), 4, "Rear after wrap around");
    failures += !check(queue.Front(), 2, "Front after wrap around");

    MyCircularQueue one(1);
    failures += !check(one.isEmpty(), true, "Capacity one starts empty");
    failures += !check(one.Front(), -1, "Empty front");
    failures += !check(one.enQueue(8), true, "Capacity one enqueue");
    failures += !check(one.Rear(), 8, "Capacity one rear");
    failures += !check(one.deQueue(), true, "Capacity one dequeue");
    failures += !check(one.deQueue(), false, "Reject empty dequeue");
    return failures == 0 ? 0 : 1;
}
#endif
