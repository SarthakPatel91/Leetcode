class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int sum = 0;

        int n = nums.size();

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> mp;
            for (int j = i; j < n; j++) {
                mp[nums[j]]++;
                int n = mp.size();
                sum += n * n;
            }
        }
        return sum;
    }
};