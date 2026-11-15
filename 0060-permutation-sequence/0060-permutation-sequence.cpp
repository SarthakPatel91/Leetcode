class Solution {
public:
    int count = 0;
    string res = "";
    bool solve(vector<bool>& used, string& ds, int k) {
        if (ds.size() == used.size() - 1) {
            count++;

            if (count == k) {
                res = ds;
                return true;
            }
            return false;
        }

        for (int i = 1; i < used.size(); i++) {
            if (used[i] == true)
                continue;

            used[i] = true;
            char c = char('0' + i);
            ds.push_back(c);

            solve(used, ds, k);

            ds.pop_back();
            used[i] = false;
        }
        return false;
    }

    string getPermutation(int n, int k) {
        vector<string> ans;
        vector<bool> used(n + 1, false);

        string ds = "";
        solve(used, ds, k);

        return res;
    }
};