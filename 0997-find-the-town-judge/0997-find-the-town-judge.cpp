class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n == 1)
            return 1;
            
        // make graph
        unordered_map<int, vector<int>> adj;
        for (int i = 0; i < trust.size(); i++) {
            int u = trust[i][0];
            int v = trust[i][1];

            adj[u].push_back(v);
        }
        // indegree of each node
        vector<int> indegree(n + 1, 0);
        for (int u = 1; u <= n; u++) {
            for (auto& v : adj[u])
                indegree[v]++;
        }
        int judge = -1;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == n - 1) {
                judge = i;
                break;
            }
        }
        for (int i = 0; i < trust.size(); i++) {
            if (trust[i][0] == judge)
                return -1;
        }

        return judge;
    }
};