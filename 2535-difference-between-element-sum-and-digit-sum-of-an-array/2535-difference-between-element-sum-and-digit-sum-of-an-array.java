class Solution {
    public int digit(int num) {
        int sum = 0;
        while (num > 0) {
            int rem = num % 10;
            sum = sum + rem;
            num = num / 10;
        }

        return sum;
    }

    public int differenceOfSum(int[] nums) {
        int n = nums.length;

        int ans;
        int sum = 0;
        int dsum = 0;
        for (int i = 0; i < n; i++) {
            sum = sum + nums[i];
            dsum = dsum + digit(nums[i]);
        }

        return Math.abs(sum-dsum);
    }
}