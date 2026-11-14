/*
 * Problem 1281: Subtract the Product and Sum of Digits of an Integer
 * Approach: Visit each decimal digit using remainder and division.
 * Keep a running product and sum, then subtract the sum from the product.
 * Time: O(d), where d is the number of digits. Space: O(1).
 */
#include <iostream>
using namespace std;

class Solution {
public:
    int subtractProductAndSum(int n) {
        int product = 1;
        int sum = 0;

        do {
            int digit = n % 10;
            product *= digit;
            sum += digit;
            n /= 10;
        } while (n > 0);

        return product - sum;
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
    failures += !check(solution.subtractProductAndSum(234), 15, "LeetCode example 1");
    failures += !check(solution.subtractProductAndSum(4421), 21, "LeetCode example 2");
    failures += !check(solution.subtractProductAndSum(10), -1, "Zero digit");
    failures += !check(solution.subtractProductAndSum(7), 0, "Single digit");
    failures += !check(solution.subtractProductAndSum(0), 0, "Zero");
    return failures == 0 ? 0 : 1;
}
#endif
