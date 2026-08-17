//just compare and dudum
struct cmp {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        return a.first < b.first;
    }
};
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ans(n);
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
        for (int i = 0; i < n; i++) {
            pq.push({score[i], i});
        }
        int i = 0;
        while (!pq.empty()) {
            auto [first, second] = pq.top();
            pq.pop();
            i++;
            if (i == 1)
                ans[second] = "Gold Medal";
            else if (i == 2)
                ans[second] = "Silver Medal";
            else if (i == 3)
                ans[second] = "Bronze Medal";
            else
                ans[second] = to_string(i);
        }
        return ans;
    }
};