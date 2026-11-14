/*
 * Problem 83: Remove Duplicates from Sorted List
 * Approach: In a sorted list, duplicate values are adjacent.
 * Keep one node from each run and bypass any following node with the same value.
 * Time: O(n). Space: O(1).
 */
#include <iostream>
#include <vector>
using namespace std;

#ifdef LOCAL_TEST
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* nextNode) : val(x), next(nextNode) {}
};
#endif

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current = head;
        while (current != nullptr && current->next != nullptr) {
            if (current->val == current->next->val) {
                ListNode* duplicate = current->next;
                current->next = duplicate->next;
                delete duplicate;
            } else {
                current = current->next;
            }
        }
        return head;
    }
};

#ifdef LOCAL_TEST
static ListNode* makeList(const vector<int>& values) {
    ListNode dummy;
    ListNode* tail = &dummy;
    for (int value : values) {
        tail->next = new ListNode(value);
        tail = tail->next;
    }
    return dummy.next;
}

static vector<int> listValues(ListNode* head) {
    vector<int> values;
    while (head != nullptr) {
        values.push_back(head->val);
        head = head->next;
    }
    return values;
}

static void deleteList(ListNode* head) {
    while (head != nullptr) {
        ListNode* nextNode = head->next;
        delete head;
        head = nextNode;
    }
}

static bool check(ListNode* actual, const vector<int>& expected, const string& name) {
    vector<int> values = listValues(actual);
    cout << name << " expected [";
    for (size_t i = 0; i < expected.size(); ++i) {
        if (i) cout << ", ";
        cout << expected[i];
    }
    cout << "], actual [";
    for (size_t i = 0; i < values.size(); ++i) {
        if (i) cout << ", ";
        cout << values[i];
    }
    cout << "]\n";
    bool matches = values == expected;
    deleteList(actual);
    return matches;
}

int main() {
    Solution solution;
    int failures = 0;
    failures += !check(solution.deleteDuplicates(makeList({1, 1, 2})),
                       {1, 2}, "LeetCode example 1");
    failures += !check(solution.deleteDuplicates(makeList({1, 1, 2, 3, 3})),
                       {1, 2, 3}, "LeetCode example 2");
    failures += !check(solution.deleteDuplicates(nullptr), {}, "Empty list");
    failures += !check(solution.deleteDuplicates(makeList({4})), {4}, "Single node");
    failures += !check(solution.deleteDuplicates(makeList({2, 2, 2})),
                       {2}, "All nodes equal");
    return failures == 0 ? 0 : 1;
}
#endif
