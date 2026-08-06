class Solution {
public:
int dp[17];
    bool solve(int idx, vector<int>& nums, vector<int>& bucket, int target) {

        // All numbers are placed
        if (idx == nums.size())
            return true;

        for (int i = 0; i < bucket.size(); i++) {

            // Cannot put this number in this bucket
            if (bucket[i] + nums[idx] > target)
                continue;

            // Put number into bucket
            bucket[i] += nums[idx];

            if (solve(idx + 1, nums, bucket, target))
                return true;

            // Backtrack
            bucket[i] -= nums[idx];

            // Optimization
            if (bucket[i] == 0)
                break;
        }

        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {

        int total = 0;

        for (int x : nums)
            total += x;

        if (total % k != 0)
            return false;

        int target = total / k;

        sort(nums.rbegin(), nums.rend());

        if (nums[0] > target)
            return false;

        vector<int> bucket(k, 0);

        return solve(0, nums, bucket, target);
    }
};