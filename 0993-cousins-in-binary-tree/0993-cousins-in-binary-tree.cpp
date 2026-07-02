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
    bool isCousins(TreeNode* root, int x, int y) {
        vector<vector<int>> ans;
        queue<TreeNode*> q;

        q.push(root);

        while (!q.empty()) {
            int size = q.size();
            vector<int> level;
            vector<int> check;

            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                level.push_back(node->val);

                if (node->left) {
                    if (node->left->val == x || node->left->val == y) {
                        check.push_back(node->val);
                    }
                    q.push(node->left);
                }
                if (node->right) {
                    if (node->right->val == x || node->right->val == y) {
                        check.push_back(node->val);
                    }
                    q.push(node->right);
                }
                if (check.size() == 2) {
                    if (check[0] == check[1])
                        return false;

                    break;
                }
            }

            ans.push_back(level);
        }

        int xind = -1;
        int yind = -1;

        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                if (ans[i][j] == x)
                    xind = i;
                if (ans[i][j] == y)
                    yind = i;
            }
        }
        if (xind != yind)
            return false;

        return true;
    }
};