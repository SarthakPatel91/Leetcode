class Solution {
public:
    int m, n;
    int dp[201][201];
    int solve(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || i >= m || j < 0 || j >= n)
            return INT_MAX;

        if(i==m-1 && j==n-1)
        return 0;
        
        if(dp[i][j]!=-1)
        return dp[i][j];

        int down = INT_MAX;
        if (i + 1 < m) {
            down = grid[i + 1][j] + solve(i + 1, j, grid);
        }

        int right = INT_MAX;
        if (j + 1 < n) {
            right = grid[i][j + 1] + solve(i, j + 1, grid);
        }

        return dp[i][j]= min(right, down);
    }
    int minPathSum(vector<vector<int>>& grid) {
         m = grid.size();
         n = grid[0].size();

        memset(dp,-1,sizeof(dp));
        
        return grid[0][0]+ solve(0,0,grid);
    }
};