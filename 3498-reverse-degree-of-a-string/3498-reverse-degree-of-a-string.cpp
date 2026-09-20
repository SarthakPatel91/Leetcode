class Solution {
public:
    int reverseDegree(string s) {
        // vector<int> freq(26, 0);
        int size = s.size();

        int ans=0;

        for(int i=0;i<size;i++){
            int idx='z'-s[i];

            ans+=(i+1)*(idx+1);
        }

        return ans;
    }
};