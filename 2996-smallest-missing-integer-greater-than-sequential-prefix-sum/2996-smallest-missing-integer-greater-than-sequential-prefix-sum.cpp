class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = 0;
        int i = 0;
        int j = 1;
        int n = nums.size();
        while (i < n && j < n) {
            if (nums[j] == nums[i] + 1) {
                sum = sum + nums[i];
                i++;
                j++;
            }

            else
                break;
        }
        sum = sum + nums[i];

        sort(nums.begin(), nums.end());

        bool found = false;
        while (!found) {
            if (!binary_search(nums.begin(), nums.end(), sum))
                return sum;

            else
                sum = sum + 1;
        }

        return 0;
    }
};