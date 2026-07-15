class Solution {
public:
    bool hasPathSum(TreeNode* root, int target) {
        if (root == nullptr)
            return false;
        
        if (root->left == nullptr && root->right == nullptr) {
            return target==root->val;
        }
        return hasPathSum(root->left, target-root->val) ||
               hasPathSum(root->right, target-root->val);
    }
};