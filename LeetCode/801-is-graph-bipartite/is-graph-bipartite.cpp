class Solution {
public:
    bool res = true;
    void dfs(vector<vector<int>>& graph, int node, int c, vector<int>& colors) {
        colors[node] = c;
        for (int i = 0; i < graph[node].size(); i++) {
            int niegh = graph[node][i];
            if (colors[niegh] != -1 && colors[niegh] == c) {
                res = false;
                return;
            }
            if (colors[niegh] == -1) {
                dfs(graph, niegh, 1-c, colors);
            }
        }
        return;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> colors(n, -1);
        for (int i = 0; i < n; i++) {
            if (colors[i] == -1) {
                dfs(graph, i, 0, colors);
            }
        }
        return res;
    }
};