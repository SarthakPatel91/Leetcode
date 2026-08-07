class Solution {
public:
    bool issafe(int row, int col, int n, vector<string>& ds) {

        // upper column
        for (int i = 0; i < row; i++) {
            if (ds[i][col] == 'Q')
                return false;
        }

        // upper left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (ds[i][j] == 'Q')
                return false;
        }

        // upper right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (ds[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void solve(int i, int n, vector<vector<bool>>& vis,
               vector<string>& ds, vector<vector<string>>& ans) {

        if (i == n) {
            ans.push_back(ds);
            return;
        }

        for (int j = 0; j < n; j++) {

            if (!vis[i][j] && issafe(i, j, n, ds)) {

                vis[i][j] = true;
                ds[i][j] = 'Q';

                solve(i + 1, n, vis, ds, ans);

                ds[i][j] = '.';
                vis[i][j] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> ds(n, string(n, '.'));
        vector<vector<string>> ans;
        vector<vector<bool>> vis(n, vector<bool>(n, false));

        solve(0, n, vis, ds, ans);

        return ans;
    }
};