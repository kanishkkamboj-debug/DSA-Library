class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> mp;
        for (auto val : tasks) {
            mp[val]++;
        }
        int ans = 0;
        for (auto val : mp) {
            int second = val.second;
            if (second == 1)
                return -1;
            ans += (second + 2) / 3;
        }
        return ans;
    }
};