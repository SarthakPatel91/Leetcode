class Solution {
public:
    typedef long long ll;
    ll solve(int m) {
        ll num = 0;

        while (m > 0) {
            int rem = m % 10;
            num += pow(rem, 2);
            m = m / 10;
        }

        return num;
    }
    bool isHappy(int n) {
        if (n == 1)
            return true;

        ll number = 0;
        unordered_map<ll, int> mp;

        while (true) {
            number = solve(n);

            if (number == 1)
                return true;

            if (mp.find(number) != mp.end())
                return false;

            mp[number]++;

            n = number;
        }

        return false;
    }
};