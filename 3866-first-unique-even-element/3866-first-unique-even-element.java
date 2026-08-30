class Solution {
    public int firstUniqueEven(int[] nums) {
        HashMap<Integer, Integer> mp = new HashMap<>();

        for (int i = 0; i < nums.length; i++) {
            mp.put(nums[i], mp.getOrDefault(nums[i], 0) + 1);
        }

        int ans = -1;

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] % 2 == 0 && mp.get(nums[i])==1) {
                ans = nums[i];
                break;
            }
        }

        return ans;
    }
}