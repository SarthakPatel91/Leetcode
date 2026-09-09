class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int m = p.size();
        if (m > n)
            return {};

        vector<int> freqp(26, 0);
        for (char ch : p) {
            freqp[ch - 'a']++;
        }

        vector<int> ans;

        for (int i = 0; i <= s.size() - m; i++) {
            string temp = s.substr(i, m);
            vector<int> freqtemp(26, 0);
            for (char ch : temp)
                freqtemp[ch - 'a']++;

            if (freqp == freqtemp)
                ans.push_back(i);
        }

        return ans;
    }
};