class NeighborSum {
public:
    int n;
    unordered_map<int, pair<int, int>> pos;
    vector<vector<int>> g;

    // note isme mujhe koi iteration aur value pass nahi karni yeh sab sirf
    // confusion ke liye kar rakha hai just store all value globally traverse
    // them and return !!!!!!!!!!!

    NeighborSum(vector<vector<int>>& grid) {
        g = grid;
        n = grid.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                pos[grid[i][j]] = {i, j};
            }
        }
    }

    int adjacentSum(int value) {
        auto [r, c] = pos[value];
        int ar[4] = {0, 0, -1, 1};
        int ac[4] = {-1, 1, 0, 0};
        int sum = 0;
        for (int i = 0; i < 4; i++) {
            int row = r + ar[i];
            int col = c + ac[i];
            if (row >= 0 && row < n && col >= 0 && col < n) {
                sum += g[row][col];
            }
        }
        return sum;
    }

    int diagonalSum(int value) {
        auto [r, c] = pos[value];
        int ar[4] = {-1, 1, -1, 1};
        int ac[4] = {-1, 1, 1, -1};
        int sum = 0;
        for (int i = 0; i < 4; i++) {
            int row = r + ar[i];
            int col = c + ac[i];
            if (row >= 0 && row < n && col >= 0 && col < n) {
                sum += g[row][col];
            }
        }
        return sum;
    }
};

/**
 * Your NeighborSum object will be instantiated and called as such:
 * NeighborSum* obj = new NeighborSum(grid);
 * int param_1 = obj->adjacentSum(value);
 * int param_2 = obj->diagonalSum(value);
 */