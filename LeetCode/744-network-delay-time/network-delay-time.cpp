class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int src) {
        vector<vector<pair<int, int>>> ans(n + 1);
        for (const auto& val : times) {
            int s = val[0];
            int d = val[1];
            int w = val[2];
            ans[s].push_back({d, w});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> res;
        vector<int> dist(n + 1, INT_MAX);
        dist[src] = 0;
        res.push({0, src});
        while (!res.empty()) {
            auto [f, node] = res.top();
            res.pop();
            if (f > dist[node]) {
                continue;
            }
            for (int j = 0; j < ans[node].size(); j++) {
                int neigh = ans[node][j].first;
                int wt = ans[node][j].second;
                if (f + wt < dist[neigh]) {
                    dist[neigh] = wt + f;
                    res.push({f + wt, neigh});
                }
            }
        }
        int con = 0;
        for (int i=1;i<=n;i++) {
            if (dist[i] == INT_MAX) {
                return -1;
            }
            con = max(con, dist[i]);
        }
        return con;
    }
};