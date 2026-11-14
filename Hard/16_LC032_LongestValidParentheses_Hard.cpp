/*
 * Problem 32: Longest Valid Parentheses
 * Approach: Keep indices in a vector used as a stack, with a base index
 * before the current valid region. A matched pair gives a candidate length.
 * Time: O(n). Space: O(n).
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        vector<int> indices;
        indices.push_back(-1);
        int longest = 0;

        for (int index = 0; index < static_cast<int>(s.size()); ++index) {
            if (s[index] == '(') {
                indices.push_back(index);
            } else {
                indices.pop_back();
                if (indices.empty()) {
                    indices.push_back(index);
                } else {
                    int currentLength = index - indices.back();
                    if (currentLength > longest) longest = currentLength;
                }
            }
        }
        return longest;
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
    failures += !check(solution.longestValidParentheses("(()"), 2, "LeetCode example 1");
    failures += !check(solution.longestValidParentheses(")()())"), 4, "LeetCode example 2");
    failures += !check(solution.longestValidParentheses(""), 0, "Empty string");
    failures += !check(solution.longestValidParentheses("()()"), 4, "Two adjacent pairs");
    failures += !check(solution.longestValidParentheses("((("), 0, "Only opening brackets");
    failures += !check(solution.longestValidParentheses("()(())"), 6, "Nested pairs");
    return failures == 0 ? 0 : 1;
}
#endif
