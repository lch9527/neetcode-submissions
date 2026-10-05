class Solution {
public:
    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<
            ListNode*,
            vector<ListNode*>,
            Compare
        > minHeap;

        // Put the first node of every non-empty list into the heap
        for (ListNode* node : lists) {
            if (node) {
                minHeap.push(node);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!minHeap.empty()) {
            // Get the smallest current node
            ListNode* node = minHeap.top();
            minHeap.pop();

            // Attach it to the result
            tail->next = node;
            tail = tail->next;

            // Add the next node from the same linked list
            if (node->next) {
                minHeap.push(node->next);
            }
        }

        return dummy.next;
    }
};