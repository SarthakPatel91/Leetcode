class Solution {
public:
    int m, n;
    int check(int r, int c, vector<vector<int>>& grid) {
        int count = 0;
        // left
        if (c - 1 >= 0)
            if (grid[r][c - 1] == 1)
                count++;
        // right
        if (c + 1 < n)
            if (grid[r][c + 1] == 1)
                count++;
        // up
        if (r - 1 >= 0)
            if (grid[r - 1][c] == 1)
                count++;
        // bottom
        if (r + 1 < m)
            if (grid[r + 1][c] == 1)
                count++;

        return count;
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    res = res + 4 - check(i, j, grid);
                }
            }
        }
        return res;
    }
};