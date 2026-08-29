class Solution {
public:
    typedef long long ll;
    bool canfinish(vector<int>& weights, int mid, int days) {
        int m = weights.size();

        int sum = 0;
        int d = 1;
        for (int i = 0; i < weights.size(); i++) {
            if (sum + weights[i] <= mid) {
                sum += weights[i];
            } else {
                sum = weights[i];
                d++;
            }
        }

        if (d <= days)
            return true;

        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        ll totalsum = 0;

        for (int i = 0; i < n; i++)
            totalsum += weights[i];

        int low = *max_element(weights.begin(), weights.end());
        int high = totalsum;
        int mid;

        while (low <= high) {
            mid = low + (high - low) / 2;

            if (canfinish(weights, mid, days)) { // finish in <=days
                high = mid - 1; // reduce the range && minimize the high

            } else
                low = mid + 1; // reduce the range && maximixe the low
        }

        return low;
    }
};