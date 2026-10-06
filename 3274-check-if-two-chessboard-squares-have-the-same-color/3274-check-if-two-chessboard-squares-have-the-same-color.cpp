class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int x1 = coordinate1[0] - 'a' + 1;
        int y1 = coordinate1[1];
        int x2 = coordinate2[0] - 'a' + 1;
        int y2 = coordinate2[1];
        cout << y1 << " " << y2;

        int firstSum = (x1 + y1) % 2;
        int secondSum = (x2 + y2) % 2;

        return firstSum == secondSum;
    }
};