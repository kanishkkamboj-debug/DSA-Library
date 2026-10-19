class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {

        // Reshaping is possible only if the total
        //  number of elements remains the same
        if (mat.size() * mat[0].size() != r * c)
            return mat;
        if (mat.size() == r && mat[0].size() == c)
            return mat;
        int n = mat[0].size();
        vector<vector<int>> ans(r, vector<int>(c));
        for (int i = 0; i < r * c; i++) {
            // Original matrix index:
            // i / n gives the original row
            // i % n gives the original column

            // New matrix index:
            // i / c gives the new row
            // i % c gives the new column
            ans[i / c][i % c] = mat[i / n][i % n];
        }
        return ans;
    }
};