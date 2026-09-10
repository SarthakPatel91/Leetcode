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
    int ans = 0;
    void solve(TreeNode* root) {
        if (root == NULL)
            return;

        int sum = 0;
        int count = 0;
        findsum(root, sum, count);
        int avg = sum / count;

        if (avg == root->val)
            ans++;

        solve(root->left);
        solve(root->right);
    }
    void findsum(TreeNode* root, int& sum, int& count) {
        if (root == NULL)
            return;

        sum += root->val;
        count++;

        findsum(root->left, sum, count);
        findsum(root->right, sum, count);
    }

    int averageOfSubtree(TreeNode* root) {
        if (root == nullptr)
            return 0;

        solve(root);

        return ans;
    }
};