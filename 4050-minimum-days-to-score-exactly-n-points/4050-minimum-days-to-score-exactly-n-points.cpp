class Solution {
public:
    int dp[100001];
    int solve(int n) {
        if (n == 0)
            return 0;

        if (dp[n] != -1)
            return dp[n];

        int ans = 2e5;

        for (int i = 1; i <= n; i++) {
            int x = i * (i + 1) / 2;

            if (x > n)
                break;

            int rem = n - x;
            if (rem == 0)
                ans = min(ans, i);
            else
                ans = min(ans, i + 1 + solve(rem));
        }
        return dp[n]=ans;
    }
    int minDays(int n) {
        memset(dp, -1, sizeof(dp));

        return solve(n);
    }
};