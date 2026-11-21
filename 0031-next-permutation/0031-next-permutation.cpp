#include <algorithm>
#include<vector>
class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        // vector<int> arr = nums;
        // sort(arr.begin(), arr.end(), greater<int>());
        // if (nums == arr) {
        //     reverse(nums.begin(), nums.end());
        //     return;
        // }
        next_permutation(nums.begin(), nums.end());
    }
};