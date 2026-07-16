class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        int maxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            maxi = max(maxi, nums[i]);
            prefix[i] = __gcd(nums[i], maxi);
        }

        sort(prefix.begin(), prefix.end());
        long long sum = 0;

        for (int i = 0; i < n / 2; i++) {
            sum += __gcd(prefix[i], prefix[n - i - 1]);
        }

        return sum;
    }
};