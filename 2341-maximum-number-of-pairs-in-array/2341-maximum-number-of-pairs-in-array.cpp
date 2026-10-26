class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int n = nums.size();
        vector<bool> vis(n, false);

        int pairs = 0;
        int left = n;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (j != i && !vis[i] && !vis[j] && nums[i] == nums[j]) {
                    vis[i] = true;
                    vis[j] = true;
                    left -= 2;
                    pairs++;
                }
            }
        }
        return {pairs, left};
    }
};