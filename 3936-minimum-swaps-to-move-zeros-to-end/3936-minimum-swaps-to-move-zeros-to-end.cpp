class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n = nums.size();

        int min_swaps = 0;

        int i = 0, j = n - 1;

        int count_0 = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                count_0++;
        }

        if (count_0 == 0)
            return 0;

        while (i < j && j < n) {
            if (nums[j] == 0) {
                j--;
            } else {
                while (i < n && i < j && nums[i] != 0)
                    i++;

                if (nums[i] == 0)
                    min_swaps++;

                i++;
                j--;
            }
        }

        return min_swaps;
    }
};