class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int eve = 0;
        int nev = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] < 0) {
                ans[nev] = nums[i];
                nev += 2;
            } else {
                ans[eve] = nums[i];
                eve += 2;
            }
        }
        return ans;
    }
};