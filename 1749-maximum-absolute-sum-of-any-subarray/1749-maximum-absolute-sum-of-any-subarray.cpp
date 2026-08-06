class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size();
        // using kadanes find maxsub sum
        int currsub = nums[0];
        int maxsub = nums[0];

        for (int i = 1; i < n; i++) {
            currsub = max(nums[i], currsub + nums[i]);
            maxsub = max(maxsub, currsub);
        }

        //using kadanes find minsub sum

        int minsub=nums[0];
        currsub=nums[0];

        for(int i=1;i<n;i++){
            currsub=min(nums[i],currsub+nums[i]);
            minsub=min(minsub,currsub);
        }

        return max(abs(maxsub),abs(minsub));
    }
};