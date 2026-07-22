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
    ListNode* deleteMiddle(ListNode* head) {
        // if (head == NULL)
        //     return NULL;

        int size = 0;
        ListNode* curr = head;

        while (curr) {
            size++;
            curr = curr->next;
        }

        if (size <= 1)
            return NULL;

        int mid = size / 2;

        curr = head;

        int i = 0;
        while (i != mid - 1) {
            curr = curr->next;
            i++;
        }
        ListNode* temp = curr->next;
        temp = temp->next;
        curr->next = temp;

        return head;
    }
};