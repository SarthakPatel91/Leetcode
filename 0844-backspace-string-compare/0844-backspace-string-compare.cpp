class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n = s.size();
        int m = t.size();

        stack<char> st;
        string s1 = "";
        string s2 = "";

        for (int i = 0; i < n; i++) {
            if (s[i] != '#')
                s1.push_back(s[i]);

            else if (s1.size() > 0)
                s1.pop_back();
        }
        for (int i = 0; i < m; i++) {
            if (t[i] != '#')
                s2.push_back(t[i]);

            else if (s2.size() > 0)
                s2.pop_back();
        }

        return s1 == s2;
    }
};