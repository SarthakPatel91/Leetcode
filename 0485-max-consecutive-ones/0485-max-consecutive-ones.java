class Solution {
    public int findMaxConsecutiveOnes(int[] nums) {
        int n = nums.length;

        int ans = Integer.MIN_VALUE;

        for (int i = 0; i < n; i++) {
            int count = 0;

            while (i<n && nums[i] == 1) {
                i++;
                count++;
                ans = Math.max(ans, count);
            }
        }
        if(ans == Integer.MIN_VALUE)
        return 0;

        
        return ans;
    }
}