class Solution {
    public int thirdMax(int[] nums) {
        int n = nums.length;

        HashMap<Integer, Integer> mp = new HashMap<>();

        for (int i = 0; i < n; i++) {
            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
        }

        ArrayList<Integer> list = new ArrayList<>();

        for (Map.Entry<Integer, Integer> p : mp.entrySet()) {
            list.add(p.getKey());
        }

        Collections.sort(list);

        if (list.size() < 3)
            return list.get(list.size() - 1);

        return list.get(list.size() - 3);
    }
}