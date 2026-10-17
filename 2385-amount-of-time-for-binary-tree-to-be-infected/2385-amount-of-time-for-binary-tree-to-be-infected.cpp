/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, vector<vector<int>>& adj) {
        if (!root)
            return;

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

    int amountOfTime(TreeNode* root, int start) {
        int n = 100001;

        vector<vector<int>> adj(n);

        dfs(root,adj);
        
        vector<bool> vis(n, false);

        int time = -1;

        queue<int> q;
        q.push(start);
        vis[start] = true;

        while (!q.empty()) {
            int size = q.size();
            time++;

            for (int i = 0; i < size; i++) {
                int node = q.front();

                q.pop();

                for (auto& neig : adj[node]) {
                    if (vis[neig] == false) {
                        q.push(neig);
                        vis[neig] = true;
                    }
                }
            }
        }

        return time;
    }
};