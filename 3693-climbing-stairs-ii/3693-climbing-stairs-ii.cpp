class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<long long> dp(n + 1, LLONG_MAX);
        dp[0] = 0;                      // starting point costs nothing

        for (int i = 1; i <= n; i++) {
            // come from 1 step back
            dp[i] = dp[i - 1] + costs[i - 1] + 1;

            // come from 2 steps back
            if (i >= 2)
                dp[i] = min(dp[i], dp[i - 2] + costs[i - 1] + 4);

            // come from 3 steps back
            if (i >= 3)
                dp[i] = min(dp[i], dp[i - 3] + costs[i - 1] + 9);
        }
        return dp[n];
    }
};