class Solution {
public:
    int kthFactor(int n, int k) {
        vector<int> prime;

        if (n == 1) {
            if (k == 1)
                return 1;

            return -1;
        }

        prime.push_back(1);

        for (int i = 2; i <= n; i++) {
            if (n % i == 0) {
                prime.push_back(i);
            }
        }

        // int ans;
        if (k > prime.size())
            return -1;

        return prime[k - 1];
    }
};