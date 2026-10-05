class Solution {
public:
    int n;
    int dp[100001][2][3];

    int solve(int i, vector<int>& prices, int hold, int transactions) {
        if (i == n)
            return 0;

        if (dp[i][hold][transactions] != -1)
            return dp[i][hold][transactions];

        if (!hold) {
            if (transactions == 2)
                return dp[i][hold][transactions] = 0;

            return dp[i][hold][transactions] = max(
                -prices[i] + solve(i + 1, prices, 1, transactions),
                solve(i + 1, prices, 0, transactions)
            );
        }

        return dp[i][hold][transactions] = max(
            prices[i] + solve(i + 1, prices, 0, transactions + 1),
            solve(i + 1, prices, 1, transactions)
        );
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();
        memset(dp, -1, sizeof(dp));

        return solve(0, prices, 0, 0);
    }
};