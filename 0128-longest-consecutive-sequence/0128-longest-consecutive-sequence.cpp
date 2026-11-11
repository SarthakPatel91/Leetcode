class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        int count = 0;

        for (int i = 0; i < n; i++) {
            int res = 1;
            while (i + 1 < n && nums[i] == nums[i + 1])
                i++;

            while (i + 1 < n && nums[i] + 1 == nums[i + 1]) {
                i++;
                res++;
                while (i + 1 < n && nums[i] == nums[i + 1])
                    i++;
            }

            count = max(count, res);
        }
        return count;
    }
};