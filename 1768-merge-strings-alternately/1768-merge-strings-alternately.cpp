class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();

        int i = 0;
        int j = 0;

        string ans;

        while (i < m && j < n) {
            ans = ans + word1[i] + word2[j];
            i++;
            j++;
        }

        while (i != m)
            ans = ans + word1[i++];

        while (j != n)
            ans = ans + word2[j++];

            return ans;
    }
};