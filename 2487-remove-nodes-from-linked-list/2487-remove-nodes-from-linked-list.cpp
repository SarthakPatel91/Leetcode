class Solution {
public:
    ListNode* removeNodes(ListNode* head) {

        deque<ListNode*> dq;

        ListNode* curr = head;

        while (curr) {
            while (!dq.empty() && dq.back()->val < curr->val) {
                dq.pop_back();
            }
            dq.push_back(curr);
            curr = curr->next;
        }

        head = dq.front();
        dq.pop_front();
        curr = head;
        while (!dq.empty()) {
            curr->next = dq.front();
            curr = curr->next;
            dq.pop_front();
        }
        curr->next = NULL;

        return head;
    }
};