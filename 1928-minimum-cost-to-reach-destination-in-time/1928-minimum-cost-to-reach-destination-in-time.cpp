class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges,
                vector<int>& passingFees) {
        int m = edges.size();
        int n = passingFees.size();

        // make graph--undirected
        vector<vector<pair<int, int>>> adj(n);
        for (int i = 0; i < m; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int time = edges[i][2];
            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        
        vector<vector<int>> dist(n, vector<int>(maxTime + 1, INT_MAX));
        dist[0][0]=passingFees[0];
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            minheap;

        minheap.push({passingFees[0], 0, 0}); // cost,time,node

        while (!minheap.empty()) {
            int cost1 = get<0>(minheap.top());
            int time1 = get<1>(minheap.top());
            int node = get<2>(minheap.top());

            if(node==n-1)
            return cost1;

            minheap.pop();
            for (auto& v : adj[node]) {
                int adjnode = v.first;
                int time2 = v.second;
                int cost2 = passingFees[adjnode];

                int newtime = time1 + time2;
                int newcost = cost1 + cost2;

                // time<=maxTime
                if (newtime <= maxTime && newcost < dist[adjnode][newtime]) {
                    dist[adjnode][newtime] = newcost;
                    minheap.push({newcost, newtime, adjnode});
                }
            }
        }
        return -1;
    }
};