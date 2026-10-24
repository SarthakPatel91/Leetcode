class Solution {
    public String largestOddNumber(String num) {
        int n=num.length();

        int j=n-1;
        while(j>=0){
            Character c=num.charAt(j);
            int a=c-'0';
            if(a%2!=0){
                return num.substring(0,j+1);
            }
            j--;
        }
        return "";
    }
}