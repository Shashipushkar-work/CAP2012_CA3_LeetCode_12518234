/*
 * Problem 20: Valid Parentheses
 * Approach: Store opening brackets in a vector used as a stack.
 * Each closing bracket must match the most recent opening bracket.
 * Time: O(n). Space: O(n) for the stack in the worst case.
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> openings;
        for (char character : s) {
            if (character == '(' || character == '[' || character == '{') {
                openings.push_back(character);
            } else {
                if (openings.empty()) return false;
                char lastOpening = openings.back();
                openings.pop_back();
                if ((character == ')' && lastOpening != '(') ||
                    (character == ']' && lastOpening != '[') ||
                    (character == '}' && lastOpening != '{')) {
                    return false;
                }
            }
        }
        return openings.empty();
    }
};

#ifdef LOCAL_TEST
static bool check(bool actual, bool expected, const string& name) {
    cout << name << " expected " << (expected ? "true" : "false")
         << ", actual " << (actual ? "true" : "false") << "\n";
    return actual == expected;
}

int main() {
    Solution solution;
    int failures = 0;
    failures += !check(solution.isValid("()"), true, "LeetCode example 1");
    failures += !check(solution.isValid("()[]{}"), true, "LeetCode example 2");
    failures += !check(solution.isValid("(]"), false, "LeetCode example 3");
    failures += !check(solution.isValid(""), true, "Empty string");
    failures += !check(solution.isValid("([)]"), false, "Wrong nesting");
    failures += !check(solution.isValid("{[]}"), true, "Nested brackets");
    return failures == 0 ? 0 : 1;
}
#endif
