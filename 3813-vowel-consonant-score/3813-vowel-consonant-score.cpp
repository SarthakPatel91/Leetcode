class Solution {
public:
    int vowelConsonantScore(string s) {
        int v = 0;
        int c = 0;
        for (int i = 0; i < s.size(); i++) {
            if (isalpha(s[i])) {
                if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
                    s[i] == 'u')
                    v++;
                else
                    c++;
            }
        }

        if (c == 0)
            return 0;

        int score = v / c;

        return score;
    }
};