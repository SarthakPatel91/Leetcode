class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> prefix(n);
        prefix[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        int ans = 0;

        // brute force

        // for (int l = 0; l < n; l++) {
        //     for (int r = l; r < n; r++) {
        //         int sum;
        //         if (l == 0)
        //             sum = prefix[r];

        //         else
        //             sum = prefix[r] - prefix[l - 1];

        //         if (sum % k == 0)
        //             ans++;
        //     }
        // }

        // return ans;

        // optimized

        unordered_map<int, int> mp;
        mp[0] = 1;

        for (int i = 0; i < n; i++) {
            int rem = prefix[i] % k;

            if (rem < 0)
                rem = rem + k;

            if(mp.count(rem))
            ans=ans+mp[rem];

            mp[rem]++;
        }

        return ans;
    }
};