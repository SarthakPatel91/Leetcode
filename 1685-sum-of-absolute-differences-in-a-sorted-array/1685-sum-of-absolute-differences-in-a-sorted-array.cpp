class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefix(n);
        prefix[0] = nums[0];

        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + nums[i];

        int total = prefix[n - 1];
        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            int leftSum = (i == 0) ? 0 : prefix[i - 1];
            int rightSum = total - prefix[i];

            int left = nums[i] * i - leftSum;
            int right = rightSum - nums[i] * (n - i - 1);

            ans[i] = left + right;
        }

        return ans;
    }
};