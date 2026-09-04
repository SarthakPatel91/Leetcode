class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();

        int mx,mn;

        for(int i=0;i<n;i++){
            mx=*max_element(nums.begin(),nums.begin()+i);
            mn=*min_element(nums.begin()+i,nums.end());

            if(mx-mn<=k)
            return i;
        }

        return -1;
    }
};