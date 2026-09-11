class Solution {
public:
    bool check(int num, unordered_map<int, int>& mp) {
        unordered_map<int, int> temp = mp;

        while (num > 0) {
            int digit = num % 10;
            if (temp.count(digit) == 0)
                return false;

            else {
                temp[digit]--;
                if (temp[digit] == 0)
                    temp.erase(digit);
            }
            num /= 10;
        }

        return true;
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_map<int, int> mp;

        for (int x : digits)
            mp[x]++;

        vector<int> ans;

        for (int i = 100; i <= 998; i = i + 2) {
            if (check(i, mp))
                ans.push_back(i);
        }

        return ans;
    }
};