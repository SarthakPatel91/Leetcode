class Solution {
public:
    int dp[1001];
    int solve(int i, vector<int>& costs) {
        if (i >= costs.size()) {
            return 0;
        }

        if (dp[i] != -1)
            return dp[i];

        // take 1
        int take_1 = INT_MAX;
        take_1 = costs[i] + solve(i + 1, costs);

        int take_2 = INT_MAX;
        take_2 = costs[i] + solve(i + 2, costs);

        return dp[i] = min(take_1, take_2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        memset(dp, -1, sizeof(dp));

        return min(solve(0, cost), solve(1, cost));
    }
};