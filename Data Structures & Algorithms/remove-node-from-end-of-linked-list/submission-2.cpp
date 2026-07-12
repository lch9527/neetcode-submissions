/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head->next && n > 0){
            return nullptr;
        }
        ListNode* target = head;
        ListNode* end = head;
        int lg = n;

        while(lg > 0){
            end = end->next;
            lg--;
        }

                // If end is nullptr, remove the head node
        if (end == nullptr) {
            return head->next;
        }

        while(end -> next){
            target = target->next;
            end = end->next;
        }

        target->next = target->next->next;

        return head;
    }
};
