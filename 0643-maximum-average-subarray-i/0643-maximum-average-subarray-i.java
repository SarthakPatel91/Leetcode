class Solution {
    public double findMaxAverage(int[] nums, int k) {
        double ans = Integer.MIN_VALUE, sum = 0;
        int n = nums.length;

        for (int i = 0; i < k; i++)
            sum = sum + nums[i];

        ans = sum / k;
        int left = 0;
        for (int i = k; i < n; i++) {
            sum = sum + nums[i] - nums[left++];

            ans = Math.max(ans, sum / k);
        }

        return ans;
    }
}