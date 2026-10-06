class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* curr = head;
        ListNode* ans = head;
        ListNode* prev_group_end = nullptr;

        while (curr != nullptr) {
            ListNode* group_begin = curr;

            for (int i = 0; i < k - 1; i++) {
                curr = curr->next;

                if (curr == nullptr) {
                    return ans;
                }
            }

            ListNode* group_end = curr;
            ListNode* next_group = group_end->next;

            reverse(group_begin, group_end);

            if (prev_group_end == nullptr) {
                ans = group_end;
            } else {
                prev_group_end->next = group_end;
            }

            group_begin->next = next_group;

            prev_group_end = group_begin;
            curr = next_group;
        }

        return ans;
    }

    void reverse(ListNode* begin, ListNode* end) {
        ListNode* stop = end->next;

        ListNode* prev = stop;
        ListNode* curr = begin;

        while (curr != stop) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
    }
};