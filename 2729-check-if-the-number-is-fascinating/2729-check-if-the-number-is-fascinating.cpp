class Solution {
public:
    bool isFascinating(int n) {
        if (n % 10 == 0)
            return false;

        int n2 = 2 * n;
        int n3 = 3 * n;

        cout << n2 << " " << n3;
        string s = to_string(n) + to_string(n2) + to_string(n3);
        sort(s.begin(), s.end());

        // for(char )
        // long long num=stoll(s);

        vector<int> freq(10, 0);

        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - '0']++;
            if (freq[i] > 1 || s[i] == '0')
                return false;
        }

        for (int i = 1; i <= 9; i++) {
            if (freq[i] == 0)
                return false;
        }
        return true;
    }
};