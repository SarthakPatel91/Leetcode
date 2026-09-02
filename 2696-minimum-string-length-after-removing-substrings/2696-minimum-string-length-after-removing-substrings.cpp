class Solution {
public:
    int minLength(string s) {
        int n = s.size();

        string st = "";
        for (int i = 0; i < n; i++) {
            if (!st.empty() && ((st.back() == 'A' && s[i] == 'B') ||
                                (st.back() == 'C' && s[i] == 'D')))
                st.pop_back();

            else
                st.push_back(s[i]);
        }

        return st.size();
    }
};