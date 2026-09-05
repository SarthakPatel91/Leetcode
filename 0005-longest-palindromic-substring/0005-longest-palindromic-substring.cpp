class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int size = 0;
        string res = "";

        for (int i = 0; i < n; i++) {

            // Odd-length palindromes
            int l = i, r = i;

            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > size) {
                    size = r - l + 1;
                    res = s.substr(l, size);
                }
                l--;
                r++;
            }

            // Even-length palindromes
            l = i;
            r = i + 1;

            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 > size) {
                    size = r - l + 1;
                    res = s.substr(l, size);
                }
                l--;
                r++;
            }
        }

        return res;
    }
};