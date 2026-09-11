class Solution {
public:
    bool check(int num, unordered_map<int, int> temp) {
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
    int totalNumbers(vector<int>& digits) {
        unordered_map<int, int> mp;

        for (int x : digits)
            mp[x]++;

        int count = 0;

        for (int i = 100; i <= 998; i = i + 2) {
            if (check(i, mp))
                count++;
        }

        return count;
    }
};