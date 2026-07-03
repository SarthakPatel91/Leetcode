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
    int count = 0;

    void dfs(TreeNode* root, long long sum) {
        if (root == NULL)
            return;

        sum = sum - root->val;

        if (sum == 0)
            count++;

        dfs(root->left, sum);
        dfs(root->right, sum);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return 0;

        dfs(root, targetSum);

        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);

        return count;
    }
};