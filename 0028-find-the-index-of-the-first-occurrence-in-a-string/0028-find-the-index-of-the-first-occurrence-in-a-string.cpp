class Solution {
public:
    int strStr(string haystack, string needle) {

        // if (!haystack.contain(needle))
        //     return -1;

        int m = haystack.size();
        int n = needle.size();

        if (n > m)
            return -1;

        int count = 0;

        int i = 0;
        int j = 0;

        int firstidx;
        vector<int> nums;

        while (i < m && j < n) {
            if (haystack[i] != needle[j]) {
                if (count > 0)
                    i = nums[0] + 1;
                else
                    i++;

                j = 0;
                count = 0;
                nums.clear();

            }

            else {
                nums.push_back(i);
                i++;
                j++;
                count++;
                if (count == n)
                    return nums[0];
            }
        }

        return -1;
    }
};