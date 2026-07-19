class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int n = people.size();
        int i = 0;
        int j = n - 1;

        int sum ;

        int count = 0;
        int rest;

        while (i < j) {
            sum = people[i] + people[j];
            if (sum <= limit) {
                i++;
                j--;
            } else {
                j--;
            }
                count++;
        }

        if(i==j)
        count++;

        
        return count;
    }
};