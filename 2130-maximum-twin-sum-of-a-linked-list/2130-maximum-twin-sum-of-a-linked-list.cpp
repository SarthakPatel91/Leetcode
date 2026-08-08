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
    int pairSum(ListNode* head) {
        ListNode* temp = head;
        int n = 0;

        while (temp) {
            n++;
            temp = temp->next;
        }
        int range = (n / 2) - 1;

        vector<int> nums;
        temp = head;
        while (temp) {
            nums.push_back(temp->val);
            temp = temp->next;
        }

        int mx = INT_MIN;
        for (int i = 0; i <= range; i++) {
            mx = max(mx, nums[i] + nums[n - 1 - i]);
        }

        return mx;
    }
};