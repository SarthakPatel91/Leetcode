class Solution {
public:
    void dfs(TreeNode* root, vector<vector<int>>& adj) {
        if (!root) return;

        if (root->left) {
            adj[root->val].push_back(root->left->val);
            adj[root->left->val].push_back(root->val);
            dfs(root->left, adj);
        }

        if (root->right) {
            adj[root->val].push_back(root->right->val);
            adj[root->right->val].push_back(root->val);
            dfs(root->right, adj);
        }
    }

    void dfs1(int node, int dist, vector<vector<int>>& adj,
              vector<int>& ans, vector<bool>& vis, int k) {
        vis[node] = true;

        if (dist == k) {
            ans.push_back(node);
            return;
        }

        for (auto& neig : adj[node]) {
            if (!vis[neig]) {
                dfs1(neig, dist + 1, adj, ans, vis, k);
            }
        }
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        int n = 10001;
        vector<vector<int>> adj(n);

        dfs(root, adj);

        vector<bool> vis(n, false);
        vector<int> ans;

        dfs1(target->val, 0, adj, ans, vis, k);

        return ans;
    }
};