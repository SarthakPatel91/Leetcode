class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> prime(right + 1, true);
        prime[0] = false;
        if (right >= 1) prime[1] = false;

        for (int i = 2; (long long)i * i <= right; i++) {
            if (prime[i]) {
                for (int j = i * i; j <= right; j += i) {
                    prime[j] = false;
                }
            }
        }

        vector<int> ans;
        for (int i = max(left, 2); i <= right; i++) {
            if (prime[i]) ans.push_back(i);
        }

        if (ans.size() < 2) return {-1, -1};

        int gap = INT_MAX;
        vector<int> res = {-1, -1};

        for (int i = 0; i + 1 < (int)ans.size(); i++) {
            int d = ans[i + 1] - ans[i];
            if (d < gap) {
                gap = d;
                res = {ans[i], ans[i + 1]};
            }
        }
        return res;
    }
};