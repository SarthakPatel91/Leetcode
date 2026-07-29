#include <climits>

class Solution {
public:
    typedef long long ll;

    int smallestBalancedIndex(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return -1;

        ll rightpro = 1;
       ll totalsum = 0;

        for (int x : nums)
            totalsum += x;

        ll leftsum = totalsum;

        for (int i = n - 1; i >= 0; i--) {
            leftsum -= nums[i];

            if (leftsum == rightpro)
                return i;

            
            if (rightpro > LLONG_MAX / nums[i]) {
                rightpro = LLONG_MAX;   // Saturate the value
            } else {
                rightpro *= nums[i];
            }
        }

        return -1;
    }
};