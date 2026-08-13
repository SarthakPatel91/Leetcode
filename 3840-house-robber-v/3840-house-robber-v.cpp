class Solution {
public:
    long long dp[100001];
    long long solve(int i, vector<int>& nums, vector<int>& colors) {

        if (i >= nums.size())
            return 0;

        if (dp[i] != -1)
            return dp[i];

        // take
        long long take = 0;
        if (i + 1 < colors.size() && colors[i] == colors[i + 1])
            take = nums[i] + solve(i + 2, nums, colors);

        else {
            take = (long long)nums[i] + solve(i + 1, nums, colors);
        }

        // not take
        long long not_take = solve(i + 1, nums, colors);

        return dp[i] = max(take, not_take);
    }

    long long rob(vector<int>& nums, vector<int>& colors) {

        memset(dp, -1, sizeof(dp));
        return solve(0, nums, colors);
    }
};