class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int n = temperatures.length;

        Stack<int[]> st = new Stack<>();

        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.peek()[0] < temperatures[i]) {
                int idx = st.peek()[1];
                ans[idx] = i - idx;
                st.pop();
            }
            st.push(new int[] { temperatures[i], i });
        }

        return ans;
    }
}