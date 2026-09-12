class Solution {
public:
    bool is_prime(int n) {
        if (n < 2)
            return false;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }

        return true;
    }
    int countPrimeSetBits(int left, int right) {
        // if (right <= 2)
        //     return 0;

        int count = 0;

        for (int i = left; i <= right; i++) {
            int setbits = __builtin_popcount(i);
            cout << setbits << " ";
            if (is_prime(setbits)==true)
                count++;
        }

        return count;
    }
};