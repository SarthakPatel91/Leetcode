class Solution {
public:
    int countCommas(int n) {
        if (n < 1000)
            return 0;

        if (n >= 1000 && n < 10000)
            return n - 1000 + 1;

        if (n >= 10000 && n < 100000)
            return n - 1000 + 1;

        if (n == 100000)
            return n - 1000 + 1;

        return 0;
    }
};