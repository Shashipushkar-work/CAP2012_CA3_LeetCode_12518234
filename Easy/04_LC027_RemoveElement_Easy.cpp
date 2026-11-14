/*
 * Problem 27: Remove Element
 * Approach: Copy each value that is not equal to val into the next write slot.
 * The first returned-length values are the elements that remain.
 * Time: O(n). Space: O(1) extra.
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int write = 0;
        for (int read = 0; read < static_cast<int>(nums.size()); ++read) {
            if (nums[read] != val) {
                nums[write] = nums[read];
                ++write;
            }
        }
        return write;
    }
};

#ifdef LOCAL_TEST
static bool check(vector<int>& values, int length, const vector<int>& expected,
                  const string& name) {
    vector<int> actual(values.begin(), values.begin() + length);
    cout << name << " expected length " << expected.size() << " values [";
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
    return actual == expected;
}

int main() {
    Solution solution;
    int failures = 0;

    vector<int> first{3, 2, 2, 3};
    int firstLength = solution.removeElement(first, 3);
    failures += !check(first, firstLength, {2, 2}, "LeetCode example 1");

    vector<int> second{0, 1, 2, 2, 3, 0, 4, 2};
    int secondLength = solution.removeElement(second, 2);
    failures += !check(second, secondLength, {0, 1, 3, 0, 4}, "LeetCode example 2");

    vector<int> empty;
    int emptyLength = solution.removeElement(empty, 1);
    failures += !check(empty, emptyLength, {}, "Empty input");

    vector<int> allRemoved{4, 4, 4};
    int removedLength = solution.removeElement(allRemoved, 4);
    failures += !check(allRemoved, removedLength, {}, "All values removed");
    return failures == 0 ? 0 : 1;
}
#endif
