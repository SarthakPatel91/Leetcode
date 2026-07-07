class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        if (intervals.size() == 1)
            return 1;

        sort(intervals.begin(), intervals.end(),
             [](vector<int>& a, vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1];
                 return a[0] < b[0];
             });

        int i = 0;

        while (i < intervals.size() - 1) {

            int c = intervals[i][0];
            int d = intervals[i][1];

            int j = i + 1;

            while (j < intervals.size()) {

                // intervals[j] is covered by intervals[i]
                if (c <= intervals[j][0] && intervals[j][1] <= d) {
                    intervals.erase(intervals.begin() + j);
                    // Don't increment j
                } else {
                    j++;
                }
            }

            i++;
        }

        return intervals.size();
    }
};