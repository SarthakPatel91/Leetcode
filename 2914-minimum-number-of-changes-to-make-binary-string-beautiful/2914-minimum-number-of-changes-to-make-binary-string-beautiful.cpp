class Solution {
public:
    typedef long long ll;
    int minChanges(string s) {
        int ans = 0;
        int n = s.size();

        for (int i = 1; i < n; i=i+2) {
            char prev = s[i - 1];
            char curr = s[i];

            if (prev != curr)
                ans++;
        }
        return ans;
    }
};