class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {

        vector<int> indegree(n + 1, 0);
        vector<int> outdegree(n + 1, 0);

        // unordered_map<int, vector<int>> adj;
        for (int i = 0; i < trust.size(); i++) {
            int u = trust[i][0];
            int v = trust[i][1];

            indegree[v]++;
            outdegree[u]++;

            // adj[u].push_back(v);
        }

        for(int i=1;i<indegree.size();i++){
            if(indegree[i]==n-1 && outdegree[i]==0)
            return i;

        }

        return -1;
    }
};