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
    int height(TreeNode* root) {
        if (root == NULL)
            return 0;

        int left = height(root->left);
        int right = height(root->right);

        return 1 + max(left, right);
    }
    int deepestLeavesSum(TreeNode* root) {
        // vector<vector<int>> ans;

        int depth = height(root);
        
        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);

        int maxdepth = 1;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                if (node->left)
                    q.push(node->left);

                if (node->right)
                    q.push(node->right);

                if (maxdepth == depth)
                    sum = sum + node->val;
            }
            maxdepth++;
        }

        return sum;
    }
};