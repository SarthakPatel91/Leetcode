class Solution {
public:
    int dp[501][501];
    int solve(int i, int j, vector<int>& piles) {
        if (i > j)
            return  0;

        if (dp[i][j] != -1)
            return dp[i][j];

        // take from left
        int take_i =
            piles[i] + min(solve(i + 2, j, piles), solve(i + 1, j - 1, piles));

        // take from right
        int take_j =
            piles[j] + min(solve(i + 1, j - 1, piles), solve(i, j - 2, piles));

        // to maximize the score
        return dp[i][j] = max(take_i, take_j);
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();

        memset(dp, -1, sizeof(dp));

        int totalsum = 0;
        for (int i = 0; i < n; i++) {
            totalsum += piles[i];
        }
        int alice_score = solve(0, n - 1, piles);
        int bob_score = totalsum - alice_score;

        return alice_score > bob_score;
    }
};