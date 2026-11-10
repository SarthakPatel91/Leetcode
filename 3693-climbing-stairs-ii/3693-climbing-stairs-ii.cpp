class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n + 1, LLONG_MAX);
        dp[n] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 3 && i + k <= n; k++) {
                dp[i] = min(dp[i], costs[i + k - 1] + (long long)k * k + dp[i + k]);
            }
        }
        return (int)dp[0];
    }
};