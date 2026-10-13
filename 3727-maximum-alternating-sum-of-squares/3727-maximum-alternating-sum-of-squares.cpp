class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            if (nums[i] < 0)
                nums[i] = -1 * nums[i];
        }
        sort(nums.begin(), nums.end());

        int even_len, odd_len;

        if (n % 2 == 0)
            even_len = n / 2;
        else
            even_len = n / 2 + 1;

        odd_len = n - even_len;

        long long evensum = 0;
        long long oddsum = 0;
        const int mod = 1e9 + 7;

        for (int i = 0; i < n; i++) {
            if (i < odd_len)
                evensum += nums[i] * nums[i];
            else
                oddsum += nums[i] * nums[i];
        }

        return abs(evensum - oddsum);
    }
};