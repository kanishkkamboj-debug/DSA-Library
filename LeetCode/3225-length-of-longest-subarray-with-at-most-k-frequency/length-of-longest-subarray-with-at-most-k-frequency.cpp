class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int maxi = 0;
        unordered_map<int, int> count;
        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            count[nums[right] - 'a']++;
            while (count[nums[right] - 'a'] > k) {
                count[nums[left] - 'a']--;
                left++;
            }
            maxi = max(maxi, right - left + 1);
        }
        return maxi;
    }
};