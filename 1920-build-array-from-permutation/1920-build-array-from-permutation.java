class Solution {
    public int[] buildArray(int[] nums) {
        int n=nums.length;

        int[] ans=new int[n];

        for(int i=0;i<n;i++){
            int idx=nums[i];
            ans[i]=nums[idx];
        }

        return ans;
    }
}