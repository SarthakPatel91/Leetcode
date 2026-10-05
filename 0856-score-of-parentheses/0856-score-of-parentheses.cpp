class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        int score = 0;

        stack<int> st;

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') { // fresh start
                st.push(score);
                score = 0;
            } else {                   // closing
                if (s[i - 1] == '(') { // simple closing
                    score = st.top() + 1;
                } else { // nested closing
                    score = st.top() + 2 * score;
                }

                st.pop();
            }
        }
        return score;
    }
};