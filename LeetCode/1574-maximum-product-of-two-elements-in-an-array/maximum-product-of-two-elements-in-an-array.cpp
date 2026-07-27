class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // simple fine the two max integer in one loop and return their -1 -1 val
        int max1 = 0;
        int max2 = 0;
        for (auto val : nums) {
            if (val > max1) {
                max2 = max1;
                max1 = val;
            } else if (val > max2) {
                max2 = val;
            }
        }
        return (max1 - 1) * (max2 - 1);
    }
};