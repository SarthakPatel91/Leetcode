class Solution {
public:
    int n;
    int dp[100001][2];

    int solve(int i, vector<int>& prices, int hold, int fee) {
        if (i == n)
            return 0;

        if (dp[i][hold] != -1)
            return dp[i][hold];

        if (!hold) {
            return dp[i][hold] =
                       max(-prices[i] + solve(i + 1, prices, 1, fee),
                           solve(i + 1, prices, 0, fee));
        }

        return dp[i][hold] = max(prices[i] + solve(i + 1, prices, 0, fee)-fee,
                                 solve(i + 1, prices, 1, fee));
    }

    int maxProfit(vector<int>& prices, int fee) {
        n = prices.size();
        memset(dp, -1, sizeof(dp));

        return solve(0, prices, 0,fee);
    }
};