class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());

        int minidx = -1, maxidx = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] == mn)
                minidx = i;

            if (nums[i] == mx)
                maxidx = i;
        }

        int a = min(minidx, maxidx);
        int b = max(minidx, maxidx);

        int left = b + 1;
        int right = n - a;
        int both = (a + 1) + (n - b);

        return min({left, right, both});
    }
};