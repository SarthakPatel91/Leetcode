class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int sum = 0;
        vector<int> res;

        for (int i = 0; i < n; i++) {
            sum = 0;
            for (int j = i; j < n; j++) {
                sum = sum + arr[j];

                if ((j - i) % 2 == 0)
                    res.push_back(sum);
            }
            
        }
        int ans = 0;

        for (int i = 0; i < res.size(); i++) {
            ans += res[i];
        }

        return ans;
    }
};