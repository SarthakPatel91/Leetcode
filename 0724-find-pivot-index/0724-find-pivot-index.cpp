class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int leftsum = 0;
        int rightsum = 0;
        int totalsum = 0;

        int n = nums.size();
        for (int i = 0; i < n; i++) {
            totalsum = totalsum + nums[i];
        }

        for (int i = 0; i < n; i++) {
            rightsum = totalsum - leftsum - nums[i];
            if (leftsum == rightsum)
                return i;
            
            leftsum=leftsum+nums[i];
        }

        return -1;
    }
};