class Solution {
public:
    bool isvowel(char ch) {
        char c = tolower(ch);

        if (c == 'a' || c == 'i' || c == 'o' || c == 'u' || c == 'e')
            return true;

        return false;
    }
    string reverseVowels(string s) {
        int n = s.size();

        int i = 0;
        int j = n - 1;

        string ans;

        while (i < j) {

            if (!isvowel(s[i]))
                i++;

            if (!isvowel(s[j]))
                j--;

            if (isvowel(s[i]) && isvowel(s[j])) {
                swap(s[i], s[j]);
                i++;
                j--;
            }
        }

        return s;
    }
};