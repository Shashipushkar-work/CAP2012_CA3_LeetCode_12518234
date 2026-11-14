/*
 * Problem 61: Rotate List
 * Approach: Find the length and connect the tail to the head to form a ring.
 * Walk to the new tail, break the ring, and return the new head.
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 0) return head;

        int length = 1;
        ListNode* tail = head;
        while (tail->next != nullptr) {
            tail = tail->next;
            ++length;
        }

        int stepsToNewTail = length - (k % length);
        if (stepsToNewTail == length) return head;

        tail->next = head;
        ListNode* newTail = tail;
        while (stepsToNewTail > 0) {
            newTail = newTail->next;
            --stepsToNewTail;
        }
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;
        return newHead;
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
    failures += !check(solution.rotateRight(makeList({1, 2, 3, 4, 5}), 2),
                       {4, 5, 1, 2, 3}, "LeetCode example 1");
    failures += !check(solution.rotateRight(makeList({0, 1, 2}), 4),
                       {2, 0, 1}, "LeetCode example 2");
    failures += !check(solution.rotateRight(nullptr, 3), {}, "Empty list");
    failures += !check(solution.rotateRight(makeList({1}), 10), {1}, "Single node");
    failures += !check(solution.rotateRight(makeList({1, 2, 3}), 0),
                       {1, 2, 3}, "Zero rotations");
    return failures == 0 ? 0 : 1;
}
#endif
