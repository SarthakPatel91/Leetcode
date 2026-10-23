class Solution {
    public int maximumWealth(int[][] accounts) {
        int m=accounts.length;

        int max=Integer.MIN_VALUE;
        for(int i=0;i<m;i++){
            int[] list=accounts[i];
            int sum=Arrays.stream(list).sum();
            max=Math.max(max,sum);
        }
        return max;
    }
}