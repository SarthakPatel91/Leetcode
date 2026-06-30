class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix(n);
        prefix[0] = nums[0];

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            int need;

            if (i == 0)
                need = target;

            else
                need = target + prefix[i - 1];

            auto it = lower_bound(prefix.begin() + i, prefix.end(), need);
            if (it != prefix.end()) {
                ans = min(ans, (int)(it - prefix.begin()) - i + 1);
            }
        }
        if (ans == INT_MAX)
            return 0;

        return ans;
    }
};