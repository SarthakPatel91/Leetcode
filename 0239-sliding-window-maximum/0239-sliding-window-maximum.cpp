class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        // int mx = INT_MIN;
        vector<int> ans;
        deque<int> dq;

        for (int i = 0; i < n; i++) {
            // make space for next element
            while (!dq.empty() && dq.front() <= i - k)
                dq.pop_front();

            // remove unnecesary elemen
            while (!dq.empty() && nums[i] > nums[dq.back()])
                dq.pop_back();

            // push in dq
            dq.push_back(i);

            // valid window size
            if (i >= k - 1)
                ans.push_back(nums[dq.front()]);
        }

        return ans;
    }
};