class Solution {
public:

    bool palindrome(string temp) {
        string rev = temp;
        reverse(rev.begin(), rev.end());

        if (rev == temp)
            return true;

        return false;
    }
    void solve(string& s, int idx, string temp, vector<string>& ds,
               vector<vector<string>>& ans) {
        if (idx == s.size()) {
            if (temp.empty())
                ans.push_back(ds);
            return;
        }

        temp = temp + s[idx];

        if (palindrome(temp)) {
            ds.push_back(temp);
            solve(s, idx + 1, "", ds, ans);

            ds.pop_back();
        }

        solve(s, idx + 1, temp, ds, ans);
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;

        

        solve(s, 0, "", ds, ans);

        return ans;
    }
};