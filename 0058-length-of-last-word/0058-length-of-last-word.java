class Solution {
    public int lengthOfLastWord(String s) {
        s = s.trim();
        String[] arr = s.split("\\s+");
        int size = arr.length;
        String ans = arr[size - 1];
        return ans.length();
    }
}