class Solution {
public:
    int m, n;
    int dp[201][201];
    int dfs(int r, int c, vector<vector<int>>& matrix) {
        if (dp[r][c] != 0)
            return dp[r][c];

        int ans = 1;

        // left
        if (c - 1 >= 0 && matrix[r][c - 1] > matrix[r][c]) {
            ans = max(ans, 1 + dfs(r, c - 1, matrix));
        }

        // right
        if (c + 1 < n && matrix[r][c + 1] > matrix[r][c]) {
            ans = max(ans, 1 + dfs(r, c + 1, matrix));
        }

        // up
        if (r - 1 >= 0 && matrix[r - 1][c] > matrix[r][c]) {
            ans = max(ans, 1 + dfs(r - 1, c, matrix));
        }

        // down
        if (r + 1 < m && matrix[r + 1][c] > matrix[r][c]) {
            ans = max(ans, 1 + dfs(r + 1, c, matrix));
        }

        return dp[r][c] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        int res = 0;
        memset(dp, 0, sizeof(dp));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                res = max(res, dfs(i, j, matrix));
            }
        }

        return res;
    }
};