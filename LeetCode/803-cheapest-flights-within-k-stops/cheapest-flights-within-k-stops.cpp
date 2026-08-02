class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst,
                          int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        queue < pair<int, pair<int, int>>> pq;
        pq.push({0, {src, 0}});
        while (!pq.empty()) {
            auto [s, n] = pq.front();
            int u = n.first;
            int cost = n.second;
            pq.pop();
            if (s > k) {
                continue;
            }
            for (auto& neigh : adj[u]) {
                int v = neigh.first;
                int price = neigh.second;
                if (cost + price < dist[v]) {
                    dist[v] = cost + price;
                    pq.push({s + 1, {v, dist[v]}});
                }
            }
        }
        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};