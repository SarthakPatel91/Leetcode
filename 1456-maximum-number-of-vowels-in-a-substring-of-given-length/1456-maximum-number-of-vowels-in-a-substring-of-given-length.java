class Solution {
    public static boolean is_vowel(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    public int maxVowels(String s, int k) {
        int n = s.length();

        int ans = 0;
        int count = 0;
        for (int i = 0; i < k; i++) {
            if (is_vowel(s.charAt(i)))
                count++;
        }

        int left = 0;
        ans = count;
        for (int i = k; i < n; i++) {
            if (is_vowel(s.charAt(i))) {
                count++;
            }
            if (is_vowel(s.charAt(i - k)))
                count--;

            ans = Math.max(ans, count);
        }
        return ans;
    }
}