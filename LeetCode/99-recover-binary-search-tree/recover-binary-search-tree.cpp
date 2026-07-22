class Solution {
public:
    vector<TreeNode*> nums;
    void arr(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        arr(root->left);
        nums.push_back(root);
        arr(root->right);
    }
    void recoverTree(TreeNode* root) {
        arr(root);
        int galat = 0;
        TreeNode* prev = nullptr;
        TreeNode* galat1f = nullptr;
        TreeNode* galat1s = nullptr;
        TreeNode* galat2f = nullptr;
        TreeNode* galat2s = nullptr;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i]->val > nums[i + 1]->val) {
                if (galat == 0) {
                    galat1f = nums[i];
                    galat1s = nums[i + 1];
                    galat++;
                } else {
                    galat2f = nums[i];
                    galat2s = nums[i + 1];
                    galat++;
                }
            }
        }
        if (galat == 1) {
            swap(galat1f->val, galat1s->val);
        } else if (galat == 2) {
            swap(galat1f->val, galat2s->val);
        }
    }
};