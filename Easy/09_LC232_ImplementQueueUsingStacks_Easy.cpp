/*
 * Problem 232: Implement Queue using Stacks
 * Approach: Use two vectors as stacks. New values enter the input stack;
 * when output is empty, move values over to reverse their order.
 * Time: Amortized O(1) per operation. Space: O(n).
 */
#include <iostream>
#include <vector>
using namespace std;

class MyQueue {
private:
    vector<int> inputStack;
    vector<int> outputStack;

    void moveToOutputIfNeeded() {
        if (!outputStack.empty()) return;
        while (!inputStack.empty()) {
            outputStack.push_back(inputStack.back());
            inputStack.pop_back();
        }
    }

public:
    MyQueue() {}

    void push(int x) {
        inputStack.push_back(x);
    }

    int pop() {
        moveToOutputIfNeeded();
        int frontValue = outputStack.back();
        outputStack.pop_back();
        return frontValue;
    }

    int peek() {
        moveToOutputIfNeeded();
        return outputStack.back();
    }

    bool empty() {
        return inputStack.empty() && outputStack.empty();
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
    MyQueue queue;
    failures += !check(queue.empty(), true, "Initially empty");
    queue.push(1);
    queue.push(2);
    failures += !check(queue.peek(), 1, "LeetCode example: peek");
    failures += !check(queue.pop(), 1, "LeetCode example: pop");
    failures += !check(queue.empty(), false, "One item remains");
    queue.push(3);
    failures += !check(queue.pop(), 2, "FIFO order after push");
    failures += !check(queue.pop(), 3, "Last item");
    failures += !check(queue.empty(), true, "Empty after removals");

    MyQueue single;
    single.push(9);
    failures += !check(single.peek(), 9, "Single value peek");
    failures += !check(single.pop(), 9, "Single value pop");
    return failures == 0 ? 0 : 1;
}
#endif
