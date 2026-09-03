class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        vector<int> res;

        int n = nums.size();

        for (int x : nums)
            mp[x]++;

        for (auto& p : mp) {
            if (mp.count(p.first) == 1)
                res.push_back(p.first);
        }

        sort(res.begin(), res.end(), greater<int>());

        if (res.size() <= k)
            return res;

        vector<int> ans;

        for (int i = 0; i < k; i++) {
            ans.push_back(res[i]);
        }

        return ans;
    }
};