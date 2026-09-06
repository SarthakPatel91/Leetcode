class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {

        for (int i = 0; i < arr.size(); i++) {
            int j = i + 1;
            int k = j + 1;

            if (j < arr.size() && k < arr.size() && arr[i] % 2 != 0 &&
                arr[j] % 2 != 0 && arr[k] % 2 != 0)
                return true;
        }

        return false;
    }
};