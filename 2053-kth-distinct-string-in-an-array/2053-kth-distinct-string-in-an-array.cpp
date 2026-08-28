class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;

        // Count frequency
        for (string& s : arr) {
            mp[s]++;
        }

        // Find kth distinct string in original order
        for (string& s : arr) {
            if (mp[s] == 1) {
                k--;

                if (k == 0)
                    return s;
            }
        }

        return "";
    }
};