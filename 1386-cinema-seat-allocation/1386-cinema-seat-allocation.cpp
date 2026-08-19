class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, unordered_set<int>> mp;

        for (auto& reservedSeat : reservedSeats) {
            int row = reservedSeat[0];
            int col = reservedSeat[1];

            mp[row].insert(col);
        }

        int res = (n - mp.size()) * 2;

        for (auto& [row, bookedseat] : mp) {

            auto isavailable = [&](int seat) {
                return bookedseat.find(seat) == bookedseat.end();
            };

            bool groupA = isavailable(2) && isavailable(3) &&
                          isavailable(4) && isavailable(5);

            bool groupB = isavailable(4) && isavailable(5) &&
                          isavailable(6) && isavailable(7);

            bool groupC = isavailable(6) && isavailable(7) &&
                          isavailable(8) && isavailable(9);

            if (groupA && groupC)
                res += 2;
            else if (groupA || groupB || groupC)
                res += 1;
        }

        return res;
    }
};