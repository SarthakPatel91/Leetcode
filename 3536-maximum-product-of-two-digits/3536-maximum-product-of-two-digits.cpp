class Solution {
public:
    int maxProduct(int n) {
        vector<int> nums;

        while (n > 0) {
            int num = n % 10;
            nums.push_back(num);
            n = n / 10;
        }
        sort(nums.begin(), nums.end());

        int m = nums.size();

        long long max = nums[m - 1] * nums[m - 2];

        return max;
    }
};