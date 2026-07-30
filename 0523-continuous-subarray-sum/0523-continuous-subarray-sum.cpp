class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefix(n);
        prefix[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        unordered_map<int, int> mp;
        mp[0] = -1;

        for (int l = 0; l < n; l++) {
            int rem = prefix[l] % k;
            // if (rem < 0)
            //     rem = rem + k;
            if (mp.count(rem)) {
                if (l - mp[rem] >= 2)
                    return true;
            }

            else
                mp[rem] = l;
        }

        return false;
    }
};