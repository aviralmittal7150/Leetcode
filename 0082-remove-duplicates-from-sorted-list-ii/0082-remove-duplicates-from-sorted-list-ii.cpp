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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        while (curr != nullptr) {
            // Check whether the current value is duplicated
            if (curr->next != nullptr &&
                curr->val == curr->next->val) {

                // Skip all nodes with this duplicate value
                while (curr->next != nullptr &&
                       curr->val == curr->next->val) {
                    curr = curr->next;
                }

                prev->next = curr->next;
            } else {
                prev = curr;
            }

            curr = curr->next;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};