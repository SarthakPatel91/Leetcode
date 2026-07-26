class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int num;

        if (nums[0] < 0 && nums[1] < 0 && nums[n - 1] > 0) {
            num = nums[0] * nums[1] * nums[n - 1];

            if (num < nums[n - 1] * nums[n - 2] * nums[n - 3])
                num = nums[n - 1] * nums[n - 2] * nums[n - 3];
        }

        return num;
    }
};