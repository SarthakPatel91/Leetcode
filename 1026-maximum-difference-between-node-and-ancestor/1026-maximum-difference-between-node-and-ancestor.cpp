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
    int res = INT_MIN;
    void dfs(TreeNode* root, int path_min, int path_max) {
        if (root == NULL) {
            res = max(res, path_max - path_min);
            return;
        }

        path_max = max(path_max, root->val);
        path_min = min(path_min, root->val);

        dfs(root->left, path_min, path_max);
        dfs(root->right, path_min, path_max);
    }
    int maxAncestorDiff(TreeNode* root) {
        dfs(root, INT_MAX, INT_MIN);

        return res;
    }
};