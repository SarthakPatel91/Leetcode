class Solution {
    public double findMaxAverage(int[] nums, int k) {
        double ans=Integer.MIN_VALUE;
        int size=nums.length;

        int sum=0;
        for(int i=0;i<k;i++){
            sum=sum+nums[i];
        }

        double avg=(double) sum/k;
        ans=Math.max(ans,avg);
        int l=0;

        for(int i=k;i<size;i++){
            sum=sum+nums[i]-nums[l];
            l++;
            double new_avg=(double) sum/k;
         
            ans=Math.max(ans,new_avg);
        }

        return ans;
    }
}