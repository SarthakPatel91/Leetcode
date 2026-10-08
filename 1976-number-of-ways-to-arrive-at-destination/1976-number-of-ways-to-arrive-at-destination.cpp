class Solution {
public:
    const int mod = 1e9 + 7;
    typedef long long ll;
    int countPaths(int n, vector<vector<int>>& roads) {
        int m = roads.size();
        // make the graph

        vector<vector<pair<int, int>>> adj(n);

        for (int i = 0; i < m; i++) {
            int u = roads[i][0];
            int v = roads[i][1];
            int time = roads[i][2];

            adj[u].push_back({v, time});
            adj[v].push_back({u, time});
        }

        // find the minimum time using dijsktra algo
        vector<ll> dist(n, LLONG_MAX);
        vector<ll> ways(n, 0);

        priority_queue<pair<ll, int>, vector<pair<ll, int>>,
                       greater<pair<ll, int>>>
            minheap;

        minheap.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;

        while (!minheap.empty()) {
            pair<ll, int> p = minheap.top();
            ll d = p.first;
            int node = p.second;
            minheap.pop();

            if (d > dist[node])
                continue;

            for (auto& vec : adj[node]) {
                int neighbour = vec.first;
                int wt = vec.second;
                ll newDist = d + wt;

                if (newDist < dist[neighbour]) {
                    dist[neighbour] = d + wt;
                    ways[neighbour] = ways[node];
                    minheap.push({d + wt, neighbour});
                } else if (newDist == dist[neighbour])
                    ways[neighbour] = (ways[node] + ways[neighbour]) % mod;
            }
        }

        return ways[n - 1];
    }
};