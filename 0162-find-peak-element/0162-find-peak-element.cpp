#include <algorithm>
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;

        int target = *max_element(nums.begin(), nums.end());
        auto it = find(nums.begin(),nums.end(), target);
        if (it != nums.end()) {
            return it-nums.begin();
        } else
            return 0;
    }
};