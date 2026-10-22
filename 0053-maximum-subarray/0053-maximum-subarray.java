class Solution {
    public int maxSubArray(int[] nums) {
        int n = nums.length;

        int ans = Integer.MIN_VALUE;
        int prefix = 0;
        for (int i = 0; i < n; i++) {
            prefix = prefix + nums[i];
            ans=Math.max(ans,prefix);

            if (prefix<0)
                prefix=0;
        }
        return ans;
    }
}