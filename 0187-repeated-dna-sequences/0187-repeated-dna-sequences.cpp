class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        unordered_map<string, int> mp;

        for (int i = 0; i < n; i++) {
            string temp = s.substr(i, 10);
            mp[temp]++;
        }

        vector<string> ans;
        for (auto& p : mp) {
            if (p.second > 1)
                ans.push_back(p.first);
        }

        return ans;
    }
};