class Solution {
public:
    string removeDuplicates(string s) {
        int n = s.size();

        string ans = "";
        stack<char> st;
    
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() == s[i]) {
                st.pop();
                i++;
            }
            if(i<n)
            st.push(s[i]);
        }

        while (!st.empty()) {
            ans = ans + st.top();
            st.pop();
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};