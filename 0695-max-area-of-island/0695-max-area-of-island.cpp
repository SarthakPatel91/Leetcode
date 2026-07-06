class Solution {
public:
    int dfs(int u, unordered_map<int, vector<int>>& adj,
            vector<bool>& visited) {

        visited[u] = true;
        int area = 1;

        for (int v : adj[u]) {
            if (!visited[v]) {
                area += dfs(v, adj, visited);
            }
        }

        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        unordered_map<int, vector<int>> adj;

        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,-1},{0,1}};

        // Build Graph
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j]==0)
                    continue;

                int u = i*m + j;

                for(auto &d : dir){

                    int ni = i + d.first;
                    int nj = j + d.second;

                    if(ni>=0 && ni<n &&
                       nj>=0 && nj<m &&
                       grid[ni][nj]==1){

                        int v = ni*m + nj;
                        adj[u].push_back(v);
                    }
                }
            }
        }

        vector<bool> visited(n*m,false);

        int ans = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j]==0)
                    continue;

                int node = i*m + j;

                if(!visited[node]){
                    ans = max(ans, dfs(node, adj, visited));
                }
            }
        }

        return ans;
    }
};