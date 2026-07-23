class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency,int k) {
        vector<pair<int, int>> ans;
        const int MOD = 1e9+7;
        for (int i = 0; i < speed.size(); i++) {
            ans.push_back({efficiency[i], speed[i]});
        }
        sort(ans.rbegin(), ans.rend());
        priority_queue<int, vector<int>, greater<int>> res;
        long long sum = 0;
        long long con = INT_MIN;
        for (auto val : ans) {
            sum += val.second;
            res.push(val.second);
            if (res.size() > k) {
                sum -= res.top();
                res.pop();
            }
            con = max(con, sum * val.first);
        }
        return con % MOD;
    }
};