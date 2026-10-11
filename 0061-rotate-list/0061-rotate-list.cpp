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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL || head->next == NULL || k == 0)
            return head;

        // Find length and tail
        int len = 1;
        ListNode* tail = head;

        while (tail->next != NULL) {
            tail = tail->next;
            len++;
        }

        // Reduce unnecessary rotations
        k = k % len;

        if (k == 0)
            return head;

        // Connect tail to head to form a circle
        tail->next = head;

        // Find the new tail
        int steps = len - k;
        ListNode* newTail = head;

        for (int i = 1; i < steps; i++) {
            newTail = newTail->next;
        }

        // Break the circle
        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
};

