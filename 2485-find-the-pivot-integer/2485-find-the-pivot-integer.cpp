class Solution {
public:
    int pivotInteger(int n) {
        if (n == 1)
            return 1;
        int totalsum = 0;

        vector<int> nums(n + 1, 0);
        for (int i = 0; i < n + 1; i++) {
            nums[i] = i;
            totalsum += i;
        }

        int leftsum = 0;
        int rightsum = 0;

        for (int i = 1; i < n + 1; i++) {
            rightsum = totalsum - leftsum;

            leftsum += nums[i];

            if (leftsum == rightsum)
                return i;
        }

        return -1;
    }
};