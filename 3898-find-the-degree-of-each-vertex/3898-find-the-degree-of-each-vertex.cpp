class Solution {
public:
    vector<int> findDegrees(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> adj(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    int u = i;
                    int v = j;
                    adj[u].push_back(v);
                }
            }
        }

        vector<int> ans(n);

        for (int i = 0; i < n; i++) {
            ans[i] = adj[i].size();
        }
        return ans;
    }
};