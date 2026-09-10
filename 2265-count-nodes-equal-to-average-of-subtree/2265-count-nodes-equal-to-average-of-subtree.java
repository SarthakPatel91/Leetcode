/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int ans = 0;

    public void solve(TreeNode root) {
        if (root == null)
            return;

        int[] sum = {0};
        int[] count = {0};
        findsum(root, sum, count);

        int avg = sum[0] / count[0];

        if (avg == root.val)
            ans++;

        solve(root.left);
        solve(root.right);
    }

    public void findsum(TreeNode root,int[] sum,int[] count){
        if(root==null)
        return ;

        sum[0]+=root.val;
        count[0]++;

        findsum(root.left,sum,count);
        findsum(root.right,sum,count);
    }

   public int averageOfSubtree(TreeNode root) {
        if(root==null)
        return 0;

        solve(root);

        return ans;
    }
}