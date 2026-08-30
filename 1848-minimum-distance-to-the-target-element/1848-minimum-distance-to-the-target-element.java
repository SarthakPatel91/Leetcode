class Solution {
    public int getMinDistance(int[] nums, int target, int start) {
        int mn = Integer.MAX_VALUE;

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == target && mn > Math.abs(i - start))
                mn = Math.abs(i - start);
            ;
        }

        return mn;
    }
}