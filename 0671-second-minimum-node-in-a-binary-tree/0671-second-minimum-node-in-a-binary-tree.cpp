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
    void dfs(TreeNode* root, vector<int>& nodeValues) {
        if (root == nullptr)
            return;

        nodeValues.push_back(root->val);

        dfs(root->left, nodeValues);
        dfs(root->right, nodeValues);
    }
    int findSecondMinimumValue(TreeNode* root) {
        vector<int> nodeValues;

        dfs(root, nodeValues);

        sort(nodeValues.begin(), nodeValues.end());

        int ans;

        for (int i = 0; i < nodeValues.size() - 1; i++) {
            if (nodeValues[i] == nodeValues[i + 1])
                continue;

            else
                return nodeValues[i + 1];
        }

        return -1;
    }
};