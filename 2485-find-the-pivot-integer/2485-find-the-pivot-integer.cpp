class Solution {
public:
    int pivotInteger(int n) {
        if (n == 1)
            return 1;
        int totalsum = n * (n + 1) / 2;
        int leftsum = 0;

        for (int i = 1; i < n; i++) {
            int rightsum = totalsum - leftsum;

            leftsum += i;

            if (rightsum == leftsum)
                return i;
        }

        return -1;
    }
};