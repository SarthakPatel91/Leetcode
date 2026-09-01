class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* curr = head;
        stack<int> st;

        int size = 0;
        vector<int> ans;
        while (curr) {
            ans.push_back(curr->val);
            curr = curr->next;
            size++;
        }

        for (int i = 0; i < size; i++) {
            while (!st.empty() && ans[st.top()] < ans[i]) {
                ans[st.top()] = ans[i];
                st.pop();
            }
            st.push(i);
        }

        while (!st.empty()) {
            ans[st.top()] = 0;
            st.pop();
        }

        return ans;
    }
};