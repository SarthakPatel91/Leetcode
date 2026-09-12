class Solution {
public:
    int check(int n) {
        if (n == 2 || n == 4)
            return n;

        int sum = 0;
        int temp = n;

        for (int i = 2; i * i <= temp; i++) {
            while (temp % i == 0) {
                sum += i;
                temp /= i;
            }
        }

        if (temp > 1)
            sum += temp;

        if(sum==n)
        return n;
        
        return check(sum);
    }

    int smallestValue(int n) {
        return check(n);
    }
};