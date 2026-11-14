/*
 * Problem 206: Reverse Linked List
 * Approach: Walk through the list while redirecting each node's next pointer
 * to the previous node. Keep the next node before changing the link.
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
    ListNode* reverseList(ListNode* head) {
        ListNode* previous = nullptr;
        ListNode* current = head;
        while (current != nullptr) {
            ListNode* nextNode = current->next;
            current->next = previous;
            previous = current;
            current = nextNode;
        }
        return previous;
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
    failures += !check(solution.reverseList(makeList({1, 2, 3, 4, 5})),
                       {5, 4, 3, 2, 1}, "LeetCode example");
    failures += !check(solution.reverseList(nullptr), {}, "Empty list");
    failures += !check(solution.reverseList(makeList({1})), {1}, "Single node");
    failures += !check(solution.reverseList(makeList({1, 1, 2})),
                       {2, 1, 1}, "Duplicate values");
    return failures == 0 ? 0 : 1;
}
#endif
