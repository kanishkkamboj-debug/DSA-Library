class Solution {
public:
    TreeNode* create(vector<int>& nums, int low, int high) {
        if (low > high) {
            return nullptr;
        }
        int mid = low + (high - low) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = create(nums, low, mid - 1);
        node->right = create(nums, mid + 1, high);
        return node;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return create(nums, 0, nums.size() - 1);
    }
};