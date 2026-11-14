/*
 * Problem 155: Min Stack
 * Approach: Keep one vector for values and a second vector for the minimum
 * at each depth. The last minimum can be read or removed in constant time.
 * Time: O(1) per operation. Space: O(n).
 */
#include <iostream>
#include <vector>
using namespace std;

class MinStack {
private:
    vector<int> values;
    vector<int> minimums;

public:
    MinStack() {}

    void push(int val) {
        values.push_back(val);
        if (minimums.empty() || val <= minimums.back()) {
            minimums.push_back(val);
        }
    }

    void pop() {
        if (values.back() == minimums.back()) {
            minimums.pop_back();
        }
        values.pop_back();
    }

    int top() {
        return values.back();
    }

    int getMin() {
        return minimums.back();
    }
};

#ifdef LOCAL_TEST
static bool check(int actual, int expected, const string& name) {
    cout << name << " expected " << expected << ", actual " << actual << "\n";
    return actual == expected;
}

int main() {
    int failures = 0;
    MinStack stack;
    stack.push(-2);
    stack.push(0);
    stack.push(-3);
    failures += !check(stack.getMin(), -3, "LeetCode example: minimum");
    stack.pop();
    failures += !check(stack.top(), 0, "LeetCode example: top");
    failures += !check(stack.getMin(), -2, "Minimum after pop");

    MinStack duplicates;
    duplicates.push(2);
    duplicates.push(2);
    duplicates.push(3);
    failures += !check(duplicates.getMin(), 2, "Duplicate minimum");
    duplicates.pop();
    duplicates.pop();
    failures += !check(duplicates.getMin(), 2, "Minimum remains after equal pop");
    failures += !check(duplicates.top(), 2, "Top after pops");
    return failures == 0 ? 0 : 1;
}
#endif
