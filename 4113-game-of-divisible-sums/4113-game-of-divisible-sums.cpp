class Solution {
public:
    typedef long long ll;
    long long maxDifference(vector<int>& nums) {
        int n = nums.size();
        vector<ll> dp(n+1);

        dp[0] = 0;
        dp[n - 1] = nums[n - 1];

        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] % 3 == 0) {
                dp[i] = nums[i] - dp[i + 1];
            } else
                dp[i] = nums[i] + dp[i+1];

            if ((nums[i] + nums[i + 1]) % 3 == 0) {
                dp[i] = max(dp[i], nums[i] + nums[i + 1] - dp[i + 2]);
            } else
                dp[i] = max(dp[i], nums[i] + nums[i + 1] + dp[i + 2]);
        }

        return dp[0];
    }
};