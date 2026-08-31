
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public int[] nodesBetweenCriticalPoints(ListNode head) {
        ListNode temp = head;

        int size = 0;
        ArrayList<Integer> nums = new ArrayList<>();

        while (temp != null) {
            size++;
            nums.add(temp.val);
            temp = temp.next;
        }

        if (size == 2)
            return new int[]{-1, -1};

        int n = nums.size();
        ArrayList<Integer> res = new ArrayList<>();

        for (int i = 1; i < n - 1; i++) {

            // local maxima
            if ((nums.get(i - 1) < nums.get(i)) &&
                (nums.get(i) > nums.get(i + 1))) {
                res.add(i);
            }

            // local minima
            if ((nums.get(i - 1) > nums.get(i)) &&
                (nums.get(i) < nums.get(i + 1))) {
                res.add(i);
            }
        }

        int m = res.size();

        if (m < 2)
            return new int[]{-1, -1};

        int maxdis = res.get(m - 1) - res.get(0);
        int mindis = Integer.MAX_VALUE;

        for (int i = 0; i < m - 1; i++) {
            mindis = Math.min(mindis, res.get(i + 1) - res.get(i));
        }

        return new int[]{mindis, maxdis};
    }
}

