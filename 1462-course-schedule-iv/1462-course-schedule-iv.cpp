class Solution {
public:
    bool bfs(int n, vector<vector<int>>& adj, int src, int dst) {
        vector<bool> vis(n, false);
        vis[src]=true;
        queue<int> q;
        q.push(src);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int &v : adj[node]) {
                if (!vis[v]) {
                    if (v == dst)
                        return true;

                    vis[v] = true;
                    q.push(v);
                }
            }
        }

        return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses,
                                     vector<vector<int>>& prerequisites,
                                     vector<vector<int>>& queries) {
        int n = prerequisites.size();
        int m = queries.size();

        vector<bool> res(m, false);
        if (n == 0) {
            return res;
        }

        // make graph and fill indegree

        vector<vector<int>> adj(numCourses);
        // vector<int> indegree(n);
        for (int i = 0; i < n; i++) {
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[u].push_back(v);
            // indegree[v]++;
        }

        for (int i = 0; i < m; i++) {
            res[i] = bfs(numCourses, adj, queries[i][0], queries[i][1]);
        }

        return res;
    }
};