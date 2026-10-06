class Solution {
public:
    int m, n;
    vector<vector<int>> dp;

    int solve(int i, int j, string& a, string& b) {
        if (i == m) return n - j;
        if (j == n) return m - i;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (a[i] == b[j])
            return dp[i][j] = 1 + solve(i + 1, j + 1, a, b);

        return dp[i][j] = 1 + min(
            solve(i + 1, j, a, b),
            solve(i, j + 1, a, b)
        );
    }

    string shortestCommonSupersequence(string str1, string str2) {
        m = str1.size();
        n = str2.size();

        dp.assign(m, vector<int>(n, -1));

        solve(0, 0, str1, str2);

        string ans;
        int i = 0, j = 0;

        while (i < m && j < n) {
            if (str1[i] == str2[j]) {
                ans += str1[i];
                i++;
                j++;
            }
            else if (solve(i + 1, j, str1, str2) <= solve(i, j + 1, str1, str2)) {
                ans += str1[i++];
            }
            else {
                ans += str2[j++];
            }
        }

        while (i < m) ans += str1[i++];
        while (j < n) ans += str2[j++];

        return ans;
    }
};