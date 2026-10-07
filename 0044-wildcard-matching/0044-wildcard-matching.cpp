class Solution {
public:
    int n, m;
    vector<vector<int>> dp;

    bool solve(int i, int j, string& s, string& p) {
        if (i == m && j == n)
            return true;

        if (j == n)
            return false;

        if (i == m)
            return p[j] == '*' && solve(i, j + 1, s, p);

        if (dp[i][j] != -1)
            return dp[i][j];

        // if char matches
        if (s[i] == p[j])
            return dp[i][j] = solve(i + 1, j + 1, s, p);

        if (p[j] == '?')
            return dp[i][j] = solve(i + 1, j + 1, s, p);

        if (p[j] == '*') {
            return dp[i][j] = solve(i + 1, j, s, p) || solve(i, j + 1, s, p);
        }

        return false;
    }
    bool isMatch(string s, string p) {
        m = s.size();
        n = p.size();

        dp.assign(m, vector<int>(n, -1));

        return solve(0, 0, s, p);
    }
};