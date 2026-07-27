class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int firstmax = INT_MIN;
        int secondmax = INT_MIN;

        int n = nums.size();

        sort(nums.begin(), nums.end());

        firstmax = nums[n - 1] - 1;
        secondmax = nums[n - 2] - 1;

        return firstmax * secondmax;
    }
};