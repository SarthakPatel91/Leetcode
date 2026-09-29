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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        sort(nums.begin(), nums.end());

        ListNode* temp = head;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = head;
        ListNode* prev = dummy;

        dummy->next = head;

        while (curr) {
            while (binary_search(nums.begin(), nums.end(), curr->val)) {
                if (curr->next)
                    curr = curr->next;
                else {
                    prev->next = nullptr;
                    break;
                }
            }
            if (prev->next == nullptr)
                break;
            else {
                prev->next = curr;
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};