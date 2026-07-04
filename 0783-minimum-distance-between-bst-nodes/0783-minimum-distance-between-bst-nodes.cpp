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
    // int first;
    // int second;
    void inorder(TreeNode* root, vector<int>& in) {
        if (root == NULL)
            return;

        inorder(root->left, in);
        in.push_back(root->val);
        inorder(root->right, in);
    }
    int minDiffInBST(TreeNode* root) {

        vector<int> in;
        inorder(root, in);

        int min = INT_MAX;
        for (int i = 0; i < in.size() - 1; i++) {
            int num = abs(in[i] - in[i + 1]);

            if (min > num)
                 min=num;
        }

        return min;
    }
};