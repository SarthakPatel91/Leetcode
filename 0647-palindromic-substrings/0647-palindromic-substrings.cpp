class Solution {
public:
    bool check(string s) {
        string temp = s;
        reverse(temp.begin(), temp.end());

        if (temp == s)
            return true;

        return false;
    }
    int countSubstrings(string s) {
        int n = s.size();

        int count = 0;

        for (int i = 0; i < n; i++) {
            string temp = "";
            for (int j = i; j < n; j++) {
                temp = temp + s[j];
                // cout << temp << " ";
                if (check(temp))
                    count++;
            }
        }

        return count;
    }
};