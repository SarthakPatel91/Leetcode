class Solution {
public:
    bool checkRecord(string s) {
        int n = s.size();
        int L = 1;
        int A = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'A')
                A++;

            if (s[i] == 'L' && s[i + 1] == 'L') {
                L++;
                if (L == 3)
                    return false;
            }
            else
            L=1;
        }
        if (A < 2)
            return true;

        return false;
    }
};