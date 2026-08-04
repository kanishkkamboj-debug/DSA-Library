class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int maxi = INT_MIN;
        int mini = INT_MAX;
        // JUST create an array mark which element is present itreate over it
        // and push :)
        vector<int> ans;
        vector<bool> present(101, false);
        sort(nums.begin(), nums.end());
        for (auto val : nums) {
            present[val] = true;
            maxi = max(maxi, val);
            mini = min(mini, val);
        }

        for (int i = mini; i < maxi; i++) {
            if (!present[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};