class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for (auto a : s) {
            if (s.find(a - 1) == s.end()) {
                int current = a;
                int count = 1;
                while (s.find(current + 1) != s.end()) {
                    current++;
                    count++;
                }
                ans = max(ans, count);
            }
        }
        return ans;
    }
};