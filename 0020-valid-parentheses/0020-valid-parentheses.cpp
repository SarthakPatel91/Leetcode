class Solution {
public:
    bool isValid(string s) {
        stack<char> st;

        for (char ch : s) {
            // If opening bracket, push
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            }
            // If closing bracket
            else {
                if (st.empty()) return false;

                char top = st.top();
                st.pop();

                if ((ch == ')' && top != '(') ||
                    (ch == '}' && top != '{') ||
                    (ch == ']' && top != '[')) {
                    return false;
                }
            }
        }
        // Stack must be empty at the end
        return st.empty();

    }
};
