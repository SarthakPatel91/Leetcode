class Solution {
public:
    int gold = 0;
    void solve(int i, int j, int m, int n, int curr, vector<vector<int>>& grid) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
            return;

        // take current gold
        int val = grid[i][j];
        curr = curr + val;
        gold = max(curr, gold);

        // mark visited
        grid[i][j] = 0;

        // explore all 4 directions
        solve(i, j - 1, m, n, curr, grid); // left
        solve(i, j + 1, m, n, curr, grid); // right
        solve(i - 1, j, m, n, curr, grid); // up
        solve(i + 1, j, m, n, curr, grid); // down

        // backtrack
        grid[i][j] = val;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // DFS->start collecting from every cell which is not zero
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0)
                    solve(i, j, m, n, 0, grid);
            }
        }

        return gold;
    }
};