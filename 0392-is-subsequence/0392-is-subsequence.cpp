class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() > t.size())
            return false;

            auto it=t.begin();

        for (int i = 0; i < s.size(); i++) {
            it=find(it,t.end(),s[i]);

            if(it==t.end())
            return false;

            ++it;
        }

        return true;
    }
};