/*
 * Problem 92: Reverse Linked List II
 * Approach: Move to the node before the requested section, then repeatedly
 * take the next node and insert it at the front of that section.
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0, head);
        ListNode* beforeSection = &dummy;
        for (int position = 1; position < left; ++position) {
            beforeSection = beforeSection->next;
        }

        ListNode* sectionHead = beforeSection->next;
        for (int count = 0; count < right - left; ++count) {
            ListNode* nodeToMove = sectionHead->next;
            sectionHead->next = nodeToMove->next;
            nodeToMove->next = beforeSection->next;
            beforeSection->next = nodeToMove;
        }
        return dummy.next;
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
    failures += !check(solution.reverseBetween(makeList({1, 2, 3, 4, 5}), 2, 4),
                       {1, 4, 3, 2, 5}, "LeetCode example 1");
    failures += !check(solution.reverseBetween(makeList({5}), 1, 1),
                       {5}, "LeetCode example 2");
    failures += !check(solution.reverseBetween(makeList({1, 2, 3}), 1, 3),
                       {3, 2, 1}, "Reverse entire list");
    failures += !check(solution.reverseBetween(makeList({1, 2, 3}), 2, 2),
                       {1, 2, 3}, "Single-node section");
    return failures == 0 ? 0 : 1;
}
#endif
