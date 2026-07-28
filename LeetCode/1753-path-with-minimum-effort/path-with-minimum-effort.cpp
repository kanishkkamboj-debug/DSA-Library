class Solution {
public:
    bool valid(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    int minimumEffortPath(vector<vector<int>>& h) {
        int n = h.size();
        int m = h[0].size();
        vector<vector<int>> res(n, vector<int>(m, INT_MAX));
        priority_queue < pair<int,pair<int, int>>,
            vector< pair<int,pair<int, int>>>, greater< pair<int,pair<int, int>>>> pq;
        int x[4] = {0, 0, -1, 1};
        int y[4] = {-1, 1, 0, 0};
        res[0][0] = 0;
        pq.push({0, {0, 0}});
        while (!pq.empty()) {
            auto p = pq.top();
            int dist=p.first;
            int row=p.second.first;
            int col=p.second.second;
            pq.pop();
            if (dist > res[row][col]) {
                continue;
            }
            for (int k = 0; k < 4; k++) {
                int r = row + x[k];
                int c = col + y[k];
                if (!valid(r, c, n, m)) {
                    continue;
                }
                int abss = abs(h[row][col] - h[r][c]);
                int newwt = max(abss, dist);
                if (newwt < res[r][c]) {
                    res[r][c] = newwt;
                    pq.push({newwt, {r, c}});
                }
            }
        }
        return res[n - 1][m - 1];
    }
};