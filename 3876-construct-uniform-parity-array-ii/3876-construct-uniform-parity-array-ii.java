class Solution {
    public boolean uniformArray(int[] nums1) {
        int n = nums1.length;

        int minodd = Integer.MAX_VALUE;
        int mineven = Integer.MAX_VALUE;

        int countodd = 0;
        int counteven = 0;

        for (int i = 0; i < n; i++) {
            if (nums1[i] % 2 == 0) {
                counteven++;
                mineven = Math.min(mineven, nums1[i]);
            } else {
                countodd++;
                minodd = Math.min(minodd, nums1[i]);
            }
        }

        if (n == counteven || n == countodd)
            return true;

        if (minodd < mineven)
            return true;

        return false;
    }
}