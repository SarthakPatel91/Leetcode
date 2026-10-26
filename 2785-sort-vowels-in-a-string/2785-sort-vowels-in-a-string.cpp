class Solution {
public:
    bool is_vowel(char ch) {
        ch=tolower(ch);
        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
    }
    string sortVowels(string s) {
        int n = s.size();

        int count = 0;
        string a = "";
        for (int i = 0; i < n; i++) {
            if (is_vowel(s[i])) {
                a+=s[i];
                count++;
            }
        }

        if (count == 0)
            return s;

        int j=0;
        sort(a.begin(),a.end());

        for(int i=0;i<n;i++){
            if(is_vowel(s[i])){
                s[i]=a[j++];
            }
        }
        return s;
    }
};