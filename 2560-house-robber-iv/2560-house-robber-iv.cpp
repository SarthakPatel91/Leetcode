class Solution {
public:
    bool solve(vector<int>& nums, int k, int cap) {
        int count = 0;

        for (int i = 0; i < nums.size();) {
            if (nums[i] <= cap) {
                count++;
                i += 2;
            } else {
                i++;
            }

            if (count >= k)
                return true;
        }

        return false;
    }

    int minCapability(vector<int>& nums, int k) {
        int low = *min_element(nums.begin(), nums.end());
        int high = *max_element(nums.begin(), nums.end());

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (solve(nums, k, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};