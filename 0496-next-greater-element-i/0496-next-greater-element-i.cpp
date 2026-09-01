class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> ans;

        int m = nums1.size();
        int n = nums2.size();

        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() < nums2[i]) {
                mp[st.top()] = nums2[i];
                st.pop();
            }

            st.push(nums2[i]);
        }

        for (int i = 0; i < m; i++) {
            if (mp.find(nums1[i]) != mp.end())
                ans.push_back(mp[nums1[i]]);

            else
                ans.push_back(-1);
        }

        return ans;
    }
};
