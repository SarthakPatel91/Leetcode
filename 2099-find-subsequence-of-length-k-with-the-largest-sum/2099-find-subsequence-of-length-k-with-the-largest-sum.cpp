class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>t=nums;
        sort(nums.begin(), nums.end());
        vector<int> temp;

        for (int i = n - 1; i >= n - k; i--) {
            temp.push_back(nums[i]);
        }

        vector<int> ans;

        vector<bool> b(k, false);

        for (int i = 0; i < n; i++) {
            int target = t[i];
            for (int j = 0; j < k; j++) {
                if (target == temp[j] && b[j] == false) {
                    b[j] = true;
                    ans.push_back(target);
                    break;
                }
            }
        }

        return ans;
    }
};