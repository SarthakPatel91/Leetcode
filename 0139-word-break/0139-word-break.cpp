class Solution {
public:
    int dp[301];
    bool solve(string& s, unordered_map<string, int>& st, int m, int idx,
               bool ans) {
        if (idx == m)
            return true;

        if (dp[idx] != -1)
            return dp[idx];

        string temp = "";

        for (int end = idx; end < m; end++) {
            temp = s.substr(idx, end - idx + 1);

            if (st.count(temp))
                if (solve(s, st, m, end + 1, ans))
                    return dp[idx] = true;
        }

        return dp[idx]=false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> st;

        memset(dp, -1, sizeof(dp));
        int m = s.size();
        int n = wordDict.size();

        for (int i = 0; i < n; i++) {
            st[wordDict[i]] = 1;
        }

        bool ans = false;

        return solve(s, st, m, 0, ans);
    }
};