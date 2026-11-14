/*
 * Problem 26: Remove Duplicates from Sorted Array
 * Approach: Keep a write position for the next new value.
 * Scan once and copy a value only when it differs from the last kept value.
 * Time: O(n). Space: O(1) extra.
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int write = 1;
        for (int read = 1; read < static_cast<int>(nums.size()); ++read) {
            if (nums[read] != nums[write - 1]) {
                nums[write] = nums[read];
                ++write;
            }
        }
        return write;
    }
};

#ifdef LOCAL_TEST
static bool check(vector<int>& values, int length, const vector<int>& expected,
                  int expectedLength, const string& name) {
    vector<int> actual(values.begin(), values.begin() + length);
    cout << name << " expected length " << expectedLength << " values [";
    for (size_t i = 0; i < expected.size(); ++i) {
        if (i) cout << ", ";
        cout << expected[i];
    }
    cout << "], actual length " << length << " values [";
    for (int i = 0; i < length; ++i) {
        if (i) cout << ", ";
        cout << actual[i];
    }
    cout << "]\n";
    return length == expectedLength && actual == expected;
}

int main() {
    Solution solution;
    int failures = 0;

    vector<int> first{1, 1, 2};
    int firstLength = solution.removeDuplicates(first);
    failures += !check(first, firstLength, {1, 2}, 2, "LeetCode example 1");

    vector<int> second{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int secondLength = solution.removeDuplicates(second);
    failures += !check(second, secondLength, {0, 1, 2, 3, 4}, 5, "LeetCode example 2");

    vector<int> empty;
    int emptyLength = solution.removeDuplicates(empty);
    failures += !check(empty, emptyLength, {}, 0, "Empty input");

    vector<int> one{5};
    int oneLength = solution.removeDuplicates(one);
    failures += !check(one, oneLength, {5}, 1, "Single element");
    return failures == 0 ? 0 : 1;
}
#endif
