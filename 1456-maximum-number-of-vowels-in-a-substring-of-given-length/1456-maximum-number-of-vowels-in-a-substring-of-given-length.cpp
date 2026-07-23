class Solution {
public:
bool isVowel(char ch){
    if (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
    return true;

    return false;
}
    int maxVowels(string s, int k) {
        int count = 0;
        int i = 0;
        int n = s.size();

        for (int i = 0; i < k; i++) {
            if (isVowel(s[i]))
                count++;
        }

        int maxcount = count;

        for (int i = k; i < s.size(); i++) {
            if (isVowel(s[i]))
                count++;
            if (isVowel(s[i - k]))
                count--;

            maxcount = max(maxcount, count);
        }

        return maxcount;
    }
};