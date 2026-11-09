class Solution {
public:
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int n = nums.size();

        int idx = n;

        for (int i = 0; i < n; i++) {
            if (nums[i] != target[i]) {
                idx = i;
                break;
            }
        }

        for (int i = idx + 1; i < n; i++) {
            if (target[i] > target[i - 1])
                return 0;
        }

        int ans = idx < n;

        for (int i = idx - 1; i >= 0; i--) {
            if (i + 1 < n && target[i] < target[i + 1])
                break;

            ans++;
        }

        sort(nums.begin(), nums.end());
        sort(target.begin(), target.end());

        if (nums != target)
            return 0;

        return ans;
    }
};