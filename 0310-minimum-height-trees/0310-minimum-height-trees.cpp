class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        if(n==1)
        return {0};
        
        for (auto e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> indegree(n);

        for (int i = 0; i < n; i++)
            indegree[i] = adj[i].size();

        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 1)
                q.push(i);
        }

        while (n > 2) {
            int size = q.size();
            n -= size;

            while (size--) {
                int node = q.front();
                q.pop();

                for (int nei : adj[node]) {
                    indegree[nei]--;

                    if (indegree[nei] == 1)
                        q.push(nei);
                }
            }
        }

        vector<int> ans;

        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};