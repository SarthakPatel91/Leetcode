class Solution {
public:
    typedef long long ll;
    bool judgeSquareSum(int c) {
        int root = sqrt(c);
        vector<int> nums;
        for (int i = 0; i <= root; i++) {
            nums.push_back(i);
        }

        int left = 0;
        int right = root;

        while (left <= right) {
            ll num1 = pow(nums[left], 2);
            ll num2 = pow(nums[right], 2);

            if ((num1 + num2) < c)
                left++;

            else if ((num1 + num2) > c)
                right--;

            else
                return true;
        }

        return false;
    }
};