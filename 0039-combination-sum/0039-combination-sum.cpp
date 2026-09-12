class Solution {
public:
    void findcom(int ind, vector<int>& arr, int target,
                 vector<vector<int>>& ans, vector<int> &ds) {
        if (ind == arr.size()) {
            if (target == 0) {
                ans.push_back(ds);
            }
            return;
    }
    if (arr[ind] <= target) {
        ds.push_back(arr[ind]);
        findcom(ind, arr, target - arr[ind], ans, ds);
        ds.pop_back();
    }
    findcom(ind + 1, arr, target, ans, ds);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int>ds;
        findcom(0, candidates, target, ans, ds);
        return ans;
    }
};
