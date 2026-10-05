class Solution {
public:
    int n;
    // RECURSIVE

    // int solve(int i, vector<int>& prices, vector<int>& ds, bool hold) {
    //     if (i == n)
    //         return 0;

    //     int buy = 0, buy_skip = 0, sell = 0, sell_skip = 0;

    //     // buy or skip
    //     if (hold == false) {
    //         hold = true;
    //         ds.push_back(prices[i]);
    //         buy = solve(i + 1, prices, ds, hold);

    //         hold = false;
    //         ds.pop_back();
    //         buy_skip = solve(i + 1, prices, ds, hold);
    //     }

    //     // sell at ith day
    //     if (hold == true) {
    //         int j = i;

    //         while (j < n && ds.back() > prices[j])
    //             j++;

    //         if (j < n) {
    //             hold = false;
    //             int val = ds.back();
    //             ds.pop_back();

    //             sell = (prices[j] - val) + solve(j + 1, prices, ds, hold);

    //             hold = true;
    //             ds.push_back(val);
    //             sell_skip = solve(i + 1, prices, ds, hold);
    //         }
    //     }

    //     return  max({buy, buy_skip, sell, sell_skip});
    // }

    // RECURSIVE + MEMOIZATION

    int dp[30001][2];
    int solve(int i, vector<int>& prices, int hold) {
        if (i == n)
            return 0;

        if(dp[i][hold]!=-1)
        return dp[i][hold];
        
        // buy or skip
        if (hold == false) {
            return dp[i][hold] = max(-prices[i] + solve(i + 1, prices, 1),
                                     solve(i + 1, prices, 0));
        }

        // sell at ith day
        // if (hold == true) {
            return dp[i][hold] = max(prices[i] + solve(i + 1, prices, 0),
                                     solve(i + 1, prices, 1));
        // }
        // return dp[i][hold]
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();

        int profit = 0;

        // bool hold = false;
        // vector<int> ds;

        memset(dp, -1, sizeof(dp));

        return solve(0, prices, 0);
    }
};