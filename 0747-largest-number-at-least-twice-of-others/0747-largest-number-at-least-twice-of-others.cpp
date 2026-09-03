class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        vector<int> arr = nums;

        sort(arr.begin(), arr.end());

        int n = nums.size();

        if (arr[n - 1] < 2 * arr[n - 2])
            return -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] == arr[n - 1])
                return i;
        }

        return -1;
    }
};