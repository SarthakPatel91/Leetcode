class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();

        vector<long long> prefix(n);
        prefix[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        long long total = prefix[n - 1];
        int target = total % p;

        if (target == 0)
            return 0;

        unordered_map<int, int> mp;
        mp[0] = -1;

        int ans = n;

        for (int i = 0; i < n; i++) {
            int rem = prefix[i] % p;

            int need = (rem - target + p) % p;

            if (mp.count(need)) {
                ans = min(ans, i - mp[need]);
            }

            mp[rem] = i;
        }

        return ans == n ? -1 : ans;
    }
};