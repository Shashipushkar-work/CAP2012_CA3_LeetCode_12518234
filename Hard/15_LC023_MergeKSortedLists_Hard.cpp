
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, 
        decltype([](ListNode* a, ListNode* b) {
            return a->val > b->val;
        })> pq;

        for (auto list : lists) {
            if (list != NULL) {
                pq.push(list);
            }
        }

        ListNode dummy(0);
        ListNode* curr = &dummy;

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            curr->next = node;
            curr = curr->next;

            if (node->next != NULL) {
                pq.push(node->next);
            }
        }

        return dummy.next;
    }
};
