class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int i = 0;
        int j = nums.size() - 1;
        long long count = 0;
        const int mod = 1e9 + 7;

        vector<long long> power(nums.size());

        power[0] = 1;

        for (int k = 1; k < nums.size(); k++) {
            power[k] = (power[k - 1] * 2) % mod;
        }

        while (i <= j) {
            if (nums[i] + nums[j] <= target) {
                count = (count + power[j - i]) % mod;
                i++;
            } else {
                j--;
            }
        }

        return count;
    }
};