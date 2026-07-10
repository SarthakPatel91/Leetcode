class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return 0;
        sort(nums.begin(), nums.end());

        int maxi = INT_MIN;

        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] - nums[i] > maxi)
                maxi = nums[i + 1] - nums[i];
        }
        if(maxi==INT_MIN)
        return 0;

        return maxi;
    }
};