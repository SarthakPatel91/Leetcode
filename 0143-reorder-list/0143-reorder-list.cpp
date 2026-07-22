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
    void reorderList(ListNode* head) {
        if (head == NULL)
            return;
        vector<int> nums;

        ListNode* curr = head;

        while (curr) {
            nums.push_back(curr->val);
            curr = curr->next;
        }

        int i = 1;
        int j = nums.size() - 1;
        vector<int> temp;
        temp.push_back(nums[0]);

        while (i < j) {
            temp.push_back(nums[j--]);
            temp.push_back(nums[i++]);
        }
        if (i == j) {
            // temp.pop_back();
            temp.push_back(nums[i]);
        }
        curr = head->next;

        for (int i = 1; i < temp.size(); i++) {
            curr->val = temp[i];
            curr = curr->next;
        }
    }
};