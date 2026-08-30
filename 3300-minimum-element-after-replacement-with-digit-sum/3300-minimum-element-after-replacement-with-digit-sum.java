class Solution {
    public int digitalsum(int num) {
        int sum = 0;
        while (num > 0) {
            int rem = num % 10;
            sum = sum + rem;
            num = num / 10;
        }

        return sum;
    }

    public int minElement(int[] nums) {
        int n = nums.length;
        int ans = Integer.MAX_VALUE;
        for (int i = 0; i < n; i++) {
            ans = Math.min(ans, digitalsum(nums[i]));
        }

        return ans;
    }
}