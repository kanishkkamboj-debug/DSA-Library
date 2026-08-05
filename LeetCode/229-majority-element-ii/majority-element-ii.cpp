class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // traverse store all freq of the elements then
        unordered_map<int, int> freq;
        for (auto val : nums) {
            freq[val]++;
        }
        vector<int> ans;
        int n = nums.size();
        // check each elemnet through map so that their is no diuplicate entry
        // and if condition agrees push it in
        for (auto val : freq) {
            if (val.second > n / 3) {
                ans.push_back(val.first);
            }
        }
        return ans;
    }
};