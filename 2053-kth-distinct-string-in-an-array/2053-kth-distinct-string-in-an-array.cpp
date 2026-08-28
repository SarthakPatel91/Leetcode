class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int n = arr.size();
        unordered_map<string, int> mp;
        int count = 0;

        for (int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }

        for (int i = 0; i < n; i++) {
            string s = arr[i];
            for (auto& p : mp) {
                if (p.first == s) {
                    if (p.second == 1)
                        count++;
                    if (count == k)
                        return p.first;
                }
            }
        }

        return "";
    }
};