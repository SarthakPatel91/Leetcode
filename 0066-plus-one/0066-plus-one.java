class Solution {
    public int[] plusOne(int[] digits) {
        int n = digits.length;

        int carry = 0;

        int right = n - 1;

        while (right >= 0) {
            if (digits[right] + 1 == 10) {
                carry = 1;
                digits[right] = 0;
                right--;
            } else {
                digits[right] = digits[right] + 1;
                break;
            }
        }

        if (right < 0) {
            int[] ans = new int[n + 1];
            ans[0] = 1;
            for (int i = 1; i < n + 1; i++)
                ans[i] = digits[i - 1];

            return ans;
        }

        return digits;
    }
}