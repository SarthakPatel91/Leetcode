class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        int m = flights.size();

        if (src == dst)
            return 0;

        // make graph
        vector<vector<pair<int, int>>> adj(n + 1);
        for (int i = 0; i < m; i++) {
            int u = flights[i][0];
            int v = flights[i][1];
            int price = flights[i][2];

            adj[u].push_back({v, price});
        }

        // dist[node][stops]
        vector<vector<int>> dist(n, vector<int>(k + 2, INT_MAX));
        dist[src][0] = 0;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            minheap;
        minheap.push({0, 0, src}); // price,stops,node

        while (!minheap.empty()) {
            int price = get<0>(minheap.top());
            int stops = get<1>(minheap.top());
            int node = get<2>(minheap.top());

            minheap.pop();

            if (node == dst)
                return price;

            if (stops == k + 1)
                continue;

            for (auto& v : adj[node]) {
                int next_node = v.first;
                int next_price = v.second;

                int newprice = price + next_price;
                int newstops = stops + 1;
                if (newprice < dist[next_node][newstops]) {
                    dist[next_node][newstops] = newprice;

                    minheap.push({newprice, newstops, next_node});
                }
            }
            
        }
        return -1;
    }
};