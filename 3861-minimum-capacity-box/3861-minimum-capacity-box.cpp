class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int n = capacity.size();

        int minidx = INT_MAX;
        int cap = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (capacity[i] >= itemSize && cap > (capacity[i] - itemSize)) {
                cap = capacity[i] - itemSize;
                if (cap == 0)
                    return i;
                minidx = i;
            }
        }

        if (minidx == INT_MAX)
            return -1;

        return minidx;
    }
};