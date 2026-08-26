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
        int count = 0;
        int i = 0;

        for (int j = 0; j < size; j++) {

            if (s[j] == '1')
                count++;

            while (count > k) {
                if (s[i] == '1')
                    count--;
                i++;
            }

            if (count == k) {

                while (s[i] == '0')
                    i++;

                int currLen = j - i + 1;

                if (currLen < len) {
                    len = currLen;
                    ans.clear();
                }

                if (currLen == len) {
                    ans.push_back(s.substr(i, currLen));
                }
            }
        }

        if (ans.empty())
            return "";

        string answer = ans[0];

        for (int i = 1; i < ans.size(); i++) {
            answer = smallest(answer, ans[i]);
        }

        return answer;
    }
};