class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;
        int k = n;
        while (k > 0) {
            int rem = k % 10;
            sum = sum + rem;
            product *= rem;
            k = k / 10;
        }

        sum = sum + product;

        if (n % sum == 0)
            return true;

        return false;
    }
};