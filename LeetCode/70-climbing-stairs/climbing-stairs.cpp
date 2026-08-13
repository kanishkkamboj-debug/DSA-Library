class Solution {
public:
    int cal(int i, int n, unordered_map<int, int>& dp) {
        ;
        if (i == n)
            return 1;
        if (i > n)
            return 0;
        if (dp.find(i) != dp.end()) {
            return dp[i];
        }
        int first = cal(i + 1, n, dp);
        int second = cal(i + 2, n, dp);
        dp[i] = first + second;
        return first + second;
    }
    int climbStairs(int n) {
        unordered_map<int, int> dp;
        return cal(0, n, dp);
    }
};