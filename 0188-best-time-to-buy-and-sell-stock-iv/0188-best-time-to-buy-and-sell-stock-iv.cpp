class Solution {
public:
    int n;
    int dp[1001][2][101];

    int solve(int i, vector<int>& prices, int hold, int transactions, int k) {
        if (i == n)
            return 0;

        if (dp[i][hold][transactions] != -1)
            return dp[i][hold][transactions];

        if (!hold) {
            if (transactions == k)
                return dp[i][hold][transactions] = 0;

            return dp[i][hold][transactions] = max(
                       -prices[i] + solve(i + 1, prices, 1, transactions, k),
                       solve(i + 1, prices, 0, transactions, k));
        }

        return dp[i][hold][transactions] =
                   max(prices[i] + solve(i + 1, prices, 0, transactions + 1, k),
                       solve(i + 1, prices, 1, transactions, k));
    }

    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        memset(dp, -1, sizeof(dp));

        return solve(0, prices, 0, 0, k);
    }
};