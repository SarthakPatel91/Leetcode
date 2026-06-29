class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(), nums.end(), greater<int>());

        long long sum = 0;
        int i = 0;
        while (k > 0) {
            if (mul > 0) {
                long long num = (long long)mul * (long long)nums[i];
                sum = sum + num;
            } else {
                sum = sum + nums[i];
            }
            k--;
            i++;
            mul--;
        }
        return sum;
    }
};