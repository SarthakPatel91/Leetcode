class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1;

        int prefix = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            prefix += nums[i];

            if (mp.count(prefix - k))
                ans = ans + mp[prefix-k];

            mp[prefix]++;
        }

        return ans;
    }
};
