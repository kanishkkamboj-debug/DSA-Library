class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {  
        //this code doesn't have that -a problem because it is int not string
        unordered_map<int, int> count;
        int maxi = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); right++) {
            count[nums[right] ]++;
            while (count[nums[right]] > k) {
                count[nums[left] ]--;
                left++;
            }
            maxi = max(maxi, right - left + 1);
        }
        return maxi;
    }
};