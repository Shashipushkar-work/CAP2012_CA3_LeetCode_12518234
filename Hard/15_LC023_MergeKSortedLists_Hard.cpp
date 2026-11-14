/*
 * Problem 23: Merge k Sorted Lists
 * Approach: Merge lists in pairs, doubling the merge interval each round.
 * Each merge uses pointers to link existing nodes in sorted order.
 * Time: O(N log k), where N is the total number of nodes. Space: O(1) extra.
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
private:
    ListNode* mergeTwoLists(ListNode* first, ListNode* second) {
        ListNode dummy;
        ListNode* tail = &dummy;

        while (first != nullptr && second != nullptr) {
            if (first->val <= second->val) {
                tail->next = first;
                first = first->next;
            } else {
                tail->next = second;
                second = second->next;
            }
            tail = tail->next;
        }
        tail->next = (first != nullptr) ? first : second;
        return dummy.next;
    }

public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int listCount = static_cast<int>(lists.size());
        if (listCount == 0) return nullptr;

        for (int interval = 1; interval < listCount; interval *= 2) {
            for (int first = 0; first + interval < listCount; first += interval * 2) {
                lists[first] = mergeTwoLists(lists[first], lists[first + interval]);
            }
        }
        return lists[0];
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

    vector<ListNode*> example{
        makeList({1, 4, 5}), makeList({1, 3, 4}), makeList({2, 6})};
    failures += !check(solution.mergeKLists(example),
                       {1, 1, 2, 3, 4, 4, 5, 6}, "LeetCode example");

    vector<ListNode*> noLists;
    failures += !check(solution.mergeKLists(noLists), {}, "No lists");

    vector<ListNode*> emptyLists{nullptr, nullptr};
    failures += !check(solution.mergeKLists(emptyLists), {}, "Lists are empty");

    vector<ListNode*> oneList{makeList({-1, 0, 3})};
    failures += !check(solution.mergeKLists(oneList), {-1, 0, 3}, "One list");
    return failures == 0 ? 0 : 1;
}
#endif
