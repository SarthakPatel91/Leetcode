class Solution {
public:
    vector<vector<int>> dp;

    int solve(int l, int r, vector<int>& nums) {
        if (l + 1 == r)
            return 0;

        if (dp[l][r] != -1)
            return dp[l][r];

        int ans = 0;

        for (int k = l + 1; k < r; k++) {
            int coins = nums[l] * nums[k] * nums[r]
                      + solve(l, k, nums)
                      + solve(k, r, nums);

            ans = max(ans, coins);
        }

        return dp[l][r] = ans;
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        int n = nums.size();

        dp.assign(n, vector<int>(n, -1));

        return solve(0, n - 1, nums);
    }
};