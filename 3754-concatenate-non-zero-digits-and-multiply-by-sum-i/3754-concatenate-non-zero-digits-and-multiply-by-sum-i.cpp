class Solution {
public:
    long long sumAndMultiply(int n) {
        if (n == 1)
            return 1;

        long long sum = 0;

        long long x = 0;
        int place = 1;
        while (n > 0) {

            if (n % 10 != 0) {
                sum = sum + (n % 10);
                x = x + (n % 10) * place;
                place = place * 10;
            }

            n = n / 10;
        }

        return x * sum;
    }
};