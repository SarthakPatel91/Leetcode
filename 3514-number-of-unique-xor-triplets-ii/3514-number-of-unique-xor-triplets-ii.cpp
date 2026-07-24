class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_map<int, int> pairxor;
        unordered_map<int, int> ans;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < nums.size(); j++) {
                pairxor[nums[i] ^ nums[j]]++;
            }
        }

        for (auto& p : pairxor) {
            for (int i = 0; i < nums.size(); i++) {
                ans[p.first ^ nums[i]]++;
            }
        }

        return ans.size();
    }
};