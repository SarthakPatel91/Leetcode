class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {

        int winsum = 0;
        for (int i = 0; i < k; i++) {
            winsum = winsum + nums[i];
        }

        int maxsum = winsum;
        for (int i = k; i < nums.size(); i++) {
            winsum = winsum + nums[i] - nums[i - k];
            maxsum = max(maxsum, winsum);
        }

        return (double)maxsum / k;
    }
};