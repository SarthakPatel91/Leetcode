class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int firstmax = INT_MIN;
        int secondmax = INT_MIN;

        for (int i = 0; i < nums.size(); i++) {
            if(nums[i]>firstmax){
                secondmax=firstmax;
                firstmax=nums[i];
            }
            else if(nums[i]>secondmax)
            secondmax=nums[i];
        }

        return (firstmax-1)*(secondmax-1);
    }
};