class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.size();

        for (int i = 0; i < n; i += 2 * k) {

            // If fewer than k characters remain
            if (i + k > n)
                reverse(s.begin() + i, s.end());

            // If at least k characters remain
            else
                reverse(s.begin() + i, s.begin() + i + k);
        }

        return s;
    }
};