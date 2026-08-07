class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        // if k is greater than n auto
        k %= n;
        // reverse the array
        reverse(nums.begin(), nums.end());
        // then reverse first k elements
        reverse(nums.begin(), nums.begin() + k);
        // then n-k elements
        reverse(nums.begin() + k, nums.end());
    }
};