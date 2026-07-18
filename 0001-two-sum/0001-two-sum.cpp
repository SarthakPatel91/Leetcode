
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;

        int n = nums.size();
       

        for (int i = 0; i < n - 1; i++) {
            int num = target - nums[i];
            for (int j = i + 1; j < n; j++) {
                if (num == nums[j])
                    return {i, j};
            }
        }
        return {};
    }
};