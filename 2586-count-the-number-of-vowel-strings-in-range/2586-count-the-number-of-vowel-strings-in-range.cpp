class Solution {
public:
    bool is_vowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    int vowelStrings(vector<string>& words, int left, int right) {
        int ans = 0;
        int n = words.size();

        while (left <= right) {
            int len=words[left].size();
            if (is_vowel(words[left][0]) && is_vowel(words[left][len-1]))
                ans++;

            left++;
        }
        return ans;
    }
};