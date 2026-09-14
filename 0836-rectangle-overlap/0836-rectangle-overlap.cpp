class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int left1_x = rec1[0];
        int left1_y = rec1[1];
        int right1_x = rec1[2];
        int right1_y = rec1[3];

        int left2_x = rec2[0];
        int left2_y = rec2[1];
        int right2_x = rec2[2];
        int right2_y = rec2[3];

        if (left2_x >= right1_x ||   // rec2 is right of rec1
            right2_x <= left1_x ||   // rec2 is left of rec1
            left2_y >= right1_y ||   // rec2 is above rec1
            right2_y <= left1_y)     // rec2 is below rec1
            return false;

        return true;
    }
};