class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.size();
        int n2 = s2.size();

        if (n1 > n2)
            return false;

        unordered_map<char, int> mp1,mp2;

        for (char ch : s1)
            mp1[ch]++;

        mp2=mp1;

        int j;

        for (int i = 0; i < n2; i++) {
            int count=0;
            j = i;
            while (j < n2 && mp1.count(s2[j]) > 0) {
                count++;
                mp1[s2[j]]--;
                if(mp1[s2[j]]==0)
                mp1.erase(s2[j]);
                j++;

                if (count == n1)
                    return true;
            }
            mp1=mp2;
        }

        return false;
    }
};