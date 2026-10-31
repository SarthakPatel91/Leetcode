class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        
        // dp[i][j] = whether s[0..i-1] matches p[0..j-1]
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
        
        dp[0][0] = true; // empty matches empty
        
        // Handle patterns like a*, a*b*, a*b*c* for empty string s
        for (int j = 2; j <= m; j++) {
            if (p[j - 1] == '*')
                dp[0][j] = dp[0][j - 2];
        }
        
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                
                if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                    // character matches or dot matches → take diagonal
                    dp[i][j] = dp[i - 1][j - 1];
                }
                
                else if (p[j - 1] == '*') {
                    // Case 1: Assume zero occurrences of preceding char
                    dp[i][j] = dp[i][j - 2];
                    
                    // Case 2: One+ occurrences
                    if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }
        
        return dp[n][m];
    }
};
