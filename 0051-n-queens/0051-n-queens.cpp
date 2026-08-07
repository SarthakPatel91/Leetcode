class Solution {
public:
    bool isSafe(int row, int col, int n, vector<string>& ds) {

        // Check upper column
        for (int i = 0; i < row; i++) {
            if (ds[i][col] == 'Q')
                return false;
        }

        // Check upper-left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (ds[i][j] == 'Q')
                return false;
        }

        // Check upper-right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (ds[i][j] == 'Q')
                return false;
        }

        return true;
    }

    void solve(int i, int j, int n, vector<string>& ds,
               vector<vector<string>>& ans) {

        if (i == n) {
            ans.push_back(ds);
            return;
        }

        for (j = 0; j < n; j++) {

            if (isSafe(i, j, n, ds)) {

                // Place Queen
                ds[i][j] = 'Q';

                // Recur for next row
                solve(i + 1, 0, n, ds, ans);

                // Backtrack
                ds[i][j] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {

        vector<string> ds(n, string(n, '.'));
        vector<vector<string>> ans;

        solve(0, 0, n, ds, ans);

        return ans;
    }
};