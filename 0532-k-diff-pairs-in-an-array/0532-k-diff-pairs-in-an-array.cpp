class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int n = nums.size();
        map<pair<int, int>, int> mp;

        if (n <= 1)
            return 0;

        int i = 0;
        int j = 1;

        int count = 0;

        while (j < n) {

            if (i == j) {
                j++;
                continue;
            }

            int diff = nums[j] - nums[i];

            if (diff < k) {
                j++;
            } 
            else if (diff > k) {
                i++;
            } 
            else {

                if (mp.find({nums[i], nums[j]}) == mp.end()) {
                    count++;
                    mp[{nums[i], nums[j]}] = 1;
                }

                i++;
                j++;
            }
        }

        return count;
    }
};