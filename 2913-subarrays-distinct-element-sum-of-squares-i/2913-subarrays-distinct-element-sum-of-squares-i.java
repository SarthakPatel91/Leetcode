class Solution {
    public void subarray(List<Integer> nums, ArrayList<ArrayList<Integer>> arr) {
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            ArrayList<Integer> temp = new ArrayList<>();
            for (int j = i; j < n; j++) {
                temp.add(nums.get(j));
                arr.add(new ArrayList<>(temp));
            }
        }
    }

    public int sumCounts(List<Integer> nums) {
        ArrayList<ArrayList<Integer>> arr = new ArrayList<>();
        subarray(nums, arr);

        int sum = 0;

        for (int i = 0; i < arr.size(); i++) {
            HashMap<Integer, Integer> mp = new HashMap<>();
            for (int j = 0; j < arr.get(i).size(); j++) {
                mp.put(arr.get(i).get(j), mp.getOrDefault(arr.get(i).get(j), 0) + 1);

            }
            int count = mp.size();
            sum = sum + count * count;

        }

        return sum;
    }
}