class Solution {
public:
    void solve(vector<int>& nums, vector<int>& ds, vector<bool>& used,
               vector<vector<int>>& ans) {
        if (ds.size() == nums.size()) {
            ans.push_back(ds);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (used[i])
                continue;

            // take
            used[i] = true;
            ds.push_back(nums[i]);
            solve(nums, ds, used, ans);

            // not take
            used[i] = false;
            ds.pop_back();
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        vector<int> ds;
        vector<vector<int>> ans;

        vector<bool> used(n, false);

        solve(nums, ds, used, ans);


        //for removing duplicates
        vector<vector<int>> res;
        map<vector<int>, int> mp;

        for (int i = 0; i < ans.size(); i++) {
            mp[ans[i]]++;

            if (mp[ans[i]] == 1)
                res.push_back(ans[i]);
        }

        return res;
    }
};