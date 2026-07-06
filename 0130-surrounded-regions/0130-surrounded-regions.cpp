class Solution {
public:
    void dfs(int u, unordered_map<int, vector<int>>& adj,
             vector<bool>& vis) {

        vis[u] = true;

        for (auto &v : adj[u]) {
            if (!vis[v])
                dfs(v, adj, vis);
        }
    }

    void solve(vector<vector<char>>& board) {

        int m = board.size();
        int n = board[0].size();

        vector<pair<int,int>> dir = {
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };

        // Build graph
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (board[i][j] == 'X')
                    continue;

                int u = i * n + j;

                for (auto &d : dir) {

                    int ni = i + d.first;
                    int nj = j + d.second;

                    if (ni >= 0 && ni < m &&
                        nj >= 0 && nj < n &&
                        board[ni][nj] == 'O') {

                        int v = ni * n + nj;
                        adj[u].push_back(v);
                    }
                }
            }
        }

        vector<bool> vis(m * n, false);

        // DFS from all border O's
        for (int i = 0; i < m; i++) {

            // Left border
            if (board[i][0] == 'O' && !vis[i * n])
                dfs(i * n, adj, vis);

            // Right border
            if (board[i][n - 1] == 'O' && !vis[i * n + (n - 1)])
                dfs(i * n + (n - 1), adj, vis);
        }

        for (int j = 0; j < n; j++) {

            // Top border
            if (board[0][j] == 'O' && !vis[j])
                dfs(j, adj, vis);

            // Bottom border
            if (board[m - 1][j] == 'O' && !vis[(m - 1) * n + j])
                dfs((m - 1) * n + j, adj, vis);
        }

        // Flip surrounded O's
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                int node = i * n + j;

                if (board[i][j] == 'O' && !vis[node])
                    board[i][j] = 'X';
            }
        }
    }
};