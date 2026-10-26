class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int n = word.size();
        int ans = 0;

        for (int j = 1; j < n; j++) {
            unordered_map<char, int> mp;
            mp[word[j - 1]]++;          // count the starting char
            int count = 1;

            while (j < n && word[j - 1] <= word[j]) {
                count++;
                mp[word[j]]++;
                if (mp.size() == 5)
                    ans = max(ans, count);
                j++;
            }
        }
        return ans;
    }
};