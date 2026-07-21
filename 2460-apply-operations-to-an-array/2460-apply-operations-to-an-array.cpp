class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();

        for (int k = 0; k < n - 1; k++) {
            for (int i = 0; i < n - 1; i++) {
                if (nums[i] == nums[i + 1]) {
                    nums[i] = nums[i] * 2;
                    nums[i + 1] = 0;
                }
            }
        }

        int slow = 0;

        for (int fast = 0; fast < nums.size(); fast++) {

            if (nums[fast] != 0) {
                swap(nums[slow], nums[fast]);
                slow++;
            }
        }

        return nums;
    }
};