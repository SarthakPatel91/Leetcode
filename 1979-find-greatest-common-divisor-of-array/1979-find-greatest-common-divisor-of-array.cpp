class Solution {
public:
    int gcd(int max, int min) {
        if (min == 0)
            return max;

        return gcd(min, max % min);
    }
    int findGCD(vector<int>& nums) {
        int max = *max_element(nums.begin(), nums.end());
        int min = *min_element(nums.begin(), nums.end());

        return gcd(max, min);
    }
};