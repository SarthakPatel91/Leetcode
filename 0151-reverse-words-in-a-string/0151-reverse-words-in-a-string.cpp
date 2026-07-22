class Solution {
public:
    string reverseWords(string s) {
        stack<char> st;
        string ans;

        int n = s.size();

        int i = 0;
        int j = n - 1;

        while (i < n && s[i] == ' ')
            i++;
        while (j >= 0 && s[j] == ' ')
            j--;

        while (j >= i) {

            // Push one word into stack
            while (j >= i && s[j] != ' ') {
                st.push(s[j]);
                j--;
            }

            // Pop the word into answer
            while (!st.empty()) {
                ans += st.top();
                st.pop();
            }

            // Skip spaces between words
            while (j >= i && s[j] == ' ')
                j--;

            // Add one space if another word exists
            if (j >= i)
                ans += ' ';
        }

        return ans;
    }
};