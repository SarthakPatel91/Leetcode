class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;

        int[] ans = new int[m];

        HashMap<Integer, Integer> mp = new HashMap<>();

        Stack<Integer> st = new Stack<>();

        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.peek() < nums2[i]) {
                mp.put(st.peek(), nums2[i]);
                st.pop();
            }

            st.push(nums2[i]);
        }

        for (int i = 0; i < m; i++) {
            if (mp.containsKey(nums1[i]))
                ans[i]=mp.get(nums1[i]);

            else
                ans[i]=-1;
        }

        return ans;
    }
}