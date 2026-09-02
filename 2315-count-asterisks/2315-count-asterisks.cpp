class Solution {
public:
    int countAsterisks(string s) {
        int count = 0;
        int res = 0;

        bool pair = false;

        for (int i = 0; i < s.size(); i++) {
            if (!pair && s[i] == '*')
                res++;

            if (s[i] == '|')
                pair = !pair;
        }

        return res;
    }
};