/*
 * Problem 509: Fibonacci Number
 * Approach: Keep the two previous Fibonacci values and build the sequence
 * from index 2 through n. This avoids repeated recursive calculations.
 * Time: O(n). Space: O(1).
 */
#include <iostream>
using namespace std;

class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;

        int previous = 0;
        int current = 1;
        for (int index = 2; index <= n; ++index) {
            int next = previous + current;
            previous = current;
            current = next;
        }
        return current;
    }
};

#ifdef LOCAL_TEST
static bool check(int actual, int expected, const string& name) {
    cout << name << " expected " << expected << ", actual " << actual << "\n";
    return actual == expected;
}

int main() {
    Solution solution;
    int failures = 0;
    failures += !check(solution.fib(2), 1, "LeetCode example 1");
    failures += !check(solution.fib(3), 2, "LeetCode example 2");
    failures += !check(solution.fib(4), 3, "LeetCode example 3");
    failures += !check(solution.fib(0), 0, "Zero index");
    failures += !check(solution.fib(1), 1, "First index");
    failures += !check(solution.fib(10), 55, "Larger index");
    return failures == 0 ? 0 : 1;
}
#endif
