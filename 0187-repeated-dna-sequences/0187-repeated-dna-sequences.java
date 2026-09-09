class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        int n = s.length();

        HashMap<String, Integer> mp = new HashMap<>();

        for (int i = 0; i <= n - 10; i++) {
            String temp = s.substring(i, i + 10);
            mp.put(temp, mp.getOrDefault(temp, 0) + 1);
        }

        ArrayList<String> ans = new ArrayList<>();

        for (Map.Entry<String, Integer> p : mp.entrySet()) {
            if (p.getValue() > 1) {
                ans.add(p.getKey());
            }
        }

        return ans;
    }
}