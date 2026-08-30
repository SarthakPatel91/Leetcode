class Solution {
    public int[] runningSum(int[] nums) {
        int n = nums.length;
        int[] list = new int[n];
        list[0] = nums[0];

        for (int i = 1; i < n; i++) {
            list[i] = list[i - 1] + nums[i];
        }

        return list;

    }
}