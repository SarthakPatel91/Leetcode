class Solution {
public:
    int m, n;

    void dfs(int i, int j, vector<vector<int>>& grid, long long& sum) {
        if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0)
            return;

        sum += grid[i][j];
        grid[i][j] = 0;   // mark visited

        dfs(i, j - 1, grid, sum);
        dfs(i, j + 1, grid, sum);
        dfs(i - 1, j, grid, sum);
        dfs(i + 1, j, grid, sum);
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        int count = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] != 0) {
                    long long sum = 0;
                    dfs(i, j, grid, sum);
                    if (sum % k == 0)
                        count++;
                }
            }
        }
        return count;
    }
};