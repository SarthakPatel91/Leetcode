class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();

        int minsize = INT_MAX;

        int i = 0;
        long long sum = 0;

        for (int j = 0; j < n; j++) {
            sum = sum + nums[j];
            while (sum >= target) {
                minsize = min(minsize, (j - i + 1));
                sum = sum - nums[i];
                i++;
            }
        }

        if(minsize==INT_MAX)
        minsize=0;
        
        return minsize;
    }
};