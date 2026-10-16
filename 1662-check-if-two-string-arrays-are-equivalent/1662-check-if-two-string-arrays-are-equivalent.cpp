class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string a = "", b = "";
        int n = word1.size();
        int m = word2.size();

        for (int i = 0; i < n; i++) {
            a += word1[i];
        }

        for (int i = 0; i < m; i++)
            b += word2[i];

        return a == b;
    }
};