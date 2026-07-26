class Solution {
public:
    // for to make traversal easy make array of each dieaction in each dimension
    int x[4] = {-1, 1, 0, 0};
    int y[4] = {0, 0, -1, 1};
    // function check if all the pointer are in array or not
    bool valid(int i, int j, int n, int m) {
        return i >= 0 && i < n && j >= 0 && j < m;
    }
    // this question is similar to rooten tomatoes like in that we used to
    // return the no of fresh fuit remaind in this just make it opposit e make
    // the cain of rottens to 'A' and convert the fresh furit into X then
    // convert A back into O
    void solve(vector<vector<char>>& board) {
        if (board.empty() || board[0].empty()) {
            return;
        }
        int n = board.size();
        int m = board[0].size();
        queue<pair<int, int>> res;
        // traverse the first row and last row only
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') {
                res.push({i, 0});
                board[i][0] = 'A';
            }
            if (board[i][m - 1] == 'O') {
                res.push({i, m - 1});
                board[i][m - 1] = 'A';
            }
        }
        // traverse last and first col only
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') {
                res.push({0, j});
                board[0][j] = 'A';
            }
            if (board[n - 1][j] == 'O') {
                res.push({n - 1, j});
                board[n - 1][j] = 'A';
            }
        }
        while (!res.empty()) {
            auto [r, c] = res.front();
            res.pop();
            for (int k = 0; k < 4; k++) {
                int row = r + x[k];
                int col = c + y[k];
                if (valid(row, col, n, m) && board[row][col] == 'O') {
                    res.push({row, col});
                    board[row][col] = 'A';
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};