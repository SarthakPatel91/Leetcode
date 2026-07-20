class Solution {
public:
    int strStr(string haystack, string needle) {

        // if (!haystack.contain(needle))
        //     return -1;

        int m = haystack.size();
        int n = needle.size();

        if (n > m)
            return -1;

        for (int i = 0; i < m; i++) {
            if (haystack[i] == needle[0]) {
                if (haystack.substr(i, n) == needle)
                    return i;
            }
        }

        return -1;
    }
};