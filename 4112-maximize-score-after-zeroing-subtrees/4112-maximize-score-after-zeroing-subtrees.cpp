class Solution {
public:
    int maxScore(vector<int>& parent, vector<int>& op, vector<int>& score) {
        int n = parent.size();
        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            if (parent[i] != -1) {
                adj[parent[i]].push_back(i);
            }
        }

        function<int(int)> dfs = [&](int s) {
            if (adj[s].empty())
                return score[s];

            int sum = score[s];
            int mn = INT_MAX;

            for (auto u : adj[s]) {
                int curr = dfs(u);
                sum += curr;
                mn = min(mn, curr);
            }

            if (op[s]) {
                sum = sum - mn;
            } else
                sum = max(sum, sum - mn);

            return sum;
        };

        return dfs(0);
    }
};