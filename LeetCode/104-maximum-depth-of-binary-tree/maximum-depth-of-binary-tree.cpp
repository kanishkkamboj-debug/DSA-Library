class Solution {
public:
    int maxDepth(TreeNode* root) { return ans(root); }
    int ans(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        return 1 + max(ans(root->left), ans(root->right));
    }
};