class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        if (m > n)
            return {};

        vector<int> freqp(26, 0);
        vector<int> freq(26, 0);
        for (char ch : p) {
            freqp[ch - 'a']++;
        }

        vector<int> ans;

        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;

            if (i >= m)
                freq[s[i - m] - 'a']--;

            if (i >= m - 1 && freq == freqp)
                ans.push_back(i - m + 1);
        }

        return ans;
    }
};