class Solution {
public:
    int m, n;
    vector<vector<int>> dp;

    int solve(int i, int j, string& word1, string& word2) {
        if (i == m)
            return n - j;
        if (j == n)
            return m - i;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (word1[i] == word2[j])
            return dp[i][j] = solve(i + 1, j + 1, word1, word2);

        int insert = solve(i, j + 1, word1, word2);
        int replace = solve(i + 1, j + 1, word1, word2);
        int del = solve(i + 1, j, word1, word2);

        return dp[i][j] = 1 + min({insert, replace, del});
    }

    int minDistance(string word1, string word2) {
        m = word1.size();
        n = word2.size();

        dp.assign(m, vector<int>(n, -1));

        return solve(0, 0, word1, word2);
    }
};