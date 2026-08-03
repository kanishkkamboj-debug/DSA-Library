class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        bool exist = false;
        bool found = false;
        for (int i = 0; i < nums1.size(); i++) {
            for (int j = 0; j < nums2.size(); j++) {
                if (nums1[i] == nums2[j]) {
                    exist = true;
                }
                if (exist && nums1[i] < nums2[j]) {
                    ans.push_back(nums2[j]);
                    found = true;
                    break;
                }
            }
            if (!found) {
                ans.push_back(-1);
            }
            exist = false;
            found = false;
        }
        return ans;
    }
};