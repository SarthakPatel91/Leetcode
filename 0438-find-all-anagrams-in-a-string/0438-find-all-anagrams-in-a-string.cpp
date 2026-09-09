class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        if (m > n)
            return {};

        map<char, int> mp1;
        for (char ch : p)
            mp1[ch]++;

        vector<int> ans;

        for (int i = 0; i <= s.size() - m; i++) {
            map<char, int> mp2;
            for (int j = i; j < i + m && j < n; j++) {
                mp2[s[j]]++;
            }
            if (mp1 == mp2)
                ans.push_back(i);
        }

        return ans;
    }
};