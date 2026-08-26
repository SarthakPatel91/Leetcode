class Solution {
public:
    string smallest(string& a, string& b) {
        if (a > b)
            return b;

        return a;
    }
    string shortestBeautifulSubstring(string s, int k) {
        vector<string> ans;

        int size = s.size();

        int len = INT_MAX;
        string res = "";
        int count = 0;

        int i = 0;

        for (int j = 0; j < size; j++) {
            // expand
            res = res + s[j];

            if (s[j] == '1')
                count++;

            // shrink
            while (count > k) {
                if (s[i] == '1')
                    count--;

                i++;
            }

            // update
            if (count == k) {

                while (res[i] == '0')
                    i++;
                // for min length
                if (len >= j - i + 1) {
                    len = j - i + 1;
                    ans.push_back(s.substr(i, j - i + 1));
                }
            }
        }

        vector<string> temp;
        for (int i = 0; i < ans.size(); i++) {
            if (ans[i].size() == len)
                temp.push_back(ans[i]);
        }

        if (count < k)
            return "";

        sort(temp.begin(), temp.end());

        return temp[0];
    }
};