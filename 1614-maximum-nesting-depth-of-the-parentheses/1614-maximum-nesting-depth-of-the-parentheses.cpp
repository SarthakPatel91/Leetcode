class Solution {
public:
    int maxDepth(string s) {
        int ans = 0;
        int brac = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                brac++;
            if (s[i] ==')')
                brac--;

            ans = max(brac, ans);
        }

        return ans;
    }
};