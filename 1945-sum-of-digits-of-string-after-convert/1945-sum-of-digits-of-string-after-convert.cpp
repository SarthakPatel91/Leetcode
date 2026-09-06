class Solution {
public:
    int summation(string ans) {
        int sum = 0;

        for (int i = 0; i < ans.size(); i++) {
            int num = ans[i] - '0';
            sum = sum + num;
        }

        return sum;
    }
    int getLucky(string s, int k) {
        int n = s.size();
        string ans = "";

        for (int i = 0; i < n; i++) {
            int num = (int)(s[i]) - 'a' + 1;
            ans = ans + to_string(num);
        }
        cout << ans << " ";
        int res = 0;
        for (int i = 0; i < k; i++) {
            res = summation(ans);
            cout << res << " ";
            ans = to_string(res);
        }

        return res;
    }
};