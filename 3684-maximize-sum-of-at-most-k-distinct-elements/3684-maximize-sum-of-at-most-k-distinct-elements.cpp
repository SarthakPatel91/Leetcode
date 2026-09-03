class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        set<int, greater<int>> st(nums.begin(), nums.end());

        vector<int> res;

        for (int x : st) {
            if (res.size() == k)
                break;
            res.push_back(x);
        }

        return res;
    }
};