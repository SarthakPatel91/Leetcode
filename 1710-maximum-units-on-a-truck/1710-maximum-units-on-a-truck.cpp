class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        int n = boxTypes.size();

        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (boxTypes[i][1] < boxTypes[j][1])
                    swap(boxTypes[i], boxTypes[j]);
            }
        }

        int units = 0;

        for (int i = 0; i < n; i++) {
            if (truckSize > boxTypes[i][0]) {
                units = units + (boxTypes[i][0] * boxTypes[i][1]);
                truckSize -= boxTypes[i][0];
            } else {
                units += truckSize * boxTypes[i][1];
                break;
            }
            cout << units << " ";
        }

        return units;
    }
};