class Solution {
public:
    int m,n;
    int dp[101][101][101];

    bool dfs(int i,int j,vector<vector<char>>& grid,int bal) {
        if(i<0 || i>=m || j<0 || j>=n)
            return false;

        if(grid[i][j]=='(')
            bal++;
        else
            bal--;

        if(bal<0)
            return false;

        int rem=(m-1-i)+(n-1-j);

        if(bal>rem)
            return false;

        if(dp[i][j][bal]!=-1)
            return dp[i][j][bal];

        if(i==m-1 && j==n-1)
            return dp[i][j][bal]=(bal==0);

        return dp[i][j][bal]=dfs(i,j+1,grid,bal) || dfs(i+1,j,grid,bal);
    }

    bool hasValidPath(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();

        if(grid[0][0]==')' || grid[m-1][n-1]=='(')
            return false;

        if((m+n-1)%2)
            return false;

        memset(dp,-1,sizeof(dp));

        return dfs(0,0,grid,0);
    }
};