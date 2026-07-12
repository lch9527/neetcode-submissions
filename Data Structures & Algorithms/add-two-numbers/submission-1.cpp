class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummy(0);
        ListNode* cur = &dummy;

        int carry = 0;

        while (l1 || l2 || carry) {
            int val = carry;

            if (l1) {
                val += l1->val;
                l1 = l1->next;
            }

            if (l2) {
                val += l2->val;
                l2 = l2->next;
            }

            carry = val / 10;
            int digit = val % 10;

            cur->next = new ListNode(digit);
            cur = cur->next;
        }

        return dummy.next;
    }
};