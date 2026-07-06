class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& adj, int u,
             vector<bool>& visited) {
        visited[u] = true;

        for (auto& v : adj[u]) {
            if (!visited[v])
                dfs(adj, v, visited);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        // make graph
        unordered_map<int, vector<int>> adj;

        for (int i = 0; i < rooms.size(); i++) {
            for (int j = 0; j < rooms[i].size(); j++) {
                int v = rooms[i][j];
                adj[i].push_back(v);
            }
        }

        vector<bool> visited(rooms.size(), false);
        visited[0] = true;

        dfs(adj, 0, visited);

        for (int i = 0; i < visited.size(); i++) {
            if (visited[i] == false)
                return false;
        }

        return true;
    }
};