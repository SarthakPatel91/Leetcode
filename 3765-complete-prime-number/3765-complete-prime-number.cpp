class Solution {
public:
    bool check(string temp) {
        int number = stoi(temp);

        if (number < 2)
            return false;

        for (int i = 2; i * i <= number; i++) {
            if (number % i == 0)
                return false;
        }

        return true;
    }
    bool completePrime(int num) {
        if (num < 2)
            return false;

        string s = to_string(num);

        int n = s.size();

        for (int i = 1; i <= n; i++) {
            string prefix = (s.substr(0, i));
            string suffix = (s.substr(n - i, i));

            if (!check(prefix) || !check(suffix)) {
                return false;
            }
        }
        return true;
    }
};