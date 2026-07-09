class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                      vector<vector<int>>& queries) {
        vector<bool> ans;

        for (int i = 0; i < queries.size(); i++) {
            int u = queries[i][0];
            int v = queries[i][1];
            if (u > v) {
                int temp = u;
                u = v;
                v = temp;
            }

            int num1 = nums[u];
            int num2 = nums[v];

            if (abs(num1 - num2) <= maxDiff)
                ans.push_back(true);
            else {
                bool check = false;
                for (int j = u; j < v; j++) {
                    num1 = nums[j];
                    num2 = nums[j + 1];
                    if (abs(num1 - num2) > maxDiff) {
                        check = false;
                        break;
                    } else
                        check = true;
                }
                ans.push_back(check);
            }
        }

        return ans;
    }
};