class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        int mx = INT_MIN;
        unordered_map<int, int> mp;

        int i = 0;

        for (int j = 0; j < n; j++) {
            mp[nums[j]]++;

            while (mp[nums[j]] > k) {
                mp[nums[i]]--;
                i++;
            }

            mx = max(mx, j - i + 1);
        }

        return mx;
    }
};
