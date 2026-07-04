class Solution {
public:
    int count = 0;

    void dfs(TreeNode* root, int maxi) {
        if (root == NULL)
            return;

        if (root->val >= maxi) {
            count++;
            maxi = root->val;
        }

        dfs(root->left, maxi);
        dfs(root->right, maxi);
    }

    int goodNodes(TreeNode* root) {
        dfs(root, root->val);
        return count;
    }
};