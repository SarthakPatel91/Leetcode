class Solution {
public:
    int maxPower(string s) {
        int count = 1;
        int mx = INT_MIN;

        for (int i = 0; i < s.size() - 1; i++) {
            if (s[i] == s[i + 1]) {
                count++;
            } else
                count = 1;

            mx = max(count, mx);
        }
        if (mx == INT_MIN)
            return 1;

        return mx;
    }
};