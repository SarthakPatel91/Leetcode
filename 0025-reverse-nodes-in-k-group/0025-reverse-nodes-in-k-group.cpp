class Solution {
public:

    ListNode* reverseList(ListNode* head, int k) {

        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL && k != 0) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            k--;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {

        int size = 0;
        ListNode* curr = head;

        while (curr) {
            size++;
            curr = curr->next;
        }

        if (k > size)
            return head;

        ListNode* newhead = NULL;
        ListNode* prevtail = NULL;
        curr = head;

        while (size >= k) {

            ListNode* grouphead = curr;
            ListNode* nextGroup = curr;

            for (int i = 0; i < k; i++)
                nextGroup = nextGroup->next;

            ListNode* reversedHead = reverseList(grouphead, k);

            if (newhead == NULL)
                newhead = reversedHead;

            if (prevtail != NULL)
                prevtail->next = reversedHead;

            prevtail = grouphead;
            prevtail->next = nextGroup;

            curr = nextGroup;
            size -= k;
        }

        return newhead;
    }
};