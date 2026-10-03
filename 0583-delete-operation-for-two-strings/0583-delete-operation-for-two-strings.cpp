class Solution {
public:
    int m, n;
    int dp[501][501];

    int solve(int i, int j, string& word1, string& word2) {
        if (i == m )
            return n-j;
            if(j==n)
            return m-i;

        if(dp[i][j]!=-1)
        return dp[i][j];

        if (word1[i] == word2[j])
            return dp[i][j]= solve(i+1,j+1,word1,word2);

        int left = solve(i + 1, j, word1, word2);
        int right = solve(i, j + 1, word1, word2);

        return dp[i][j]= 1 + min(left, right);
    }
    int minDistance(string word1, string word2) {
        m = word1.size();
        n = word2.size();

        memset(dp,-1,sizeof(dp));
        
        return solve(0,0,word1,word2);
    }
};