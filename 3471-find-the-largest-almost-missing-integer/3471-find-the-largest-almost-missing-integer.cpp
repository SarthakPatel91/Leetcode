class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> mp;

        for (int i = 0; i + k <= nums.size(); i++) {

            unordered_set<int> temp;

            for (int j = i; j < i + k; j++) {
                temp.insert(nums[j]);
            }

            for (int num : temp) {
                mp[num]++;
            }
        }

        int ans = -1;

        for (auto& p : mp) {
            if (p.second == 1) {
                ans = max(ans, p.first);
            }
        }

        return ans;
    }
};