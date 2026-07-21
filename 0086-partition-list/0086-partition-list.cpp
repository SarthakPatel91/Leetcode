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
    ListNode* partition(ListNode* head, int x) {
        ListNode* curr = head;

        vector<int> ans;

        while (curr != NULL) {
            if (curr->val < x) {
                ans.push_back(curr->val);
            }
            curr = curr->next;
        }

        curr = head;

        while (curr != NULL) {
            if (curr->val >= x)
                ans.push_back(curr->val);

            curr = curr->next;
        }
        if (ans.empty())
            return NULL;

        ListNode* newnode = new ListNode(ans[0]);

        ListNode* temp = newnode;

        for (int i = 1; i < ans.size(); i++) {
            ListNode* node = new ListNode(ans[i]);
            newnode->next = node;
            newnode = newnode->next;
        }

        // node->next=NULL;

        return temp;
    }
};