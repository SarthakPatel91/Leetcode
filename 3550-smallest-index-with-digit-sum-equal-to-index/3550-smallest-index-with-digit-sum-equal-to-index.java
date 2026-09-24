class Solution {
    public int digitsum(int n) {
        int sum = 0;
        while (n > 0) {
            int rem = n % 10;
            sum = sum + rem;
            n = n / 10;
        }

        return sum;
    }

    public int smallestIndex(int[] nums) {
        int size = nums.length;

        for (int i = 0; i < size; i++) {
            if (i == digitsum(nums[i])) {
                return i;
            }
        }

        return -1;
    }
}