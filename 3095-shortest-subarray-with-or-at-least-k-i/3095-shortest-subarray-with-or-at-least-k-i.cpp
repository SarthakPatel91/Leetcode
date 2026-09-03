class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        int len = INT_MAX;
        int xr;
        for (int i = 0; i < n; i++) {
            xr = 0;
            for (int j = i; j < n; j++) {
                xr = xr | nums[j];

                if (xr >= k) {
                    len = min(len, j - i + 1);
                    break;
                }
            }
        }
        if (len == INT_MAX)
            return -1;

        return len;
    }
};