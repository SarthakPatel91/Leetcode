class Solution {
public:
    int dp[101];
    int solve(string& s, int idx) {
        if (idx == s.size())
            return 1;

        if (s[idx] == '0')
            return 0;

        if (dp[idx] != -1)
            return dp[idx];

        int take_1_digit = solve(s, idx + 1);

        int take_2_digit = 0;

        if (idx + 1 < s.size()) {
            int num = (s[idx] - '0') * 10 + (s[idx + 1] - '0');
            if (num >= 10 && num <= 26) {
                take_2_digit = solve(s, idx + 2);
            }
        }

        return dp[idx] = take_1_digit + take_2_digit;
    }
    int numDecodings(string s) {
        int n = s.size();
        if (n == 1 && s[0]!='0')
            return 1;

        memset(dp, -1, sizeof(dp));

        return solve(s, 0);
    }
};