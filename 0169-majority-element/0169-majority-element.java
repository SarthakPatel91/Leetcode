class Solution {
    public int majorityElement(int[] nums) {
        HashMap<Integer, Integer> mp = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
        }

        for (Map.Entry<Integer, Integer> p : mp.entrySet()) {
            if (p.getValue() > nums.length / 2)
                return p.getKey();
        }

        return 0;
    }
}