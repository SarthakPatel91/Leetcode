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
    struct compare {
        bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
    };
    
    ListNode* sortList(ListNode* head) {
        if (head == NULL)
            return NULL;

        priority_queue<ListNode*, vector<ListNode*>, compare> minheap;

        ListNode* temp = head;
        while (temp) {
            minheap.push(temp);
            temp = temp->next;
        }

        head = minheap.top();
        minheap.pop();
        temp = head;
        ListNode* curr;

        while (!minheap.empty()) {
            curr = minheap.top();
            minheap.pop();
            temp->next = curr;
            temp = temp->next;
        }
        temp->next = NULL;

        return head;
    }
};