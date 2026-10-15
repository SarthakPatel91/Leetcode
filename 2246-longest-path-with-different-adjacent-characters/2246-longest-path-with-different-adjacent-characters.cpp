class Solution {
public:
    int max_len = 1;

    int dfs(int node, vector<vector<int>>& adj, string& s) {
        int first = 0, second = 0;

        for (auto& neig : adj[node]) {
            int len = dfs(neig, adj, s);

            if (s[neig] == s[node])
                continue;

            if (len > first) {
                second = first;
                first = len;
            } else if (len > second) {
                second = len;
            }
        }

        max_len = max(max_len, first + second + 1);
        return first + 1;
    }

    int longestPath(vector<int>& parent, string s) {
        int n = s.size();
        vector<vector<int>> adj(n);

        for (int i = 1; i < n; i++)
            adj[parent[i]].push_back(i);

        dfs(0, adj, s);
        return max_len;
    }
};