class Solution {
public:
    vector<int> validSequence(string word1, string word2) {

        int m = word1.size();
        int n = word2.size();

        vector<int> last(n, -1);
        int j = n - 1;
        for (int i = m - 1; i >= 0 && j >= 0; i--) {
            if (word1[i] == word2[j]) {
                last[j] = i;
                j--;
            }
        }

        vector<int> ans(n);
        bool canchange = true;
        j = 0;
        for (int i = 0; i < m && j < n; i++) {
            if (word1[i] == word2[j]) {
                ans[j] = i;
                j++;
            } else if (canchange && (j == n - 1 || i < last[j + 1])) {
                ans[j] = i;
                j++;
                canchange = false;
            }
            if (j == n)
                return ans;
        }
        return {};
    }
};