class Solution {
public:
    int m, n;

    void dfs(int r, int c, vector<vector<int>>& heights,
             vector<vector<bool>>& vis) {

        vis[r][c] = true;

        if (r - 1 >= 0 && !vis[r - 1][c] &&
            heights[r - 1][c] >= heights[r][c])
            dfs(r - 1, c, heights, vis);

        if (r + 1 < m && !vis[r + 1][c] &&
            heights[r + 1][c] >= heights[r][c])
            dfs(r + 1, c, heights, vis);

        if (c - 1 >= 0 && !vis[r][c - 1] &&
            heights[r][c - 1] >= heights[r][c])
            dfs(r, c - 1, heights, vis);

        if (c + 1 < n && !vis[r][c + 1] &&
            heights[r][c + 1] >= heights[r][c])
            dfs(r, c + 1, heights, vis);
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();

        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));

        // Pacific Ocean
        for (int i = 0; i < m; i++)
            dfs(i, 0, heights, pacific);

        for (int j = 0; j < n; j++)
            dfs(0, j, heights, pacific);

        // Atlantic Ocean
        for (int i = 0; i < m; i++)
            dfs(i, n - 1, heights, atlantic);

        for (int j = 0; j < n; j++)
            dfs(m - 1, j, heights, atlantic);

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};