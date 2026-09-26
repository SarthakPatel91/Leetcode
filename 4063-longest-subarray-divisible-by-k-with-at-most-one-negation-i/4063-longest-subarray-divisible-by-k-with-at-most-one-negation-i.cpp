class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int size = nums.size();

        vector<long long> prefix(size+1, 1);

        for (int i = 0; i < size; i++) {
            prefix[i+1] = prefix[i] + nums[i];
        }

        vector<int> first(k, -1);
        vector<int> last(k, -1);

        auto mod = [&](long long x) { return (int)(((x % k) + k) % k); };

        first[mod(prefix[0])] = 0;
        int ans = 0;

        for (int r = 1; r <= size; r++) {
            int j = r - 1;

            if (first[mod(prefix[j])] == -1)
                first[mod(prefix[j])] = j;

            last[mod(2LL * nums[j])] = j;

            int cr = mod(prefix[r]);

            if (first[cr] != -1)
                ans = max(ans, r - first[cr]);

            for (int v = 0; v < k; v++) {
                if (last[v] == -1)
                    continue;

                int c = mod(cr - v);

                if (first[c] != -1 && first[c] <= last[v])
                    ans = max(ans, r - first[c]);
            }
        }

        return ans;
    }
};