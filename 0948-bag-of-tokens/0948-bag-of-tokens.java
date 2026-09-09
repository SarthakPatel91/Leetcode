class Solution {
    public int bagOfTokensScore(int[] tokens, int power) {
        Arrays.sort(tokens);

        int n = tokens.length;
        int i = 0;
        int j = n - 1;

        int points = 0;
        int ans = 0;

        while (i <= j) {
            if (power >= tokens[i]) {
                power -= tokens[i];
                points++;
                i++;
                ans = Math.max(ans, points);
            } else if (points >= 1) {
                points--;
                power += tokens[j];
                j--;
            } else
                break;
        }

        return ans;
    }
};