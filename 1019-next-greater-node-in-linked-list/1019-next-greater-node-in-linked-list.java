class Solution {
    public int[] nextLargerNodes(ListNode head) {

        ListNode curr = head;
        Stack<Integer> st = new Stack<>();

        int size = 0;
        ArrayList<Integer> ans = new ArrayList<>();

        while (curr != null) {
            ans.add(curr.val);
            curr = curr.next;
            size++;
        }

        for (int i = 0; i < size; i++) {

            while (!st.empty() && ans.get(st.peek()) < ans.get(i)) {
                ans.set(st.peek(), ans.get(i));
                st.pop();
            }

            st.push(i);
        }

        while (!st.empty()) {
            ans.set(st.peek(), 0);
            st.pop();
        }

        // Convert ArrayList<Integer> to int[]
        int[] result = new int[size];

        for (int i = 0; i < size; i++) {
            result[i] = ans.get(i);
        }

        return result;
    }
}