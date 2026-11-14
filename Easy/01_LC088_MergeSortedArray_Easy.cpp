/*
 * Problem 88: Merge Sorted Array
 * Approach: Fill nums1 from the back so its existing values are not overwritten.
 * Compare the largest remaining values and place the larger one at the end.
 * Time: O(m + n). Space: O(1) extra.
 */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int first = m - 1;
        int second = n - 1;
        int write = m + n - 1;

        while (second >= 0) {
            if (first >= 0 && nums1[first] > nums2[second]) {
                nums1[write] = nums1[first];
                --first;
            } else {
                nums1[write] = nums2[second];
                --second;
            }
            --write;
        }
    }
};

#ifdef LOCAL_TEST
static void printVector(const vector<int>& values) {
    cout << "[";
    for (size_t i = 0; i < values.size(); ++i) {
        if (i > 0) cout << ", ";
        cout << values[i];
    }
    cout << "]";
}

static bool check(vector<int> actual, const vector<int>& expected, const string& name) {
    cout << name << " expected ";
    printVector(expected);
    cout << ", actual ";
    printVector(actual);
    cout << "\n";
    return actual == expected;
}

int main() {
    Solution solution;
    int failures = 0;

    vector<int> first1{1, 2, 3, 0, 0, 0};
    vector<int> second1{2, 5, 6};
    solution.merge(first1, 3, second1, 3);
    failures += !check(first1, {1, 2, 2, 3, 5, 6}, "LeetCode example");

    vector<int> first2{1};
    vector<int> second2;
    solution.merge(first2, 1, second2, 0);
    failures += !check(first2, {1}, "No second values");

    vector<int> first3{0};
    vector<int> second3{1};
    solution.merge(first3, 0, second3, 1);
    failures += !check(first3, {1}, "Empty first values");

    vector<int> first4{2, 2, 0, 0};
    vector<int> second4{2, 3};
    solution.merge(first4, 2, second4, 2);
    failures += !check(first4, {2, 2, 2, 3}, "Duplicates");

    return failures == 0 ? 0 : 1;
}
#endif
