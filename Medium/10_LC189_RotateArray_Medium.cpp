/*
 * Problem 189: Rotate Array
 * Approach: Reduce k to the array length, reverse the whole array, then
 * reverse the first k values and the remaining values to restore their order.
 * Time: O(n). Space: O(1).
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    void reverseRange(vector<int>& nums, int left, int right) {
        while (left < right) {
            int temporary = nums[left];
            nums[left] = nums[right];
            nums[right] = temporary;
            ++left;
            --right;
        }
    }

public:
    void rotate(vector<int>& nums, int k) {
        int length = static_cast<int>(nums.size());
        if (length == 0) return;
        k %= length;
        if (k == 0) return;

        reverseRange(nums, 0, length - 1);
        reverseRange(nums, 0, k - 1);
        reverseRange(nums, k, length - 1);
    }
};

#ifdef LOCAL_TEST
static bool check(const vector<int>& actual, const vector<int>& expected, const string& name) {
    cout << name << " expected [";
    for (size_t i = 0; i < expected.size(); ++i) {
        if (i) cout << ", ";
        cout << expected[i];
    }
    cout << "], actual [";
    for (size_t i = 0; i < actual.size(); ++i) {
        if (i) cout << ", ";
        cout << actual[i];
    }
    cout << "]\n";
    return actual == expected;
}

int main() {
    Solution solution;
    int failures = 0;

    vector<int> first{1, 2, 3, 4, 5, 6, 7};
    solution.rotate(first, 3);
    failures += !check(first, {5, 6, 7, 1, 2, 3, 4}, "LeetCode example 1");

    vector<int> second{-1, -100, 3, 99};
    solution.rotate(second, 2);
    failures += !check(second, {3, 99, -1, -100}, "LeetCode example 2");

    vector<int> empty;
    solution.rotate(empty, 5);
    failures += !check(empty, {}, "Empty array");

    vector<int> one{7};
    solution.rotate(one, 9);
    failures += !check(one, {7}, "Single value");

    vector<int> duplicates{2, 2, 2};
    solution.rotate(duplicates, 4);
    failures += !check(duplicates, {2, 2, 2}, "k larger than length");
    return failures == 0 ? 0 : 1;
}
#endif
