class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int count = 0;
        for (auto val : nums) if (val < k) count++;
        return count;
    }
};