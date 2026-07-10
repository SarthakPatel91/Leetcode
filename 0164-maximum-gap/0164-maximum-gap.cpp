class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();

        if (n < 2)
            return 0;

        priority_queue<int> maxheap;

        for (int x : nums)
            maxheap.push(x);

        int prev = maxheap.top();
        maxheap.pop();

        int ans = 0;

        while (!maxheap.empty()) {
            int curr = maxheap.top();
            maxheap.pop();

            ans = max(ans, prev - curr);

            prev = curr;
        }

        return ans;
    }
};