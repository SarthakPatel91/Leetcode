class Solution {

    public boolean check(String s) {
        String temp = s;

        String rev = new StringBuilder(s).reverse().toString();

        return rev.equals(temp);
    }

    public int countSubstrings(String s) {
        int n = s.length();
        int count = 0;

        for (int i = 0; i < n; i++) {
            String temp = "";

            for (int j = i; j < n; j++) {
                temp = temp + s.charAt(j);

                if (check(temp))
                    count++;
            }
        }

        return count;
    }
}