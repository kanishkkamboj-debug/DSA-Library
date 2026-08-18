class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for (auto val : nums) {
            mp[val]++;
        }
        if (k == 1) {
            int ans = -1;
            for (auto val : nums) {
                if (mp[val] == 1) {
                    ans = max(ans, val);
                }
            }
            return ans;
        }
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }
        int ans = -1;
        if (mp[nums[0]] == 1)
            ans = max(ans, nums[0]);
        if (mp[nums[n - 1]] == 1)
            ans = max(ans, nums[n - 1]);
        return ans;
    }
};