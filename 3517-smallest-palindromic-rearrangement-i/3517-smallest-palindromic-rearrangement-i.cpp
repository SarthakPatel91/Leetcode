class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        if (n == 1)
            return s;

        string ans = "";
        string temp = "";
        vector<int> freq(26, 0);
        int mid = n / 2;

        for (int i = 0; i < mid; i++) {
            freq[s[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                int k = freq[i];
                while (k > 0) {
                    char c = 'a' + i;
                    temp.push_back(c);
                    k--;
                }
            }
        }
        ans = temp;
        if (n % 2 != 0) {
            ans = ans + s[mid];
        }

        reverse(temp.begin(), temp.end());
        ans = ans + temp;

        return ans;
    }
};