class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if (n * m != original.size())
            return {};
        vector<vector<int>> ans(m,vector<int>(n));
        int i = 0, j = 0, k = 0;
        while (k<original.size()) {
            ans[i][j] = original[k++];
            if (j == n-1) {
                j = 0;
                i++;
            } else {
                j++;
            }
        }
        return ans;
    }
};