class Solution {
public:
    string reverseWords(string s) {
        if (s.size() == 1)
            return s;

        // string ans;

        // stack<char> st;

        for (int i = 0; i < s.size(); i++) {
            int k = i;
            while (k<s.size() && s[k] != ' ') {
                k++;
            }
            reverse(s.begin() + i, s.begin() + k);

            i = k;
        }

        return s;
    }
};