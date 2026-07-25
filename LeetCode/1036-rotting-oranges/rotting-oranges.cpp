class Solution {
public:
    // for to make traversal easy make array of each dieaction in each dimension
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};
    // function check if all the pointer are in array or not
    bool valid(int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m) {
            return false;
        }
        return true;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        int time = 0;
        queue<pair<int, int>> res;
        // loop to count all the fresh oreanges available side by side finding
        // rooten oranges
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    res.push({i, j});
                    grid[i][j] = 0;
                } else if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }
        // doing a bfs traversal to check parallely
        while (!res.empty() && fresh > 0) {
            time++;
            int s = res.size();
            while (s--) {
                auto [r, c] = res.front();
                res.pop();
                for (int k = 0; k < 4; k++) {
                    int row = r + x[k];
                    int col = c + y[k];
                    if (valid(row, col, n, m) && grid[row][col] == 1) {
                        res.push({row, col});
                        grid[row][col] = 0;
                        fresh--;
                    }
                }
            }
        }
        if (fresh > 0) {
            return -1;
        }
        return time;
    }
};