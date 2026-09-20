class Solution {
    public int reverseDegree(String s) {
        int n = s.length();

        int ans = 0;

        for (int i = 0; i < n; i++) {
            int idx = 'z' - s.charAt(i);

            ans = ans + (i + 1) * (idx + 1);
        }

        return ans;
    }
}