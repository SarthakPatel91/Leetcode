class Solution {
public:
    int reverseBits(int n) {
        vector<int> bits(32);
        int i = 31;
        while (n > 0) {
            int rem = n % 2;
            bits[i] = rem;
            n = n / 2;
            i--;
        }

        reverse(bits.begin(), bits.end());

        int ans = 0;
        int p = 31;

        for (int i = 0; i < 32; i++) {
            ans = ans + pow(2, p) * bits[i];
            p--;
        }
        return ans;
        
    }
};