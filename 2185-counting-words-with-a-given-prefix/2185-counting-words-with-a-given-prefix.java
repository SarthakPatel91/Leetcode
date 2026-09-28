class Solution {
    public int prefixCount(String[] words, String pref) {
        int count = 0;

        int n = pref.length();

        for (int i = 0; i < words.length; i++) {
            if (n > words[i].length())
                continue;

             if (words[i].substring(0,n).equals(pref))
                count++;
        }

        return count;
    }
}