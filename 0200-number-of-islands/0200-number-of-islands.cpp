class Solution {
public:
int m,n;
void dfs(vector<vector<char>>&grid,int i,int j){
    if(i<0 || i>=m || j<0 || j>=n || grid[i][j]=='0')
    return ;
    
    grid[i][j]='0';//mark visited

    dfs(grid,i-1,j);//up
    dfs(grid,i+1,j);//down
    dfs(grid,i,j+1);//right
    dfs(grid,i,j-1);//left
    
}
    int numIslands(vector<vector<char>>& grid) {
        m=grid.size();
        n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1'){//to start from from '1'
                    count++;
                    dfs(grid,i,j);
                }

            }
        }
        return count;
    }
};