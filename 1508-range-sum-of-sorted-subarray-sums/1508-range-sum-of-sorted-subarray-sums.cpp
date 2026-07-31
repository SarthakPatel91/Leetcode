class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {

        int newsize = n * (n + 1) / 2;

        vector<int> res(newsize);
        int k = 0;

        for (int l = 0; l < n; l++) {
            int sum = 0;
            for (int r = l; r < n; r++) {

                sum = sum + nums[r];
                res[k] = sum;
                k++;
            }
        }

        sort(res.begin(), res.end());

        long long ans = 0;

        for (int i = left - 1; i <= right - 1; i++) {
            ans += res[i];
        }
        int mod = 1e9 + 7;
        ans = ans % mod;

        return ans;
    }
};