class Solution {
public:
typedef long long ll;
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;

        ll res = 0;
        int l = 0;
        ll sum = 0;

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
            sum += nums[i];

            while (mp[nums[i]] > 1) {
                mp[nums[l]]--;
                sum -= nums[l];

                if (mp[nums[l]] == 0)
                    mp.erase(nums[l]);

                l++;
            }

            if (i - l + 1 == k) {
                res = max(res, sum);

                mp[nums[l]]--;
                if (mp[nums[l]] == 0)
                    mp.erase(nums[l]);

                sum -= nums[l];
                l++;
            }
        }

        return res;
    }
};