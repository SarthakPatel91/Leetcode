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

        // int i = 0;
        // int j = n - 1;

        // while (i < j) {
        //     if (nums[i] == 0 && nums[j] != 0)
        //         swap(nums[i], nums[j]);

        //     else if (nums[i] != 0 || nums[j] == 0) {
        //         i++, j--;
        //     }
        // }

        // return nums;
        int j = 0;

        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            if (nums[i] != 0) {
                ans[j] = nums[i];
                j++;
            }
        }
       

        return ans;
    }
};