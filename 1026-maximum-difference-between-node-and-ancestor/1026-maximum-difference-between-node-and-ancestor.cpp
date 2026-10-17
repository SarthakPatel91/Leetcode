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
    void dfs(TreeNode* root, vector<int>& ds, vector<vector<int>>& ans) {
        if (root == nullptr)
            return;

        ds.push_back(root->val);

        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(ds);
        }

        dfs(root->left, ds, ans);
        dfs(root->right, ds, ans);

        ds.pop_back();
    }
    int maxAncestorDiff(TreeNode* root) {
        vector<vector<int>> ans;
        vector<int> ds;

        dfs(root, ds, ans);

        int res = INT_MIN;

        for (int i = 0; i < ans.size(); i++) {
            vector<int> nums = ans[i];

            int mn = *min_element(nums.begin(), nums.end());
            int mx = *max_element(nums.begin(), nums.end());

            res = max(res, abs(mx - mn));
        }

        return res;
    }
};