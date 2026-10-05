class Solution {
public:
    int n;
    int dp[100001][2];

    int solve(int i, vector<int>& prices, int hold) {
        if (i >= n)
            return 0;

        if (dp[i][hold] != -1)
            return dp[i][hold];

        if (!hold) {
            return dp[i][hold] = max(-prices[i] + solve(i + 1, prices, 1),
                                     solve(i + 1, prices, 0));
        }

        return dp[i][hold] = max(prices[i] + solve(i + 2, prices, 0),
                                 solve(i + 1, prices, 1));
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();
        memset(dp, -1, sizeof(dp));

        return solve(0, prices, 0);
    }
};