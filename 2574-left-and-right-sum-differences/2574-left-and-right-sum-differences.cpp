class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        int leftsum = 0;
        int rightsum = 0;

        int totalsum = 0;
        for (int i = 0; i < n; i++) {
            totalsum += nums[i];
        }
        for (int i = 0; i < n; i++) {

            if (i == 0) {
                int num = abs(totalsum - nums[0]);
                ans.push_back(num);
            } else if (i == n - 1) {
                int num = abs(totalsum - nums[n - 1]);
                ans.push_back(num);
            } else {
                leftsum += nums[i - 1];
                rightsum = totalsum - nums[i] - leftsum;
                int num = abs(leftsum - rightsum);
                ans.push_back(num);
            }
        }
        return ans;
    }
};