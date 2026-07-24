class Solution {
public:
    void dfs (int i, vector<bool>& visited, vector<vector<int>>& isConnected) {
        visited[i] = true;
        for (int node = 0; node < isConnected.size(); node++) {
            if (isConnected[i][node] == 1 && visited[node] == 0) {
                dfs(node, visited, isConnected);
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, visited, isConnected);
                res++;
            }
        }
        return res;
    }
};