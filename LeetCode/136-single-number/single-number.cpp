class Solution {
public:
    // for bit mainpulation traverse the whole array  using ^
    int singleNumber(vector<int>& nums) {
        int sum = 0;
        for (auto val : nums) {
            sum ^= val;
        }
        return sum;
    }
};