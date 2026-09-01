class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        vector<int> ans(nums1.size(),-1);

        int m = nums1.size();
        int n = nums2.size();

        for (int i = 0; i < nums2.size(); i++) {
            mp[nums2[i]] = i;
        }

        for (int i = 0; i < m; i++) {
            int idx = mp[nums1[i]];
            for (int j = idx + 1; j < n; j++) {
                if (nums2[j] > nums1[i]) {
                    ans[i]=nums2[j];
                    break;
                }
            }
        }

        return ans;
    }
};
