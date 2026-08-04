class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n = arr.size();

        // vector<int> prefix(n);
        // prefix[0] = arr[0];
        // for (int i = 1; i < n; i++) {
        //     prefix[i] = prefix[i - 1] + arr[i];
        // }

        // brute force

        // int ans = 0;
        // for (int l = 0; l < n; l++) {
        //     for (int r = l; r < n; r++) {
        //         int sum;
        //         if (l == 0)
        //             sum = prefix[r];
        //         else
        //             sum = prefix[r] - prefix[l - 1];

        //         if (sum % 2 != 0)
        //             ans++;
        //     }
        // }
        // return ans;

        // optimized for time complexity and space

        const int Mod = 1e9 + 7;
        unordered_map<int, int> mp;
        mp[0] = 1;
        mp[1] = 0;

        int prefix = 0;
        int ans = 0;

        for (int i = 0; i < n; i++) {
            prefix += arr[i];

            int rem = prefix % 2;

            if (rem == 0)
                ans = (ans + mp[1]) % Mod;
            else
                ans = (ans + mp[0]) % Mod;

            mp[rem]++;
        }
        return ans;
    }
};