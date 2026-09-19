class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        multiset<int> small, large; // small: lower half (max at rbegin), large: upper half (min at begin)
        vector<double> res;
        res.reserve(nums.size() - k + 1);

        auto rebalance = [&]() {
            if (small.size() > large.size() + 1) {
                large.insert(*small.rbegin());
                small.erase(prev(small.end()));
            } else if (small.size() < large.size()) {
                small.insert(*large.begin());
                large.erase(large.begin());
            }
        };

        for (int i = 0; i < (int)nums.size(); i++) {
            if (small.empty() || nums[i] <= *small.rbegin())
                small.insert(nums[i]);
            else
                large.insert(nums[i]);
            rebalance();

            if (i >= k - 1) {
                if (k % 2 == 1)
                    res.push_back((double)*small.rbegin());
                else
                    res.push_back(((double)*small.rbegin() + (double)*large.begin()) / 2.0);

                int out = nums[i - k + 1];
                if (out <= *small.rbegin())
                    small.erase(small.find(out));
                else
                    large.erase(large.find(out));
                rebalance();
            }
        }
        return res;
    }
};