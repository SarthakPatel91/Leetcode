class Solution {
public:
    bool canAliceWin(int n) {
        if (n < 10)
            return false;

        int alice = 10;
        int bob;

        vector<int> moves(10);

        for (int i = 0; i < 10; i++) {
            moves[i] = 10 - i;
        }

        int idx;

        for (int i = 0; i < 10; i++) {
            if (n < moves[i]) {
                idx = i;
                break;
            }
            n = n - moves[i];
        }

        if(idx%2==0)
        return false;

        return true;
    }
};